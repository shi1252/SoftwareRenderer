#include "Image.h"
#include "..\Math\BaseMath.h"

Image::Image(const char* path)
{
	hBitmap = (HBITMAP)LoadImageA(NULL, path, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	if (!hBitmap) return;

	BITMAP bm;
	GetObject(hBitmap, sizeof(BITMAP), &bm);

	width = bm.bmWidth;
	height = bm.bmHeight;

	BITMAPINFOHEADER bmih;
	ZeroMemory(&bmih, sizeof(BITMAPINFOHEADER));
	bmih.biSize = sizeof(BITMAPINFOHEADER);
	bmih.biWidth = bm.bmWidth;
	bmih.biHeight = bm.bmHeight;
	bmih.biPlanes = 1;
	bmih.biBitCount = 32;
	bmih.biCompression = BI_RGB;
	bmih.biSizeImage = bm.bmWidth * 4 * bm.bmHeight;

	pixel = new BYTE[bmih.biSizeImage];
	if (!GetDIBits(CreateCompatibleDC(0), hBitmap, 0, bm.bmHeight, pixel, (BITMAPINFO*)& bmih, DIB_RGB_COLORS))
	{
		delete[] pixel;
	}
}

Image::Image(const Image& copy)
{
	width = copy.width;
	height = copy.height;
	pixel = new BYTE[width * height * 4];
	memcpy(pixel, copy.pixel, sizeof(BYTE) * width * height * 4);

}

Image::~Image()
{
	DeleteObject(hBitmap);
	delete[] pixel;
}

DWORD Image::GetColorByUV(float x, float y)
{
	if (!hBitmap) return 0;

	DWORD color = 0;
	int px = BaseMath::Clamp((int)(x * width), 0, width), py = BaseMath::Clamp((int)(y * height), 0, height);

	if (py <= 46)
		color = 0;
	BYTE r = pixel[(width * py + px) * 4 + 2];
	BYTE g = pixel[(width * py + px) * 4 + 1];
	BYTE b = pixel[(width * py + px) * 4 + 0];

	color = (r << 16) | (g << 8) | (b);

	return color;
}

DWORD Image::GetColorByUV(Vector2 v)
{
	return GetColorByUV(v.x, v.y);
}
