/*
 * main.cpp
 *
 * @author Joseph Zehe
 *
 */

#include <iostream>

#include "Material.h"
#include "Item.h"
#include "FileHandler.h"
#include "ConsoleHandler.h"

/*#include "Shape.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cuboid.h"*/


using namespace std;

/*void input(map<string, MaterialPtr>& map_MaterialPtr, list<ItemPtr>& list_ItemPtr)
{
	ConsoleParser parser;
	ConsoleCommandPtr cmd;
	vector<string> sArgs;
	vector<float> fArgs;
	MaterialPtr p_material;
	map<string, MaterialPtr>::iterator map_it;
	ItemPtr p_item;
	string strIn = "";
	while(true)
	{
		// cin >> strIn; trennt schon von Haus aus bei Leerzeichen
		getline(cin, strIn);

		cmd = parser.parse(strIn);

		switch(cmd->getName())
		{
			case eCmdEmpty:
				cout << "Ungültige Eingabe, \"help\" für mehr" << endl;
			break;
			case eCmdHelp:
				cout << "help - Zeigt die Hilfe an" << endl
					 << "exit - Beendet die Anwendung" << endl
					 << "list materials - Listet die Items im Inventar auf" << endl
					 << "create material <name> <density> - Erstellt ein Item im Inventar" << endl
					 << "list items - Listet die Items im Inventar auf" << endl
					 << "create item <name> <shape> [0] [1] [2] <material> - Erstellt ein Item im Inventar" << endl;
			break;
			case eCmdExit:
				cout << "Eingabe wird geschlossen..." << endl;
				return;
			break;
			case eCmdListMaterials:
				if(map_MaterialPtr.empty())
					cout << "Die Materialienliste ist leer" << endl;
				else
				{
					cout << "Folgene Materialien existieren:" << endl;
					for (map<string, MaterialPtr>::iterator it = map_MaterialPtr.begin(); it != map_MaterialPtr.end(); it++)
						cout << (*it).second->toString() << endl;
				}
			//set_MaterialPtr.find(p_material)  kann ein material gesucht werden
			if (fruits.find (pear) == fruits.end())
				{ std::cout<<"i don't have pear"; }
			break;
			case eCmdCreateMaterial:
				sArgs = cmd->getsArgs();
				fArgs = cmd->getfArgs();
				p_material = new Material(sArgs[0], fArgs[0]);
				map_MaterialPtr[sArgs[0]] = p_material;
			break;
			case eCmdRemoveMaterial:
				cout << "Noch keine Behandlung..." << endl;
				// TODO: Implementieren
			break;
			case eCmdListItems:
				if(list_ItemPtr.empty())
					cout << "Das Inventar ist leer" << endl;
				else
				{
					cout << "Folgene Items sind im Inventar:" << endl;
					for (list<ItemPtr>::iterator it = list_ItemPtr.begin(); it != list_ItemPtr.end(); it++)
						cout << (*it)->toString() << endl;
				}
			break;
			case eCmdCreateItem:
				ShapePtr p_shape;
				sArgs = cmd->getsArgs();
				fArgs = cmd->getfArgs();
				map_it = map_MaterialPtr.find(sArgs[1]);
				if(map_it != map_MaterialPtr.end())
				{
					switch(fArgs.size())
					{
						case 1: p_shape = new Sphere(fArgs[0]);
						break;
						case 2: p_shape = new Cylinder(fArgs[0], fArgs[1]);
						break;
						case 3: p_shape = new Cuboid(fArgs[0], fArgs[1], fArgs[2]);
					}
					p_item = new Item(sArgs[0], p_shape, (*map_it).second);
					list_ItemPtr.push_back(p_item);
				}
				else { cout << "Material \"" << sArgs[1] << "\" wurde nicht gefunden" << endl; }
			break;
			case eCmdRemoveItem:
				cout << "Noch keine Behandlung..." << endl;
				// TODO: Implementieren
			break;

			delete cmd;
		}

	}
	//while(cmd->getName() != eCmdExit);

	// delete cmd;


}*/

int main()
{

	// define main lists and objects
	MaterialPtrMapPtr p_mapMaterials = new map<string, MaterialPtr>;
	ItemPtrMapPtr p_mapItems = new map<string, ItemPtr>;
	FileHandler fileHandler(p_mapMaterials, p_mapItems);
	ConsoleHandler consoleHandler(p_mapMaterials, p_mapItems);

	// load recources
	fileHandler.loadMaterials();
	fileHandler.loadItems();

	// operate console
	/*ErrorCode = */consoleHandler.start();

	// save resources
	fileHandler.saveItems();
	fileHandler.saveMaterials();

	// langst das, oder muss durch die Elemente iteriet und diese gelöscht werden?
	delete p_mapMaterials;
	delete p_mapItems;



	//ItemPtr p_axe = new Tool("Axe");

	/*FileHandler handler;

	map<string, MaterialPtr> map_MaterialPtr;
	list<ItemPtr> list_ItemPtr;

	input(map_MaterialPtr, list_ItemPtr);

	handler.saveMaterials(map_MaterialPtr);
	handler.saveItems(list_ItemPtr);

	map_MaterialPtr.clear();
	list_ItemPtr.clear();*/

	return 0;
}
