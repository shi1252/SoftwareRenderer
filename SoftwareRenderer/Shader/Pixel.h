#pragma once
#include "..\Math\Vector.h"

typedef unsigned long DWORD;

class Pixel
{
public:
	Pixel(int x, int y, DWORD color);
	Vector2 position;
	float depth = 1.f;
	DWORD color;
};