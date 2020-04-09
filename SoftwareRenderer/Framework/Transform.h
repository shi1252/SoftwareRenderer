#pragma once

struct Vector3;
struct Matrix4x4;

class Transform
{
public:
	Vector3* position;
	Vector3* rotation;
	Vector3* scale;

	Vector3 Right();
	Vector3 Up();
	Vector3 Forward();
	Matrix4x4 Matrix();
	Matrix4x4 InvMatrix();

	Transform();
	Transform(const Transform& t);
	~Transform();

	void Translate(Vector3 pos);
	void Translate(Vector3 dir, float distance);
	void Rotate(Vector3 rot);
};