#include "SoftwareRenderer.h"
#include "Buffer\BitmapBuffer.h"
#include "Shader\VertexShader.h"
#include "Shader\PixelShader.h"
#include "Math\Matrix4x4.h"
#include "Geometry\BaseGeometry.h"
#include "Geometry\CubeGeometry.h"
#include "Camera\Camera.h"
#include <time.h>

#pragma region World Matrix
Matrix4x4 worldMatrix(
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1);
#pragma endregion
Camera* mainCam;
static std::vector<BaseGeometry*> geoList;


SoftwareRenderer::SoftwareRenderer(HWND hWnd, int width, int height, DWORD bgColor):
	hWnd(hWnd), width(width), height(height), bgColor(bgColor)
{
	buffer = new BitmapBuffer(hWnd, width, height, bgColor);
	vs = new VertexShader();
	ps = new PixelShader();
}

SoftwareRenderer::~SoftwareRenderer()
{
	delete buffer;
	delete vs;
	delete ps;
}

void SoftwareRenderer::Init()
{
	oldTime = clock();
	mainCam = new Camera(width, height);

	geoList.push_back(new CubeGeometry(1.f, 1.f, 1.f, 0xffff0000));
}

void SoftwareRenderer::Render()
{
	buffer->Clear();

	for (int i = 10; i < 20; ++i)
		buffer->SetColor(i, 599, 0xffff0000);
	// Call DrawFunction
	//Vertex v1(-0.1.f, 0.1.f, 0, RGB(255, 0, 0)), v2(-0.1.f, -0.1.f, 0, RGB(0, 255, 0)), v3(0, 0, 0, RGB(0, 0, 255));
	//DrawTriangleV2(bb, v1, v2, v3);

	//Vertex v1(-1, -1, -.5f, 0), v2(-1, 1, -0.5f, 0), v3(0, 1, 1.f, 0);
	//Vertex v4(0, 0, -.4, 255), v5(0, 2, -.4, 255), v6(0, 0, 0, 255);
	//v1 = mvp * v1;
	//v2 = mvp * v2;
	//v3 = mvp * v3;
	//v4 = mvp * v4;
	//v5 = mvp * v5;
	//v6 = mvp * v6;
	//DrawTriangleV2(buffer, v1, v2, v3);
	//DrawTriangleV2(buffer, v4, v5, v6);

	//for (int i = 0; i < renderList.size(); i++)
	//{
	//	renderList[i]->Draw(buffer, mvp);
	//}

	// TODO: Frustum Culling
	for (int i = 0; i < geoList.size(); ++i)
		vs->push_back(geoList[i]);
	ps->pixels = vs->Rasterize(mainCam);
	ps->Render(buffer);

	buffer->Draw();
}

void SoftwareRenderer::Update()
{
	float curTime = clock();
	float deltaTime = (curTime - oldTime) / CLOCKS_PER_SEC;

	//if (GetAsyncKeyState(VK_LSHIFT))
	//{
	//	if (GetAsyncKeyState('W'))
	//		mainCam->transform.Rotate(-mainCam->transform.right);
	//	if (GetAsyncKeyState('S'))
	//		mainCam->transform.Rotate(mainCam->transform.right);
	//	if (GetAsyncKeyState('A'))
	//		mainCam->transform.Rotate(-mainCam->transform.up);
	//	if (GetAsyncKeyState('D'))
	//		mainCam->transform.Rotate(mainCam->transform.up);
	//	if (GetAsyncKeyState('Q'))
	//		mainCam->transform.Rotate(mainCam->transform.forward);
	//	if (GetAsyncKeyState('E'))
	//		mainCam->transform.Rotate(-mainCam->transform.forward);
	//}
	//else
	//{
	//	if (GetAsyncKeyState('W'))
	//		mainCam->transform.Translate(mainCam->transform.up, 1.0f);// *deltaTime);
	//	if (GetAsyncKeyState('S'))
	//		mainCam->transform.Translate(-mainCam->transform.up, 1.0f);// *deltaTime);
	//	if (GetAsyncKeyState('A'))
	//		mainCam->transform.Translate(-mainCam->transform.right, 1.0f);// *deltaTime);
	//	if (GetAsyncKeyState('D'))
	//		mainCam->transform.Translate(mainCam->transform.right, 1.0f);// *deltaTime);
	//	if (GetAsyncKeyState('Q'))
	//		mainCam->transform.Translate(mainCam->transform.forward, 1.0f);// *deltaTime);
	//	if (GetAsyncKeyState('E'))
	//		mainCam->transform.Translate(-mainCam->transform.forward, 1.0f);// *deltaTime);
	//}

	//renderList[0]->transform->Rotate(Vector3(0.f, 1.f, 0));
	//renderList[0]->transform->Translate(Vector3(1.f, 0.f, 0), 1.0f);

	oldTime = curTime;
}

void SoftwareRenderer::Clear()
{
	for (int i = 0; i < geoList.size(); i++)
		geoList[i]->~BaseGeometry();
	geoList.clear();

	//delete mainCam;
	//mainCam = nullptr;
}
