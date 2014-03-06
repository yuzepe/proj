/*
 * ConsoleHandler.cpp
 *
 * @author Joseph Zehe
 *
 */

#include "ConsoleHandler.h"

ConsoleHandler::ConsoleHandler(MaterialPtrMapPtr p_mapMaterials, ItemPtrMapPtr p_mapItems)
: mp_mapMaterials(p_mapMaterials), mp_mapItems(p_mapItems)
{

}

ConsoleHandler::~ConsoleHandler()
{

}

void ConsoleHandler::start()
{
	Parser parser;
	ConsoleCommandPtr cmd;
	vector<string> sArgs;
	vector<float> fArgs;
	MaterialPtr p_material;
	map<string, MaterialPtr>::iterator map_it;
	ItemPtr p_item;
	string strIn = "";

	cout << "LOG: Starte Consolen Verarbeitung " << endl;

	while(true)
	{
		// cin >> strIn; trennt schon von Haus aus bei Leerzeichen
		getline(cin, strIn);

		cmd = parser.parseConsole(strIn);

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
				if(mp_mapMaterials->empty())
					cout << "Die Materialienliste ist leer" << endl;
				else
				{
					cout << "Folgene Materialien existieren:" << endl;
					for (map<string, MaterialPtr>::iterator it = mp_mapMaterials->begin(); it != mp_mapMaterials->end(); it++)
						cout << (*it).second->toString() << endl;
				}
			//set_MaterialPtr.find(p_material)  kann ein material gesucht werden
			/*if (fruits.find (pear) == fruits.end())
				{ std::cout<<"i don't have pear"; }*/
			break;
			case eCmdCreateMaterial:
				sArgs = cmd->getsArgs();
				fArgs = cmd->getfArgs();
				p_material = new Material(sArgs[0], fArgs[0]);
				(*mp_mapMaterials)[sArgs[0]] = p_material;
			break;
			case eCmdRemoveMaterial:
				cout << "Noch keine Behandlung..." << endl;
				// TODO: Implementieren
			break;
			case eCmdListItems:
				if(mp_mapItems->empty())
					cout << "Das Inventar ist leer" << endl;
				else
				{
					cout << "Folgene Items sind im Inventar:" << endl;
					for (map<string, ItemPtr>::iterator it = mp_mapItems->begin(); it != mp_mapItems->end(); it++)
						cout << it->second->toString() << endl;
				}
			break;
			case eCmdCreateItem:
				ShapePtr p_shape;
				sArgs = cmd->getsArgs();
				fArgs = cmd->getfArgs();
				map_it = mp_mapMaterials->find(sArgs[1]);
				if(map_it != mp_mapMaterials->end())
				{
					switch(fArgs.size())
					{
						case 1: p_shape = new Sphere(fArgs[0]);
						break;
						case 2: p_shape = new Cylinder(fArgs[0], fArgs[1]);
						break;
						case 3: p_shape = new Cuboid(fArgs[0], fArgs[1], fArgs[2]);
					}
					p_item = new Item(sArgs[0], p_shape, map_it->second);
					(*mp_mapItems)[sArgs[0]] = p_item;
				}
				else { cout << "Material \"" << sArgs[1] << "\" wurde nicht gefunden" << endl; }
			break;
			case eCmdRemoveItem:
				cout << "Noch keine Behandlung..." << endl;
				// TODO: Implementieren
			break;
		}
		delete cmd;
	}
}
