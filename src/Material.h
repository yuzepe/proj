/*
 * Material.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#define _USE_MATH_DEFINES

#include <math.h>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Material;
typedef Material* MaterialPtr;
typedef map<string, MaterialPtr> MaterialPtrMap;
typedef MaterialPtrMap* MaterialPtrMapPtr;

class Material
{
public:
	inline Material(string name, float density) : m_name(name), m_density(density) {};
	inline Material(string name, int density) : Material(name, static_cast<float>(density)) {};
	~Material();

	inline string toRawString() { ostringstream ostr; ostr << m_name << " " << m_density; return ostr.str(); };
	inline string toString() { ostringstream ostr; ostr << m_name << "(" << m_density << " g/cm³)"; return ostr.str(); };

	inline string getName() { return m_name; };
	inline float getDensity() { return m_density; };

private:
	string m_name;
	float m_density; // Dichte g/cm³
};

#endif
