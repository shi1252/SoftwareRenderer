#pragma once

struct Vector3;
struct Vector4;
class Vertex;

struct Matrix4x4
{
	float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;

	Matrix4x4()
		:m00(1.f), m01(0.f), m02(0.f), m03(0.f),
		m10(0.f), m11(1.f), m12(0.f), m13(0.f),
		m20(0.f), m21(0.f), m22(1.f), m23(0.f),
		m30(0.f), m31(0.f), m32(0.f), m33(1.f)
	{}
	Matrix4x4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
		: m00(m00), m01(m01), m02(m02), m03(m03),
		m10(m10), m11(m11), m12(m12), m13(m13),
		m20(m20), m21(m21), m22(m22), m23(m23),
		m30(m30), m31(m31), m32(m32), m33(m33)
	{}
	Matrix4x4(Vector4 col1, Vector4 col2, Vector4 col3, Vector4 col4);

	const static Matrix4x4 identity;

	Matrix4x4 operator+(const Matrix4x4& m);
	Matrix4x4 operator-(const Matrix4x4& m);
	Matrix4x4 operator*(const Matrix4x4& m);
	//Matrix4x4 operator*(const Matrix3x3 &m)
	//{
	//	return Matrix4x4(
	//		m00 * m.m00 + m01 * m.m10 + m02 * m.m20,
	//		m00 * m.m01 + m01 * m.m11 + m02 * m.m21,
	//		m00 * m.m02 + m01 * m.m12 + m02 * m.m22,
	//		m03,
	//		m10 * m.m00 + m11 * m.m10 + m12 * m.m20,
	//		m10 * m.m01 + m11 * m.m11 + m12 * m.m21,
	//		m10 * m.m02 + m11 * m.m12 + m12 * m.m22,
	//		m13,
	//		m20 * m.m00 + m21 * m.m10 + m22 * m.m20,
	//		m20 * m.m01 + m21 * m.m11 + m22 * m.m21,
	//		m20 * m.m02 + m21 * m.m12 + m22 * m.m22,
	//		m23,
	//		m30 * m.m00 + m31 * m.m10 + m32 * m.m20,
	//		m30 * m.m01 + m31 * m.m11 + m32 * m.m21,
	//		m30 * m.m02 + m31 * m.m12 + m32 * m.m22,
	//		m33
	//	);
	//}
	Vector3 operator*(Vector3 v);
	Vector4 operator*(Vector4 v);
	Vertex operator*(Vertex v);
	float& operator()(int r, int c);
	static Matrix4x4 TransposeMatrix(const Matrix4x4& m);
	static Matrix4x4 TranslateMatrix(float x, float y, float z);
	static Matrix4x4 TranslateMatrix(Vector3 v);
	static Matrix4x4 InverseTranslateMatrix(float x, float y, float z);
	static Matrix4x4 InverseTranslateMatrix(Vector3 v);
	static Matrix4x4 XRotateMatrix(float degree);
	static Matrix4x4 YRotateMatrix(float degree);
	static Matrix4x4 ZRotateMatrix(float degree);
	static Matrix4x4 InverseXRotateMatrix(float degree);
	static Matrix4x4 InverseYRotateMatrix(float degree);
	static Matrix4x4 InverseZRotateMatrix(float degree);
	static Matrix4x4 YXZRotateMatrix(Vector3 rotation);
	static Matrix4x4 InverseYXZRotateMatrix(Vector3 rotation);
	static Matrix4x4 ScaleMatrix(float scale);
	static Matrix4x4 ScaleMatrix(float x, float y, float z);
	static Matrix4x4 ScaleMatrix(Vector3 v);
	static Matrix4x4 InverseScaleMatrix(float scale);
	static Matrix4x4 InverseScaleMatrix(float x, float y, float z);
	static Matrix4x4 InverseScaleMatrix(Vector3 v);
	static Matrix4x4 TRSMatrix(Vector3 position, Vector3 rotation, Vector3 scale);
	static Matrix4x4 InverseTRSMatrix(Vector3 position, Vector3 rotation, Vector3 scale);
};