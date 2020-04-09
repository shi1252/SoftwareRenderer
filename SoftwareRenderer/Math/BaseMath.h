#pragma once
#include <math.h>
#include <stdarg.h>
#define PI 3.141592f
#define DegToRad 0.01745329252f
#define RadToDeg 57.295779513f
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

static class BaseMath
{
public:
	template <typename T>
	static T Lerp(T& val1, T& val2, float ratio)
	{
		ratio = Clamp(ratio, 0.f, 1.f);
		return (val1 + (val2 - val1) * ratio);
	}
	template <typename T>
	static T Clamp(T value, T min, T max)
	{
		if (value > max) value = max;
		if (value < min) value = min;
		return value;
	}
	template <typename T>
	static T Min(T &v1, T &v2)
	{
		return v1 < v2 ? v1 : v2;
	}
	template <typename T>
	static T Min(const int count, ...)
	{
		va_list vl;
		va_start(vl, count);

		T min = va_arg(vl, T);
		T temp;
		for (int i = 0; i < count-1; ++i)
		{
			temp = va_arg(vl, T);
			min > temp ? min = temp : 0;
		}

		va_end(vl);
		return min;
	}
	template <typename T>
	static T Max(T& v1, T& v2)
	{
		return v1 > v2 ? v1 : v2;
	}
	template <typename T>
	static T Max(const int count, ...)
	{
		va_list vl;
		va_start(vl, count);

		T max = va_arg(vl, T);
		T temp;
		for (int i = 0; i < count - 1; ++i)
		{
			temp = va_arg(vl, T);
			max < temp ? max = temp : 0;
		}

		va_end(vl);
		return max;
	}
};