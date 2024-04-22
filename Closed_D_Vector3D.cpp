#include "Closed_D_Vector3D.h"
#include <iostream>
#include <sstream>
using namespace std;


Closed_D_Vector3D& Closed_D_Vector3D::operator++() {
    SetX(GetX() + 1);
    SetY(GetY() + 1);
    SetZ(GetZ() + 1);
    return *this;
}

Closed_D_Vector3D& Closed_D_Vector3D::operator--() {
    SetX(GetX() - 1);
    SetY(GetY() - 1);
    SetZ(GetZ() - 1);
    return *this;
}

Closed_D_Vector3D Closed_D_Vector3D::operator++(int) {
    SetX(GetX() + 1);
    SetY(GetY() + 1);
    SetZ(GetZ() + 1);
    return *this;
}

Closed_D_Vector3D Closed_D_Vector3D::operator--(int) {
    SetX(GetX() - 1);
    SetY(GetY() - 1);
    SetZ(GetZ() - 1);
    return *this;
}

double Closed_D_Vector3D::operator()() const {
    return sqrt(GetX() * GetX() + GetY() * GetY() + GetZ() * GetZ());
}

Closed_D_Vector3D operator*(double scalar, const Closed_D_Vector3D& vec) {
    if (scalar == 0) {
        throw VectorException("Scalar can not be 0!");
    }
    return Closed_D_Vector3D(scalar * vec.GetX(), scalar * vec.GetY(), scalar * vec.GetZ());
}


bool operator!=(const Closed_D_Vector3D& vec1, const Closed_D_Vector3D& vec2) {
    return !(vec1 == vec2);
}

bool operator==(const Closed_D_Vector3D& vec1, const Closed_D_Vector3D& vec2) {
    return vec1.GetX() == vec2.GetX() && vec1.GetY() == vec2.GetY() && vec1.GetZ() == vec2.GetZ();
}

bool operator ^ (const Closed_D_Vector3D& vec1, const Closed_D_Vector3D& vec2)
{
    return vec1() == vec2();
}


ostream& operator<<(ostream& out, const Closed_D_Vector3D& vec) {
    out << "(" << vec.GetX() << ", " << vec.GetY() << ", " << vec.GetZ() << ")";
    return out;
}

istream& operator>>(istream& input, Closed_D_Vector3D& vec) {
    cout << "Enter x: ";
    double x, y, z;
    if (!(input >> x)) {
        throw VectorException("Invalid input: x must be a number.");
    }
    vec.SetX(x);

    cout << "Enter y: ";
    if (!(input >> y)) {
        throw VectorException("Invalid input: y must be a number.");
    }
    vec.SetY(y);

    cout << "Enter z: ";
    if (!(input >> z)) {
        throw VectorException("Invalid input: z must be a number.");
    }
    vec.SetZ(z);

    return input;
}


Closed_D_Vector3D& Closed_D_Vector3D::operator=(const Closed_D_Vector3D& other) {
    if (this != &other) {
        Vector3D::operator=(other);
    }
    return *this;
}

Closed_D_Vector3D::operator string() const {
    stringstream sout;
    sout << "( " << GetX() << +", " << GetY() << ", " << GetZ() << ")";
    return sout.str();
}