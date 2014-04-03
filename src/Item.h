/*
 * Item.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef ITEM_H
#define ITEM_H

#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include "Shape.h"
#include "Material.h"

using namespace std;

class Item;
typedef Item* ItemPtr;
typedef map<string, ItemPtr> ItemPtrMap;
typedef ItemPtrMap* ItemPtrMapPtr;

class Item
{
public:
	Item(string name, ShapePtr p_shape, MaterialPtr p_material);
	~Item();

	string toRawString();
	string toString();

	inline float getMass() { return (mp_shape->getVolume() * mp_material->getDensity() / 1000.0f); }; // Masse in kg
	inline string getName() { return m_name; };
	inline ShapePtr getShape() { return mp_shape; };
	inline MaterialPtr getMaterial() { return mp_material; };
private:
	string m_name;
	ShapePtr mp_shape;
	MaterialPtr mp_material;
};

#endif // ITEM_H
