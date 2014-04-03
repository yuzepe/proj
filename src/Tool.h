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

	inline float getMass(); // Masse in kg
	inline string getName() { return m_name; };
	inline ItemPtrMapPtr getItems() { return mp_mapItems; };
private:
	string m_name;
	ItemPtrMapPtr mp_mapItems;
};

#endif // TOOL_H
