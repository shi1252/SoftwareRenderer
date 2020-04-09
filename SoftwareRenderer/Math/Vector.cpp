#include "Vector.h"
#include "BaseMath.h"

const Vector2 Vector2::zero(.0f, .0f);
const Vector2 Vector2::one(1.0f, 1.0f);
const Vector2 Vector2::right(1.0f, 0.0f);
const Vector2 Vector2::left(-1.0f, 0.0f);
const Vector2 Vector2::up(0.0f, 1.0f);
const Vector2 Vector2::down(0.0f, -1.0f);

const Vector3 Vector3::zero(.0f, .0f, .0f);
const Vector3 Vector3::one(1.0f, 1.0f, 1.0f);
const Vector3 Vector3::right(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::left(-1.0f, 0.0f, 0.0f);
const Vector3 Vector3::up(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::down(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::forward(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::backward(0.0f, 0.0f, -1.0f);

const Vector4 Vector4::zero(.0f, .0f, .0f);
const Vector4 Vector4::one(1.0f, 1.0f, 1.0f);
const Vector4 Vector4::right(1.0f, 0.0f, 0.0f);
const Vector4 Vector4::left(-1.0f, 0.0f, 0.0f);
const Vector4 Vector4::up(0.0f, 1.0f, 0.0f);
const Vector4 Vector4::down(0.0f, -1.0f, 0.0f);
const Vector4 Vector4::forward(0.0f, 0.0f, 1.0f);
const Vector4 Vector4::backward(0.0f, 0.0f, -1.0f);

Vector2 operator*(float n, const Vector2& v)
{
	return Vector2(n * v.x, n * v.y);
}

Vector3 operator*(float n, const Vector3& v)
{
	return Vector3(n * v.x, n * v.y, n * v.z);
}

Vector4 operator*(float n, const Vector4& v)
{
	return Vector4(n * v.x, n * v.y, n * v.z, n * v.w);
}

void Vector3::BarycentricCoordinate(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 p, Vector3& out)
{
	Vector3 u = v2 - v1;
	Vector3 v = v3 - v1;
	Vector3 w = p - v1;

	float denom = (u.Dot(u) * v.Dot(v)) - (u.Dot(v) * v.Dot(u));
	out.y = (w.Dot(u) * v.Dot(v) - w.Dot(v) * v.Dot(u)) / denom;
	out.z = (w.Dot(v) * u.Dot(u) - w.Dot(u) * u.Dot(v)) / denom;
	out.x = 1 - out.y - out.z;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	this->x += v.x;
	this->y += v.y;

	return *this;
}

Vector2& Vector2::operator+=(const float v)
{
	this->x += v;
	this->y += v;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	this->x -= v.x;
	this->y -= v.y;

	return *this;
}

Vector2& Vector2::operator-=(const float v)
{
	this->x -= v;
	this->y -= v;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2(*this) += v;
}

Vector2 Vector2::operator+(const float v) const
{
	return Vector2(*this) += v;
}

Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(*this) -= v;
}

Vector2 Vector2::operator-(const float v) const
{
	return Vector2(*this) -= v;
}

Vector2 Vector2::operator*(const float n) const
{
	return Vector2(n * x, n * y);
}

Vector2 Vector2::operator*(const Vector2& v) const
{
	return Vector2(x * v.x, y * v.y);
}

Vector2 Vector2::operator/(const float n) const
{
	return Vector2(x / n, y / n);
}

Vector2 Vector2::operator/(const Vector2& v) const
{
	return Vector2(x / v.x, y / v.y);
}

bool Vector2::operator==(const Vector2& v) const
{
	if (this->x == v.x && this->y == v.y)
		return true;
	return false;
}

bool Vector2::operator!=(const Vector2& v) const
{
	return !(this->operator==(v));
}

float Vector2::Dot(const Vector2& v) const
{
	return (this->x * v.x + this->y * v.y);
}

float Vector2::Cross(const Vector2& v) const
{
	return (this->x * v.y - this->y * v.x);
}

float Vector2::Length() const
{
	return sqrtf(x * x + y * y);
}

float Vector2::SqrMagnitude() const
{
	return (x * x + y * y);
}

Vector2 Vector2::Normalize()
{
	return Vector2(x / this->Length(), y / this->Length());
}

float Vector2::Cos(Vector2& v)
{
	return (Dot(v) / (Length() * v.Length()));
}

float Vector2::AngleRad(Vector2& v)
{
	return acosf(this->Dot(v) / (this->Length() * v.Length()));
}

float Vector2::AngleDeg(Vector2& v)
{
	return AngleRad(v) * 180.0f / PI;
}

Vector2 Vector2::Proj(Vector2& v)
{
	return (Length() * Cos(v) * v.Normalize());
}

Vector2& Vector2::MinX(Vector2& v1, Vector2& v2)
{
	if (v1.x > v2.x)
		return v2;
	return v1;
}

Vector2& Vector2::MinX(Vector2* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector2& min = v[0];
	for (int i = 1; i < length; i++)
	{
		if (min.x > v[i].x)
		{
			min = v[i];
		}
	}
	return min;
}

int Vector2::MinXIndex(Vector2* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector2& min = v[0];
	int index = 0;
	for (int i = 1; i < length; i++)
	{
		if (min.x > v[i].x)
		{
			min = v[i];
			index = i;
		}
	}
	return index;
}

int Vector2::MinXIndex(std::vector<Vector2> list)
{
	Vector2& min = list[0];
	int index = 0;
	for (int i = 1; i < list.size(); i++)
	{
		if (min.x > list[i].x)
		{
			min = list[i];
			index = i;
		}
	}
	return index;
}

Vector2& Vector2::MinY(Vector2& v1, Vector2& v2)
{
	if (v1.y > v2.y)
		return v2;
	return v1;
}

Vector2& Vector2::MinY(Vector2* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector2& min = v[0];
	for (int i = 1; i < length; i++)
	{
		if (min.y > v[i].y)
		{
			min = v[i];
		}
	}
	return min;
}

int Vector2::MinYIndex(Vector2* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector2& min = v[0];
	int index = 0;
	for (int i = 1; i < length; i++)
	{
		if (min.y > v[i].y)
		{
			min = v[i];
			index = i;
		}
	}
	return index;
}

int Vector2::MinYIndex(std::vector<Vector2> list)
{
	Vector2& min = list[0];
	int index = 0;
	for (int i = 1; i < list.size(); i++)
	{
		if (min.y > list[i].y)
		{
			min = list[i];
			index = i;
		}
	}
	return index;
}

Vector2 Vector2::Lerp(Vector2& v1, Vector2& v2, float ratio)
{
	return Vector2(BaseMath::Lerp(v1.x, v2.x, ratio), BaseMath::Lerp(v1.y, v2.y, ratio));
}

float Vector2::Distance(Vector2& v1, Vector2& v2)
{
	return sqrtf(powf(v2.x - v1.x, 2.0f) + powf(v2.y - v1.y, 2.0f));
}

Vector3::operator Vector2()
{
	return Vector2(x, y);
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;

	return *this;
}

Vector3& Vector3::operator+=(const float v)
{
	this->x += v;
	this->y += v;
	this->z += v;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;

	return *this;
}

Vector3& Vector3::operator-=(const float v)
{
	this->x -= v;
	this->y -= v;
	this->z -= v;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& v) const
{
	return Vector3(*this) += v;
}

Vector3 Vector3::operator+(const float v) const
{
	return Vector3(*this) += v;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator-(const Vector3& v) const
{
	return Vector3(*this) -= v;
}

Vector3 Vector3::operator-(const float v) const
{
	return Vector3(*this) -= v;
}

Vector3 Vector3::operator*(const float n) const
{
	return Vector3(n * x, n * y, n * z);
}

Vector3 Vector3::operator*(const Vector3& v) const
{
	return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::operator/(const float n) const
{
	return Vector3(x / n, y / n, z / n);
}

Vector3 Vector3::operator/(const Vector3& v) const
{
	return Vector3(x / v.x, y / v.y, z / v.z);
}

bool Vector3::operator==(const Vector3& v) const
{
	if (this->x == v.x && this->y == v.y && this->z == v.z)
		return true;
	return false;
}

bool Vector3::operator!=(const Vector3& v) const
{
	return !(this->operator==(v));
}

float Vector3::Dot(const Vector3& v) const
{
	return (this->x * v.x + this->y * v.y + this->z * v.z);
}

Vector3 Vector3::Cross(const Vector3& v) const
{
	return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

float Vector3::Length()
{
	return sqrtf(x * x + y * y + z * z);
}

float Vector3::SqrMagnitude() const
{
	return (x * x + y * y + z * z);
}

Vector3 Vector3::Normalize()
{
	float d = Length();
	return Vector3(x / d, y / d, z / d);
}

float Vector3::Cos(Vector3& v)
{
	return (Dot(v) / (Length() * v.Length()));
}

float Vector3::AngleRad(Vector3& v)
{
	return acosf(this->Dot(v) / this->Length() * v.Length());
}

float Vector3::AngleDeg(Vector3& v)
{
	return AngleRad(v) * 180.0f / PI;
}

Vector3 Vector3::Proj(Vector3& v)
{
	return (Length() * Cos(v) * v.Normalize());
}

Vector3& Vector3::MinX(Vector3& v1, Vector3& v2)
{
	if (v1.x > v2.x)
		return v2;
	return v1;
}

Vector3& Vector3::MinX(Vector3* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector3& min = v[0];
	for (int i = 1; i < length; i++)
	{
		if (min.x > v[i].x)
		{
			min = v[i];
		}
	}
	return min;
}

int Vector3::MinXIndex(Vector3* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector3& min = v[0];
	int index = 0;
	for (int i = 1; i < length; i++)
	{
		if (min.x > v[i].x)
		{
			min = v[i];
			index = i;
		}
	}
	return index;
}

int Vector3::MinXIndex(std::vector<Vector3> list)
{
	Vector3& min = list[0];
	int index = 0;
	for (int i = 1; i < list.size(); i++)
	{
		if (min.x > list[i].x)
		{
			min = list[i];
			index = i;
		}
	}
	return index;
}

int Vector3::MinYIndex(Vector3* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector3& min = v[0];
	int index = 0;
	for (int i = 1; i < length; i++)
	{
		if (min.y > v[i].y)
		{
			min = v[i];
			index = i;
		}
	}
	return index;
}

int Vector3::MinYIndex(std::vector<Vector3> list)
{
	Vector3& min = list[0];
	int index = 0;
	for (int i = 1; i < list.size(); i++)
	{
		if (min.y > list[i].y)
		{
			min = list[i];
			index = i;
		}
	}
	return index;
}

Vector3 Vector3::Lerp(Vector3& v1, Vector3& v2, float ratio)
{
	return Vector3(BaseMath::Lerp(v1.x, v2.x, ratio), BaseMath::Lerp(v1.y, v2.y, ratio), BaseMath::Lerp(v1.z, v2.z, ratio));
}

float Vector3::Distance(Vector3& v1, Vector3& v2)
{
	return sqrtf(powf(v2.x - v1.x, 2.0f) + powf(v2.y - v1.y, 2.0f) + powf(v2.z - v1.z, 2.0f));
}

Vector3 Vector3::Clamp(Vector3 value, Vector3 min, Vector3 max)
{
	float x = value.x, y = value.y, z = value.z;
	x = BaseMath::Clamp(x, min.x, max.x);
	y = BaseMath::Clamp(y, min.y, max.y);
	z = BaseMath::Clamp(z, min.z, max.z);
	return Vector3(x, y, z);
}

Vector3 Vector3::RotateClamp(Vector3 value)
{
	float x = value.x, y = value.y, z = value.z;
	if (x < 0) x = 360.0f - fmod(x, 360.0f);
	else if (x > 360) x = fmod(x, 360.0f);
	if (y < 0) y = 360.0f - fmod(y, 360.0f);
	else if (y > 360) y = fmod(y, 360.0f);
	if (z < 0) z = 360.0f - fmod(z, 360.0f);
	else if (z > 360) z = fmod(z, 360.0f);
	return Vector3(x, y, z);
}

Vector4::operator Vector2()
{
	return Vector2(x, y);
}

Vector4::operator Vector3()
{
	return Vector3(x, y, z);
}

Vector4& Vector4::operator+=(const Vector4& v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	this->w += v.w;

	return *this;
}

Vector4& Vector4::operator+=(const float v)
{
	this->x += v;
	this->y += v;
	this->z += v;
	this->w += v;

	return *this;
}

Vector4& Vector4::operator-=(const Vector4& v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	this->w -= v.w;

	return *this;
}

Vector4& Vector4::operator-=(const float v)
{
	this->x -= v;
	this->y -= v;
	this->z -= v;
	this->w -= v;

	return *this;
}

Vector4 Vector4::operator+(const Vector4& v) const
{
	return Vector4(*this) += v;
}

Vector4 Vector4::operator+(const float v) const
{
	return Vector4(*this) += v;
}

Vector4 Vector4::operator-(const Vector4& v) const
{
	return Vector4(*this) -= v;
}

Vector4 Vector4::operator-(const float v) const
{
	return Vector4(*this) -= v;
}

Vector4 Vector4::operator*(const float n) const
{
	return Vector4(n * x, n * y, n * z, n * w);
}

Vector4 Vector4::operator*(const Vector4& v) const
{
	return Vector4(x * v.x, y * v.y, z * v.z, w * v.w);
}

Vector4 Vector4::operator/(const float n) const
{
	return Vector4(x / n, y / n, z / n, w / n);
}

Vector4 Vector4::operator/(const Vector4& v) const
{
	return Vector4(x / v.x, y / v.y, z / v.z, w / v.w);
}

bool Vector4::operator==(const Vector4& v) const
{
	if (this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w)
		return true;
	return false;
}

bool Vector4::operator!=(const Vector4& v) const
{
	return !(this->operator==(v));
}

float Vector4::Dot3(const Vector4& v) const
{
	return (this->x * v.x + this->y * v.y + this->z * v.z);
}

Vector4 Vector4::Cross3(const Vector4& v) const
{
	return Vector4(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

float Vector4::Length3()
{
	return sqrtf(x * x + y * y + z * z);
}

float Vector4::SqrMagnitude3() const
{
	return (x * x + y * y + z * z);
}

Vector4 Vector4::Normalize3()
{
	float d = Length3();
	return Vector4(x / d, y / d, z / d);
}

float Vector4::Cos3(Vector4& v)
{
	return (Dot3(v) / (Length3() * v.Length3()));
}

float Vector4::AngleRad3(Vector4& v)
{
	return acosf(this->Dot3(v) / this->Length3() * v.Length3());
}

float Vector4::AngleDeg3(Vector4& v)
{
	return AngleRad3(v) * 180.0f / PI;
}

Vector4 Vector4::Proj3(Vector4& v)
{
	return (Length3() * Cos3(v) * v.Normalize3());
}

Vector4& Vector4::MinX(Vector4& v1, Vector4& v2)
{
	if (v1.x > v2.x)
		return v2;
	return v1;
}

Vector4& Vector4::MinX(Vector4* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector4& min = v[0];
	for (int i = 1; i < length; i++)
	{
		if (min.x > v[i].x)
		{
			min = v[i];
		}
	}
	return min;
}

int Vector4::MinXIndex(Vector4* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector4& min = v[0];
	int index = 0;
	for (int i = 1; i < length; i++)
	{
		if (min.x > v[i].x)
		{
			min = v[i];
			index = i;
		}
	}
	return index;
}

int Vector4::MinXIndex(std::vector<Vector4> list)
{
	Vector4& min = list[0];
	int index = 0;
	for (int i = 1; i < list.size(); i++)
	{
		if (min.x > list[i].x)
		{
			min = list[i];
			index = i;
		}
	}
	return index;
}

Vector4& Vector4::MinY(Vector4& v1, Vector4& v2)
{
	if (v1.y > v2.y)
		return v2;
	return v1;
}

Vector4& Vector4::MinY(Vector4* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector4& min = v[0];
	for (int i = 1; i < length; i++)
	{
		if (min.y > v[i].y)
		{
			min = v[i];
		}
	}
	return min;
}

int Vector4::MinYIndex(Vector4* v, int length)
{
	if (!v)
		throw "Trying to access null array";
	Vector4& min = v[0];
	int index = 0;
	for (int i = 1; i < length; i++)
	{
		if (min.y > v[i].y)
		{
			min = v[i];
			index = i;
		}
	}
	return index;
}

int Vector4::MinYIndex(std::vector<Vector4> list)
{
	Vector4& min = list[0];
	int index = 0;
	for (int i = 1; i < list.size(); i++)
	{
		if (min.y > list[i].y)
		{
			min = list[i];
			index = i;
		}
	}
	return index;
}
