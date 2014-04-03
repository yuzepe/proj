/*
 * Tool.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef TOOL_H
#define TOOL_H

#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include "Item.h"
//~ #include "Shape.h"
//~ #include "Material.h"

using namespace std;

class Tool;
typedef Tool* ToolPtr;
typedef map<string, ToolPtr> ToolPtrMap;
typedef ToolPtrMap* ToolPtrMapPtr;

class Tool
{
public:
	Tool(string name, ItemPtrMapPtr p_mapItems);
	~Tool();

	string toRawString();
	string toString();

	inline float getMass() { return (mp_shape->getVolume() * mp_material->getDensity() / 1000.0f); }; // Masse in kg
	inline string getName() { return m_name; };
	inline ShapePtr getShape() { return mp_shape; };
	inline MaterialPtr getMaterial() { return mp_material; };
private:
	string m_name;
	ItemPtrMapPtr mp_mapItems;
};

#endif // TOOL_H
