#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
using namespace std;

class VectorException : public exception {

public:
	VectorException(const char  *msg) : exception(msg) {
		throw invalid_argument("Incorrect value");
	}
};

class Vector3D
{
private:
	double x;
	double y;
	double z;
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(const char* str) {
		istringstream iss(str);
		char comma;
		if (!(iss >> x >> comma >> y >> comma >> z))
			throw VectorException("Incorerect value!");
	}

	~Vector3D();

	void Init(double x, double y, double z);

	double GetX() const { return x; }
	double GetY() const { return y; }
	double GetZ() const { return z; }

	void SetX(double value) { x = value; }
	void SetY(double value) { y = value; }
	void SetZ(double value) { z = value; }
	friend ostream& operator << (ostream& out, const Vector3D& m);
	friend istream& operator >> (istream& in, Vector3D& m);
};