#pragma once
#include <vector>
#include "Pixel.h"

class BitmapBuffer;

class PixelShader
{
public:
	std::vector<Pixel> pixels;
	void Render(BitmapBuffer* buffer);
};