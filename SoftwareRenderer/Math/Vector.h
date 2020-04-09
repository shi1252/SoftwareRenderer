#pragma once
#include <vector>
struct Vector2
{
	float x;
	float y;

	Vector2(float x = 0, float y = 0) : x(x), y(y) {}
	static const Vector2 zero;
	static const Vector2 one;
	static const Vector2 right;
	static const Vector2 left;
	static const Vector2 up;
	static const Vector2 down;

	Vector2& operator+=(const Vector2& v);
	Vector2& operator+=(const float v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator-=(const float v);
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator+(const float v) const;
	Vector2 operator-(const Vector2& v) const;
	Vector2 operator-(const float v) const;
	friend Vector2 operator*(float v, const Vector2&);
	Vector2 operator*(const float n) const;
	Vector2 operator*(const Vector2& v) const;
	Vector2 operator/(const float n) const;
	Vector2 operator/(const Vector2& v) const;
	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;
	float Dot(const Vector2& v) const;
	float Cross(const Vector2& v) const;
	float Length() const;
	float SqrMagnitude() const;
	Vector2 Normalize();
	float Cos(Vector2& v);
	float AngleRad(Vector2& v);
	float AngleDeg(Vector2& v);
	Vector2 Proj(Vector2& v);
	static Vector2& MinX(Vector2& v1, Vector2& v2);
	static Vector2& MinX(Vector2* v, int length);
	static int MinXIndex(Vector2* v, int length);
	static int MinXIndex(std::vector<Vector2> list);
	static Vector2& MinY(Vector2& v1, Vector2& v2);
	static Vector2& MinY(Vector2* v, int length);
	static int MinYIndex(Vector2* v, int length);
	static int MinYIndex(std::vector<Vector2> list);
	static Vector2 Lerp(Vector2& v1, Vector2& v2, float ratio);
	static float Distance(Vector2& v1, Vector2& v2);
};

struct Vector3
{
	float x;
	float y;
	float z;

	static const Vector3 zero;
	static const Vector3 one;
	static const Vector3 right;
	static const Vector3 left;
	static const Vector3 up;
	static const Vector3 down;
	static const Vector3 forward;
	static const Vector3 backward;

	Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
	Vector3(const Vector2& v)
	{
		x = v.x;
		y = v.y;
	}

	operator Vector2();
	Vector3& operator+=(const Vector3& v);
	Vector3& operator+=(const float v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator-=(const float v);
	Vector3 operator+(const Vector3& v) const;
	Vector3 operator+(const float v) const;
	Vector3 operator-() const;
	Vector3 operator-(const Vector3& v) const;
	Vector3 operator-(const float v) const;
	friend Vector3 operator*(float n, const Vector3& v);
	Vector3 operator*(const float n) const;
	Vector3 operator*(const Vector3& v) const;
	Vector3 operator/(const float n) const;
	Vector3 operator/(const Vector3& v) const;
	bool operator==(const Vector3& v) const;
	bool operator!=(const Vector3& v) const;
	float Dot(const Vector3& v) const;
	Vector3 Cross(const Vector3& v) const;
	float Length();
	float SqrMagnitude() const;
	Vector3 Normalize();
	float Cos(Vector3& v);
	float AngleRad(Vector3& v);
	float AngleDeg(Vector3& v);
	Vector3 Proj(Vector3& v);
	static Vector3& MinX(Vector3& v1, Vector3& v2);
	static Vector3& MinX(Vector3* v, int length);
	static int MinXIndex(Vector3* v, int length);
	static int MinXIndex(std::vector<Vector3> list);
	static int MinYIndex(Vector3* v, int length);
	static int MinYIndex(std::vector<Vector3> list);
	static Vector3 Lerp(Vector3& v1, Vector3& v2, float ratio);
	static float Distance(Vector3& v1, Vector3& v2);
	static Vector3 Clamp(Vector3 value, Vector3 min, Vector3 max);
	static Vector3 RotateClamp(Vector3 value);
	static void BarycentricCoordinate(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 p, Vector3& out);
};

struct Vector4
{
	float x;
	float y;
	float z;
	float w;

	static const Vector4 zero;
	static const Vector4 one;
	static const Vector4 right;
	static const Vector4 left;
	static const Vector4 up;
	static const Vector4 down;
	static const Vector4 forward;
	static const Vector4 backward;

	Vector4(float x = 0, float y = 0, float z = 0, float w = 1) : x(x), y(y), z(z), w(w) {}

	operator Vector2();
	operator Vector3();
	Vector4& operator+=(const Vector4& v);
	Vector4& operator+=(const float v);
	Vector4& operator-=(const Vector4& v);
	Vector4& operator-=(const float v);
	Vector4 operator+(const Vector4& v) const;
	Vector4 operator+(const float v) const;
	Vector4 operator-(const Vector4& v) const;
	Vector4 operator-(const float v) const;
	friend Vector4 operator*(float n, const Vector4& v);
	Vector4 operator*(const float n) const;
	Vector4 operator*(const Vector4& v) const;
	Vector4 operator/(const float n) const;
	Vector4 operator/(const Vector4& v) const;
	bool operator==(const Vector4& v) const;
	bool operator!=(const Vector4& v) const;
	float Dot3(const Vector4& v) const;
	Vector4 Cross3(const Vector4& v) const;
	float Length3();
	float SqrMagnitude3() const;
	Vector4 Normalize3();
	float Cos3(Vector4& v);
	float AngleRad3(Vector4& v);
	float AngleDeg3(Vector4& v);
	Vector4 Proj3(Vector4& v);
	static Vector4& MinX(Vector4& v1, Vector4& v2);
	static Vector4& MinX(Vector4* v, int length);
	static int MinXIndex(Vector4* v, int length);
	static int MinXIndex(std::vector<Vector4> list);
	static Vector4& MinY(Vector4& v1, Vector4& v2);
	static Vector4& MinY(Vector4* v, int length);
	static int MinYIndex(Vector4* v, int length);
	static int MinYIndex(std::vector<Vector4> list);
};