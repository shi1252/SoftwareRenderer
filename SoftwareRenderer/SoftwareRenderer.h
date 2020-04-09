#pragma once
#include <Windows.h>

class BitmapBuffer;
class VertexShader;
class PixelShader;
class SoftwareRenderer
{
private:
	HWND hWnd;
	int width;
	int height;
	DWORD bgColor;
	BitmapBuffer* buffer;
	VertexShader* vs;
	PixelShader* ps;

	float oldTime;
public:
	SoftwareRenderer(HWND hWnd, int width = 800, int height = 600, DWORD bgColor = 0xff000000);
	~SoftwareRenderer();
	void Init();
	void Render();
	void Update();
	void Clear();
};