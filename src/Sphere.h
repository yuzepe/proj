/*
 * Sphere.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef SPHERE_H
#define SPHERE_H

#include <sstream>
#include <string>

#include "Shape.h"

using namespace std;

class Sphere : public Shape
{
public:
	inline Sphere(float radius = 10) : m_radius(radius) {};
	inline Sphere(int radius) : Sphere(static_cast<float>(radius)) {};
	~Sphere();

	inline string toRawString() { ostringstream ostr; ostr << "sphere " << m_radius; return ostr.str(); };
	inline string toString() { ostringstream ostr; ostr << "Sphere(r" << m_radius << " cm)"; return ostr.str(); };

	inline float getVolume() { return 4.0f * M_PI * pow(m_radius, 3) / 3.0f; }; // Kubikzentimeter cm³
private:
	float m_radius; // Zentimeter
};

#endif
