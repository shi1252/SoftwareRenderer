#include "VertexShader.h"
#include "Pixel.h"
#include <vector>
#include "Vertex.h"
#include "..\Geometry\BaseGeometry.h"
#include "..\Camera\Camera.h"
#include "..\Math\Matrix4x4.h"
#include "..\Framework\Transform.h"
#include "..\Math\Vector.h"

extern Matrix4x4 worldMatrix;

int compareByY(const void* a, const void* b)
{
	int y1 = ((Vertex*)(a))->position.y;
	int y2 = ((Vertex*)(b))->position.y;

	if (y1 < y2)
		return -1;
	else if (y1 > y2)
		return 1;
	else
		return 0;
}

std::vector<Pixel> TriangleRasterization(std::vector<Vertex> tri)
{
	std::vector<Pixel> pixels;

	qsort(&tri[0], tri.size(), sizeof(tri[0]), compareByY);

	Vector4 dv0 = tri[2].position - tri[1].position;
	Vector4 dv1 = tri[2].position - tri[0].position;
	Vector4 dv2 = tri[0].position - tri[1].position;

	float m0 = dv0.y == 0 ? 0 : dv0.x / dv0.y;
	float m1 = dv1.y == 0 ? 0 : dv1.x / dv1.y;
	float m2 = dv2.y == 0 ? 0 : dv2.x / dv2.y;

	int y0 = tri[1].position.y - m0 * tri[1].position.x;
	int y1 = tri[0].position.y - m1 * tri[0].position.x;
	int y2 = tri[1].position.y - m2 * tri[1].position.x;

	if (tri[1].position.x < tri[0].position.x)
	{
		for (int y = tri[0].position.y - 0.5f; y <= tri[2].position.y + 0.5f; ++y)
		{
			if (y <= tri[1].position.y)
			{
				for (int x = tri[0].position.x + m2 * y - 0.5f; x <= tri[0].position.x + m1 * y + 0.5f; ++x)
				{
					Vector3 out;
					Vector3::BarycentricCoordinate(tri[0].position, tri[1].position, tri[2].position, Vector3(x, y), out);
					pixels.push_back(Pixel(x, y, Vertex::InterpColor(tri[0], tri[1], tri[2], out)));
				}
			}
			else
			{

			}
		}
	}
	else
	{

	}

	return pixels;
}

std::vector<Pixel> VertexShader::Rasterize(Camera* cam)
{
	std::vector<Pixel> pixels;

	Matrix4x4 vp = cam->GetProjectionMatrix() * cam->GetViewMatrix() * worldMatrix;
	for (int i = 0; i < vertices.size(); ++i)
	{
		vertices[i].position = cam->NDCtoScreen(vp * vertices[i].position);
	}

	for (int i = 0; i < indicies.size() - (indicies.size() % 3); i += 3)
	{
		//if (Vertex::BackfaceCulling(vertices[indicies[i]], vertices[indicies[i + 1]], vertices[indicies[i + 2]])) continue;

		std::vector<Vertex> tri;
		tri.push_back(vertices[indicies[i]]);
		tri.push_back(vertices[indicies[i + 1]]);
		tri.push_back(vertices[indicies[i + 2]]);

		std::vector<Pixel> pxs = TriangleRasterization(tri);
		for (int j = 0; j < pxs.size(); ++j)
			pixels.push_back(pxs[j]);
	}

	vertices.clear();
	indicies.clear();
	return pixels;
}

void VertexShader::push_back(BaseGeometry *geo)
{
	int vertexCount = vertices.size();
	for (int i = 0; i < geo->vertexCount; ++i)
	{
		vertices.push_back(geo->vertices[i]);
		vertices[vertexCount + i].position = geo->transform->Matrix() * vertices[vertexCount + i].position;
	}

	for (int i = 0; i < geo->indexCount; ++i)
		indicies.push_back(vertexCount + geo->indices[i]);
}
