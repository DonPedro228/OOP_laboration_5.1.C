#pragma once
#include "Vector3D.h"
using namespace std;

class D_Vector3D : public Vector3D
{
public:
	D_Vector3D& operator =(const D_Vector3D& other);
	operator string() const;
	D_Vector3D() : Vector3D() {}
	D_Vector3D(double x, double y, double z) : Vector3D() {}
	D_Vector3D(const char* str) : Vector3D(str) {}

	friend D_Vector3D operator*(double scalar, const D_Vector3D& vec);
	friend bool operator==(const D_Vector3D& vec1, const D_Vector3D& vec2);
	friend bool operator ^ (const D_Vector3D& vec1, const D_Vector3D& vec2);
	friend bool operator!=(const D_Vector3D& vec1, const D_Vector3D& vec2);

	D_Vector3D& operator ++();
	D_Vector3D& operator --();
	D_Vector3D operator ++(int);
	D_Vector3D operator --(int);

	double operator()() const;
};