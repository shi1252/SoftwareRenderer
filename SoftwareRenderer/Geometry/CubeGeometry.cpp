#include "CubeGeometry.h"
#include "..\Framework\Transform.h"
#include "..\Math\Matrix4x4.h"
#include "..\Math\Vector.h"
#include "..\Shader\Vertex.h"

CubeGeometry::CubeGeometry(float width, float height, float depth, DWORD color)
{
	transform = new Transform();

	width = width * .5f;
	height = height * .5f;
	depth = depth * .5f;

	vertices = new Vertex[24]
	{
		Matrix4x4::TranslateMatrix(Vector3(0, 0, -depth)) * Vertex(-width, -height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, 0, -depth)) * Vertex(-width, height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, 0, -depth)) * Vertex(width, height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, 0, -depth)) * Vertex(width, -height, 0, color),

		Matrix4x4::TranslateMatrix(Vector3(0, 0, depth)) * Matrix4x4::YRotateMatrix(180) * Vertex(-width, -height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, 0, depth)) * Matrix4x4::YRotateMatrix(180) * Vertex(-width, height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, 0, depth)) * Matrix4x4::YRotateMatrix(180) * Vertex(width, height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, 0, depth)) * Matrix4x4::YRotateMatrix(180) * Vertex(width, -height, 0, color),

		Matrix4x4::TranslateMatrix(Vector3(-width, 0, 0)) * Matrix4x4::YRotateMatrix(90) * Vertex(-depth, -height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(-width, 0, 0)) * Matrix4x4::YRotateMatrix(90) * Vertex(-depth, height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(-width, 0, 0)) * Matrix4x4::YRotateMatrix(90) * Vertex(depth, height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(-width, 0, 0)) * Matrix4x4::YRotateMatrix(90) * Vertex(depth, -height, 0, color),

		Matrix4x4::TranslateMatrix(Vector3(width, 0, 0)) * Matrix4x4::YRotateMatrix(-90) * Vertex(-depth, -height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(width, 0, 0)) * Matrix4x4::YRotateMatrix(-90) * Vertex(-depth, height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(width, 0, 0)) * Matrix4x4::YRotateMatrix(-90) * Vertex(depth, height, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(width, 0, 0)) * Matrix4x4::YRotateMatrix(-90) * Vertex(depth, -height, 0, color),

		Matrix4x4::TranslateMatrix(Vector3(0, height, 0)) * Matrix4x4::XRotateMatrix(90) * Vertex(-width, -depth, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, height, 0)) * Matrix4x4::XRotateMatrix(90) * Vertex(-width, depth, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, height, 0)) * Matrix4x4::XRotateMatrix(90) * Vertex(width, depth, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, height, 0)) * Matrix4x4::XRotateMatrix(90) * Vertex(width, -depth, 0, color),

		Matrix4x4::TranslateMatrix(Vector3(0, -height, 0)) * Matrix4x4::XRotateMatrix(-90) * Vertex(-width, -depth, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, -height, 0)) * Matrix4x4::XRotateMatrix(-90) * Vertex(-width, depth, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, -height, 0)) * Matrix4x4::XRotateMatrix(-90) * Vertex(width, depth, 0, color),
		Matrix4x4::TranslateMatrix(Vector3(0, -height, 0)) * Matrix4x4::XRotateMatrix(-90) * Vertex(width, -depth, 0, color)
	};
	vertexCount = 24;
	indices = new int[36]
	{
		0,1,2,
		0,2,3,

		4,5,6,
		4,6,7,

		8,9,10,
		8,10,11,

		12,13,14,
		12,14,15,

		16,17,18,
		16,18,19,

		20,21,22,
		20,22,23
	};
	indexCount = 36;
}
