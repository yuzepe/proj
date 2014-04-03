/*
 * Item.cpp
 *
 * @author Joseph Zehe
 *
 */

#include "Item.h"

Item::Item(string name, ShapePtr p_shape, MaterialPtr p_material)
 : m_name(name)
 , mp_shape(p_shape)
 , mp_material(p_material)
{
}

Item::~Item()
{
	delete mp_shape;
	delete mp_material;
}

string Item::toRawString()
{
	ostringstream ostr;
	ostr << m_name << " " << mp_shape->toRawString() << " " << mp_material->getName();
	return ostr.str();
}

string Item::toString()
{
	ostringstream name_mass;
	ostringstream ostr;

	name_mass << m_name << "(" << getMass() << " kg)";
	ostr << left << setw(20) << name_mass.str() << " " << setw(24) << mp_shape->toString() << " " << mp_material->toString();

	return ostr.str();
}
