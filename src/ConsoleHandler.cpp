/*
 * ConsoleHandler.cpp
 *
 * @author Joseph Zehe
 *
 */

#include "ConsoleHandler.h"

ConsoleHandler::ConsoleHandler(MaterialPtrMapPtr p_mapMaterials, ItemPtrMapPtr p_mapItems, ToolPtrMapPtr p_mapTools)
: mp_mapMaterials(p_mapMaterials), mp_mapItems(p_mapItems), mp_mapTools(p_mapTools)
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
	MaterialPtrMap::iterator mat_it;
	ItemPtrMap::iterator itm_it;
	MaterialPtr p_material;
	ItemPtr p_item;
	ToolPtr p_tool;
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
					 << "create item <name> <shape> [0] [1] [2] <material> - Erstellt ein Item im Inventar" << endl
					 << "list tools - Listet die Tools im Inventar auf" << endl
					 << "create tool <name> <tools> - Erstellt ein Tool im Inventar" << endl;
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
					for(MaterialPtrMap::iterator it = mp_mapMaterials->begin(); it != mp_mapMaterials->end(); ++it)
						cout << (*it).second->toString() << endl;
				}
			break;
			case eCmdCreateMaterial:
				sArgs = cmd->getsArgs();
				fArgs = cmd->getfArgs();
				p_material = new Material(sArgs[0], fArgs[0]);
				(*mp_mapMaterials)[sArgs[0]] = p_material;
			break;
			case eCmdRemoveMaterial:
				sArgs = cmd->getsArgs();
				mat_it = mp_mapMaterials->find(sArgs[0]);
				if(mat_it != mp_mapMaterials->end())
				{
					mp_mapMaterials->erase(mat_it);
				}
				else { cout << "Material \"" << sArgs[0] << "\" wurde nicht gefunden" << endl; }
			break;
			case eCmdListItems:
				if(mp_mapItems->empty())
					cout << "Das Inventar ist leer" << endl;
				else
				{
					cout << "Folgene Items sind im Inventar:" << endl;
					for(ItemPtrMap::iterator it = mp_mapItems->begin(); it != mp_mapItems->end(); ++it)
						cout << it->second->toString() << endl;
				}
			break;
			case eCmdCreateItem:
				ShapePtr p_shape;
				sArgs = cmd->getsArgs();
				fArgs = cmd->getfArgs();
				mat_it = mp_mapMaterials->find(sArgs[1]);
				if(mat_it != mp_mapMaterials->end())
				{
					switch(fArgs.size())
					{
						case 1: p_shape = new Sphere(fArgs[0]);
						break;
						case 2: p_shape = new Cylinder(fArgs[0], fArgs[1]);
						break;
						case 3: p_shape = new Cuboid(fArgs[0], fArgs[1], fArgs[2]);
					}
					p_item = new Item(sArgs[0], p_shape, mat_it->second);
					(*mp_mapItems)[sArgs[0]] = p_item;
				}
				else { cout << "Material \"" << sArgs[1] << "\" wurde nicht gefunden" << endl; }
			break;
			case eCmdRemoveItem:
				sArgs = cmd->getsArgs();
				itm_it = mp_mapItems->find(sArgs[0]);
				if(itm_it != mp_mapItems->end())
				{
					mp_mapItems->erase(itm_it);
				}
				else { cout << "Gegenstand \"" << sArgs[0] << "\" wurde nicht gefunden" << endl; }
			break;
			case eCmdListTools:
				if(mp_mapTools->empty())
					cout << "Keine Werkzeuge vorhanden" << endl;
				else
				{
					cout << "Folgene Tools sind im Werkzeuggürtel:" << endl;
					for(ToolPtrMap::iterator it = mp_mapTools->begin(); it != mp_mapTools->end(); ++it)
						cout << it->second->toString() << endl;
				}
			break;
			case eCmdCreateTool:
				bool found = true;
				ItemPtrMapPtr p_mapItems = new ItemPtrMap;
				sArgs = cmd->getsArgs();
				for(unsigned int i = 1; i < sArgs.size(); ++i)
				{
					itm_it = mp_mapItems->find(sArgs[i]);
					if(found && itm_it != mp_mapItems->end())
					{
						(*p_mapItems)[sArgs[i]] = itm_it->second;
					}
					else { found = false; cout << "Item \"" << sArgs[i] << "\" wurde nicht gefunden" << endl; }
				}
				if(found)
				{
					p_tool = new Tool(sArgs[0], p_mapItems);
					(*mp_mapTools)[sArgs[0]] = p_tool;
				} // else <--- Speicherfreigabe von p_mapItems
			break;
		}
		delete cmd;
	}
}
