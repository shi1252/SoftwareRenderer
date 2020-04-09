#pragma once
#include "BaseGeometry.h"

class PlaneGeometry : public BaseGeometry
{
public:
	PlaneGeometry(float width = 1, float height = 1, DWORD color = 0);
};