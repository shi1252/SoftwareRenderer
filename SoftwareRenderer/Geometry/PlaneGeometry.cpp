#include "PlaneGeometry.h"
#include "..\Framework\Transform.h"
#include "..\Shader\Vertex.h"

PlaneGeometry::PlaneGeometry(float width, float height, DWORD color)
{
	transform = new Transform();

	vertices = new Vertex[4]
	{
		Vertex(-width, -height, 0, color),
		Vertex(-width, height, 0, color),
		Vertex(width, height, 0, color),
		Vertex(width, -height, 0, color)
	};
	vertexCount = 4;
	indices = new int[6]
	{
		0,1,2,
		0,2,3
	};
	indexCount = 6;
}
