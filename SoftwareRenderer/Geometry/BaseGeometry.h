#pragma once
#include "..\Shader\Vertex.h"
#include "..\Framework\HookVariable.h"

class Transform;
struct Matrix4x4;
class Image;

class BaseGeometry
{
public:
	Transform* transform = nullptr;
	Vertex* vertices = nullptr;
	int vertexCount = 0;
	int* indices = nullptr;
	int indexCount = 0;
	HookVariable<Image*> texture;

	BaseGeometry() { texture.SetHook(std::bind(&BaseGeometry::SetTexture, this)); };
	BaseGeometry(const BaseGeometry& copy);
	~BaseGeometry() { delete transform; transform = nullptr; delete[] vertices; vertices = nullptr; delete[] indices; indices = nullptr; delete texture; texture = nullptr; }
private:
	void SetTexture();
};