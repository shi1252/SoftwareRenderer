#include "Camera.h"
#include "..\Math\BaseMath.h"
#include "..\Math\Matrix4x4.h"
#include "..\Framework\Transform.h"
#include "..\Math\Vector.h"

Camera::Camera(float width, float height, float fov, float n, float f)
{
	this->width = width;
	this->height = height;
	aspect = width / (float)height;

	fieldOfView = fov;
	near_Plane = n;
	fieldOfView.SetHook(std::bind(&Camera::SetProjectionMatrix, this));
	near_Plane.SetHook(std::bind(&Camera::SetProjectionMatrix, this));
	far_Plane.SetHook(std::bind(&Camera::SetProjectionMatrix, this));
	far_Plane = f;

	transform = new Transform();
	transform->position->z = -10.f;
}

Camera::~Camera()
{
}

Matrix4x4 Camera::GetViewMatrix()
{
	return transform->InvMatrix();
}

Matrix4x4 Camera::GetProjectionMatrix()
{
	return projectionMatrix;
}

Vector4 Camera::NDCtoScreen(Vector4 v)
{
	Vector4 temp = ((v / fabs(v.w)) + 1.f) / 2.f;
	temp = Vector4(roundf(temp.x * width), roundf(temp.y * height), temp.z, v.w);
	return temp;
}

void Camera::SetProjectionMatrix()
{
	focalLength = 1.f / tanf((fieldOfView * DegToRad) / 2.0f);

	projectionMatrix = Matrix4x4(
		focalLength / aspect, 0, 0, 0,
		0, focalLength, 0, 0,
		0, 0, (near_Plane + far_Plane) / (near_Plane - far_Plane), (2 * near_Plane * far_Plane) / (near_Plane - far_Plane),
		0, 0, -1, 0);
}
