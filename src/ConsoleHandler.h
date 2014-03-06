/*
 * ConsoleHandler.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H

#include <string>
#include <iostream>

#include "Material.h"
#include "Item.h"
#include "Parser.h"

using namespace std;

class ConsoleHandler
{
public:
	ConsoleHandler(MaterialPtrMapPtr p_mapMaterials, ItemPtrMapPtr p_mapItems);
	~ConsoleHandler();

	void start();

private:
	MaterialPtrMapPtr mp_mapMaterials;
	ItemPtrMapPtr mp_mapItems;
};

#endif
