#include "Point3d.h"
#include "Vector3d.h"

void Point3d::moveByVector(const Vector3d& v) {
  // implement this function as a friend of class Vector3d
  m_x += v.m_x;
  m_y += v.m_y;
  m_z += v.m_z;
}
