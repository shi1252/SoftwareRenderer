#pragma once
#include <Windows.h>

static const unsigned int BYTES_PER_PIXEL = 4;
static const unsigned int BITS_PER_PIXEL = 8 * BYTES_PER_PIXEL;

class BitmapBuffer
{
private:
	HWND hWnd;
	UINT width;
	UINT height;
	DWORD bgColor;
	DWORD scanlineCount;

	HDC hdc;
	HDC memDC;
	HBITMAP frontBitmap;
	HBITMAP backBitmap;

	BYTE* bits;
	float* depthBuffer;
public:
	float minDepth;
	float maxDepth;

	BitmapBuffer(HWND hWnd, UINT width, UINT height, DWORD bgColor = 0xff000000);
	~BitmapBuffer();

	void Draw();
	void Clear();

	void SetColor(UINT x, UINT y, DWORD color);
	void SetDepth(UINT x, UINT y, float depth);
	float GetDepth(UINT x, UINT y);
	void SetDepthDefault(float min, float max);
	UINT GetWidth() { return width; }
	UINT GetHeight() { return height; }
};