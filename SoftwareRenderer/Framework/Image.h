#pragma once
#include <Windows.h>
#include "..\Math\Vector.h"

class Image
{
private:
	int width;
	int height;
	HBITMAP hBitmap;

	BYTE* pixel;
public:
	Image(const char* path);
	Image(const Image& copy);
	~Image();

	DWORD GetColorByUV(float x, float y);
	DWORD GetColorByUV(Vector2 v);
};