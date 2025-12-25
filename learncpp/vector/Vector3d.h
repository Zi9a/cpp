#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3d.h"
#include <iostream>

class Vector3d {
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x, double y, double z)
		: m_x{x}, m_y{y}, m_z{z} {
	}

	void print() const {
		std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}

	friend void Point3d::moveByVector(const Vector3d& v);
};
#endif // !VECTOR3D_H
