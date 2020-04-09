#pragma once
#include "BaseGeometry.h"

class CubeGeometry : public BaseGeometry
{
public:
	CubeGeometry(float width = 1, float height = 1, float depth = 1, DWORD color = 0);
};