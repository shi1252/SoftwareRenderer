#include "Vertex.h"
#include "..\Math\Vector.h"
#include "..\Math\BaseMath.h"

Vertex::Vertex()
	: position(Vector4::zero), uv(Vector2::zero), color(0), texture(nullptr) {}

Vertex::Vertex(float x, float y, float z, DWORD color) 
	: position(Vector4(x, y, z)), uv(Vector2::zero), color(color), texture(nullptr) {}

Vertex::Vertex(Vector4 v, DWORD color) 
	: position(v), color(color), texture(nullptr) {}

Vertex::Vertex(float x, float y, float z, float uvx, float uvy)
	: position(Vector4(x, y, z)), uv(Vector2(uvx, uvy)), color(0), texture(nullptr) {}

Vertex::Vertex(Vector4 v, Vector2 uv)
	: position(v), uv(uv), color(0), texture(nullptr) {}

Vertex::Vertex(Vector4 v, Vector2 uv, DWORD color)
	: position(v), uv(uv), color(color), texture(nullptr) {}

Vertex::Vertex(Vector4 v, Vector2 uv, Image* texture)
	: position(v), uv(uv), color(0), texture(texture) {}


DWORD Vertex::InterpColor(Vertex v1, Vertex v2, Vertex v3, Vector3 p)
{
	Vector3 out = Vector3::zero;
	Vector3::BarycentricCoordinate(v1.position, v2.position, v3.position, p, out);

	BYTE r1 = (BYTE)255 & v1.color, r2 = (BYTE)255 & v2.color, r3 = (BYTE)255 & v3.color;
	WORD g1 = ((WORD)65280 & v1.color) >> 8, g2 = ((WORD)65280 & v2.color) >> 8, g3 = ((WORD)65280 & v3.color) >> 8;
	DWORD b1 = ((DWORD)16711680 & v1.color) >> 16, b2 = ((DWORD)16711680 & v2.color) >> 16, b3 = ((DWORD)16711680 & v3.color) >> 16;
	r1 *= out.x; g1 *= out.x; b1 *= out.x;
	r2 *= out.y; g2 *= out.y; b2 *= out.y;
	r3 *= out.z; g3 *= out.z; b3 *= out.z;

	return ((r1 | r2 | r3) | (g1 | g2 | g3) << 8 | (b1 | b2 | b3) << 16);
}

Vector2 Vertex::InterpUV(Vertex v1, Vertex v2, Vertex v3, Vector4 p)
{
	Vector3 out = Vector3::zero;
	Vector3::BarycentricCoordinate(v1.position, v2.position, v3.position, p, out);

	//float leng = out.x + out.y + out.z;
	//if (leng > 1.0f)
	//{
	//	return 0;
	//	Vector3::BarycentricCoordinate(v1.position, v2.position, v3.position, p, out);
	//	leng = leng;
	//}
	float z = 1.f / (out.x / v1.position.w + out.y / v2.position.w + out.z / v3.position.w);
	Vector2 t = z * (v1.uv * out.x / v1.position.w + v2.uv * out.y / v2.position.w + v3.uv * out.z / v3.position.w);
	//Vector2 ss = (v1.uv * out.x + v2.uv * out.y + v3.uv * out.z);
	return t;//(v1.uv * out.x + v2.uv * out.y + v3.uv * out.z);
}

bool Vertex::BackfaceCulling(Vertex &v1, Vertex &v2, Vertex &v3)
{
	Vector3 bc1 = v2.position - v1.position;
	Vector3 bc2 = v3.position - v1.position;
	if (bc1.Cross(bc2).Dot(Vector3::forward) > 0)
		return true;
}