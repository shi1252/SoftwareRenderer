#pragma once
#include "..\Math\Vector.h"

typedef unsigned long DWORD;
class Image;

class Vertex
{
public:
	Vector4 position;
	Vector2 uv;
	DWORD color;
	Image *texture;

	Vertex();
	Vertex(float x, float y, float z, DWORD color = 0);
	Vertex(Vector4 v, DWORD color);
	Vertex(float x, float y, float z, float uvx, float uvy);
	Vertex(Vector4 v, Vector2 uv);
	Vertex(Vector4 v, Vector2 uv, DWORD color);
	Vertex(Vector4 v, Vector2 uv, Image* texture);

	static DWORD InterpColor(Vertex v1, Vertex v2, Vertex v3, Vector3 p);
	static Vector2 InterpUV(Vertex v1, Vertex v2, Vertex v3, Vector4 p);
	static bool BackfaceCulling(Vertex &v1, Vertex &v2, Vertex &v3);
};