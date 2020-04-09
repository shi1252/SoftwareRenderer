#include "Transform.h"
#include "..\Math\Matrix4x4.h";
#include "..\Math\Vector.h"

Transform::Transform()
{
	position = new Vector3(Vector3::zero);
	rotation = new Vector3(Vector3::zero);
	scale = new Vector3(Vector3::one);
}

Transform::Transform(const Transform& t)
{
	position = t.position;
	rotation = t.rotation;
	scale = t.scale;
}

Transform::~Transform()
{
}

Vector3 Transform::Right()
{
	return Matrix4x4::YXZRotateMatrix(*rotation) * Vector3::right;
}

Vector3 Transform::Up()
{
	return Matrix4x4::YXZRotateMatrix(*rotation) * Vector3::up;
}

Vector3 Transform::Forward()
{
	return Matrix4x4::YXZRotateMatrix(*rotation) * Vector3::forward;
}

Matrix4x4 Transform::Matrix()
{
	return Matrix4x4::TRSMatrix(*position, *rotation, *scale);
}

Matrix4x4 Transform::InvMatrix()
{
	return Matrix4x4::InverseTRSMatrix(*position, *rotation, *scale);
}

void Transform::Translate(Vector3 pos)
{
	(*position) = pos;
}

void Transform::Translate(Vector3 dir, float distance)
{
	(*position) += dir * distance;
}

void Transform::Rotate(Vector3 rot)
{
	(*rotation) = Vector3::RotateClamp((*rotation) + rot);
}