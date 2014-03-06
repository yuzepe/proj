/*
 * Cuboid.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef CUBOID_H
#define CUBOID_H

#include "Shape.h"

using namespace std;

class Cuboid : public Shape
{
public:
	inline Cuboid(float length, float width, float height)
			: m_length(length), m_width(width), m_height(height) {};
	inline Cuboid(int length, int width, int height)
			: Cuboid(static_cast<float>(length), static_cast<float>(width), static_cast<float>(height)) {};
	~Cuboid();

	inline string toRawString() { ostringstream ostr; ostr << "cuboid " << m_length << " " << m_width << " " << m_height; return ostr.str(); };
	inline string toString() { ostringstream ostr; ostr << "Cuboid(l" << m_length << ", w" << m_width << ", h" << m_height << " cm)"; return ostr.str(); };

	inline float getVolume() { return m_length * m_width * m_height; }; // Kubikzentimeter cm³
private:
	float m_length; // Länge in Zentimeter
	float m_width; // Breite in Zentimeter
	float m_height; // Höhe in Zentimeter
};

#endif
