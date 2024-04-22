#pragma once
#include "D_Vector3D.h"

class Closed_D_Vector3D : private Vector3D {
public:
    using Vector3D::GetX;
    using Vector3D::GetY;
    using Vector3D::GetZ;

    Closed_D_Vector3D& operator=(const Closed_D_Vector3D& other);
    operator string() const;

    Closed_D_Vector3D() : Vector3D() {}
    Closed_D_Vector3D(double x, double y, double z) : Vector3D(x, y, z) {}
    Closed_D_Vector3D(const char* str) : Vector3D(str) {}

    double operator()() const;
    friend Closed_D_Vector3D operator*(double scalar, const Closed_D_Vector3D& vec);
    friend bool operator==(const Closed_D_Vector3D& vec1, const Closed_D_Vector3D& vec2);
    friend bool operator ^ (const Closed_D_Vector3D& vec1, const Closed_D_Vector3D& vec2);
    friend bool operator!=(const Closed_D_Vector3D& vec1, const Closed_D_Vector3D& vec2);

    Closed_D_Vector3D& operator++();
    Closed_D_Vector3D& operator--();
    Closed_D_Vector3D operator++(int);
    Closed_D_Vector3D operator--(int);

    friend ostream& operator<<(ostream& out, const Closed_D_Vector3D& vec);
    friend istream& operator>>(istream& in, Closed_D_Vector3D& vec);


};