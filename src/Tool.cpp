/*
 * Tool.cpp
 *
 * @author Joseph Zehe
 *
 */

#include "Tool.h"

Tool::Tool(string name, ItemPtrMapPtr p_mapItems)
 : m_name(name)
 , mp_mapItems(p_mapItems)
{
}

Tool::~Tool()
{
	delete mp_mapItems;
}

string Tool::toRawString()
{
	ostringstream ostr;

	ostr << m_name;

	for(ItemPtrMap::iterator it = mp_mapItems->begin(); it != mp_mapItems->end(); ++it)
		//ostr << " " << it->second->toRawString();
		ostr << " " << it->second->getName();

	return ostr.str();
}

string Tool::toString()
{
	ostringstream name_mass;
	ostringstream ostr;

	name_mass << m_name << "(" << getMass() << " kg):";
	ostr << left << setw(20) << name_mass.str();

	for(ItemPtrMap::iterator it = mp_mapItems->begin(); it != mp_mapItems->end(); ++it)
		ostr << left << "\n  " << setw(24) << it->second->toString();

	return ostr.str();
}

float Tool::getMass()
{
	float mass = 0.0f;

	for(ItemPtrMap::iterator it = mp_mapItems->begin(); it != mp_mapItems->end(); ++it)
		mass += it->second->getMass();
	return mass;
}
