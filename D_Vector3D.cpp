#include "D_Vector3D.h"
#include "Vector3D.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


D_Vector3D& D_Vector3D::operator=(const D_Vector3D& other)
{
	if (this != &other)
	{
		SetX(other.GetX());
		SetY(other.GetY());
		SetZ(other.GetZ());
	}
	return *this;
}

D_Vector3D::operator string() const
{
	stringstream sout;
	sout << "( " << GetX() << +", " << GetY() << ", " << GetZ() << ")";
	return sout.str();
}

D_Vector3D operator*(double scalar, const D_Vector3D& vec) {
	if (scalar == 0) {
		throw VectorException("Scalar can not be 0!");
	}
	return D_Vector3D(scalar * vec.GetX(), scalar * vec.GetY(), scalar * vec.GetZ());
}

bool operator!=(const D_Vector3D& vec1, const D_Vector3D& vec2) {
	return !(vec1 == vec2);
}

bool operator==(const D_Vector3D& vec1, const D_Vector3D& vec2) {
	return vec1.GetX() == vec2.GetX() && vec1.GetY() == vec2.GetY() && vec1.GetZ() == vec2.GetZ();
}

double D_Vector3D::operator()() const {
	return sqrt(GetX() * GetX() + GetY() * GetY() + GetZ() * GetZ());
}

bool operator ^ (const D_Vector3D& vec1, const D_Vector3D& vec2)
{
	return vec1() == vec2();
}

D_Vector3D& D_Vector3D::operator++() {
	SetX(GetX() + 1);
	SetY(GetY() + 1);
	SetZ(GetZ() + 1);
	return *this;
}

D_Vector3D& D_Vector3D::operator--() {
	SetX(GetX() - 1);
	SetY(GetY() - 1);
	SetZ(GetZ() - 1);
	return *this;
}

D_Vector3D D_Vector3D::operator++(int) {
	D_Vector3D temp(*this);
	++(*this);
	return temp;
}

D_Vector3D D_Vector3D::operator--(int) {
	D_Vector3D temp(*this);
	--(*this);
	return temp;
}