#pragma once
#include <vector>
#include "Vertex.h"
#include "Pixel.h"

class BaseGeometry;
class Camera;

class VertexShader
{
public:
	std::vector<Vertex> vertices;
	std::vector<int> indicies;
	std::vector<Pixel> Rasterize(Camera *cam);
	void push_back(BaseGeometry *geo);
};