#include "PixelShader.h"
#include "..\Buffer\BitmapBuffer.h"
#include "Pixel.h"

void PixelShader::Render(BitmapBuffer* buffer)
{
	for (int i = 0; i < pixels.size(); ++i)
	{
		if (buffer->GetDepth(pixels[i].position.x, pixels[i].position.y) <= pixels[i].depth)
		{
			buffer->SetColor(pixels[i].position.x, pixels[i].position.y, pixels[i].color);
			buffer->SetDepth(pixels[i].position.x, pixels[i].position.y, pixels[i].depth);
		}
	}

	pixels.clear();
}
