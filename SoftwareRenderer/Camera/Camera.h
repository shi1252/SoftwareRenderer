#pragma once
#include "..\Framework\HookVariable.h"
#include "..\Math\Matrix4x4.h"
#include "..\Math\Vector.h"

class Transform;

class Camera
{
private:
	int width;
	int height;
	Matrix4x4 projectionMatrix;
public:
	Transform* transform;

	HookVariable<float> fieldOfView;
	HookVariable<float> near_Plane;
	HookVariable<float> far_Plane;
	float focalLength;
	float aspect;

	Camera(float width, float height, float fov = 60.f, float n = 0.1f, float f = 1000.f);
	~Camera();

	Matrix4x4 GetViewMatrix();
	Matrix4x4 GetProjectionMatrix();
	Vector4 NDCtoScreen(Vector4 v);
private:
	void SetProjectionMatrix();
};