/*
 * Cylinder.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"

using namespace std;

class Cylinder : public Shape
{
public:
	inline Cylinder(float radius, float height)
			: m_radius(radius), m_height(height) {};
	inline Cylinder(int radius, int height)
			: Cylinder(static_cast<float>(radius), static_cast<float>(height)) {};
	~Cylinder();

	inline string toRawString() { ostringstream ostr; ostr << "cylinder " << m_radius << " " << m_height; return ostr.str(); };
	inline string toString() { ostringstream ostr; ostr << "Cylinder(r" << m_radius << ", h" << m_height << " cm)"; return ostr.str(); };

	inline float getVolume() { return M_PI * m_radius*m_radius * m_height; }; // Kubikzentimeter cm³
private:
	float m_radius; // Radius in Zentimeter
	float m_height; // Höhe in Zentimeter
};

#endif
