/*
 * main.cpp
 *
 * @author Joseph Zehe
 *
 */

#include <iostream>

#include "Material.h"
#include "Item.h"
#include "Tool.h"
#include "FileHandler.h"
#include "ConsoleHandler.h"

using namespace std;

int main()
{
	// define main lists and objects
	MaterialPtrMapPtr p_mapMaterials = new MaterialPtrMap;
	ItemPtrMapPtr p_mapItems = new ItemPtrMap;
	ToolPtrMapPtr p_mapTools = new ToolPtrMap;
	FileHandler fileHandler(p_mapMaterials, p_mapItems/*, p_mapTools*/);
	ConsoleHandler consoleHandler(p_mapMaterials, p_mapItems, p_mapTools);

	// load recources
	fileHandler.loadMaterials();
	fileHandler.loadItems();

	// operate console
	/*ErrorCode = */consoleHandler.start();

	// save resources
	fileHandler.saveItems();
	fileHandler.saveMaterials();

	// langst das, oder muss durch die Elemente iteriert und diese gelöscht werden?
	delete p_mapMaterials;
	delete p_mapItems;
	delete p_mapTools;

	//ItemPtr p_axe = new Tool("Axe");

	/*
	map_MaterialPtr.clear();
	list_ItemPtr.clear();*/

	return 0;
}
