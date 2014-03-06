/*
 * FileHandler.cpp
 *
 * @author Joseph Zehe
 *
 */

#include "FileHandler.h"

FileHandler::FileHandler(MaterialPtrMapPtr p_mapMaterials, ItemPtrMapPtr p_mapItems)
: mp_mapMaterials(p_mapMaterials), mp_mapItems(p_mapItems)
{
}

FileHandler::~FileHandler()
{
}


void FileHandler::loadMaterials()
{
	Parser parser;
	string str;
	ifstream file;
	string filename = "materials.dat";
	ConsoleCommandPtr cmd;
	vector<string> sArgs;
	vector<float> fArgs;
	MaterialPtr p_material;

	cout << "LOG: Lese aus Datei " << filename << endl;

	file.open(filename, ios::in);
	while (!file.eof())
    {
        getline(file, str);
		cmd = parser.parseMaterial(str);
		if(cmd->getName() == eCmdCreateMaterial)
		{
			sArgs = cmd->getsArgs();
			fArgs = cmd->getfArgs();
			p_material = new Material(sArgs[0], fArgs[0]);
			(*mp_mapMaterials)[sArgs[0]] = p_material;
		}
	}
	file.close();

	// Speicher freigeben? bzw. schon in while Schleife?
}

void FileHandler::loadItems()
{
	Parser parser;
	string str;
	ifstream file;
	string filename = "items.dat";
	ConsoleCommandPtr cmd;
	vector<string> sArgs;
	vector<float> fArgs;
	map<string, MaterialPtr>::iterator map_it;
	ItemPtr p_item;
	ShapePtr p_shape;

	cout << "LOG: Lese aus Datei " << filename << endl;

	file.open(filename, ios::in);
	while (!file.eof())
    {
		getline(file, str);
		cmd = parser.parseItem(str);
		if(cmd->getName() == eCmdCreateItem)
		{
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
		}
	}
	file.close();

	// Speicher freigeben? bzw. schon in while Schleife?
}

void FileHandler::saveMaterials()
{
	saveData("materials.dat", mp_mapMaterials);
}

void FileHandler::saveItems()
{
	saveData("items.dat", mp_mapItems);
}

template <typename T> void FileHandler::loadData(string filename, T data)
{
	/*Parser parser;
	string str;
	ifstream file;

	file.open(filename, ios::in);
	while (!file.eof())
    {
        getline(file, str);
        obj = parser.parse Item/Material(str); // geht das überhaupt
        data[obj->getName()] = obj; 		   // muss warschl. für jeden Datentyp einzeln definiert werden
    }
	file.close();*/
}

template <typename T> void FileHandler::saveData(string filename, T* data)
{
	cout << "LOG: Schreibe in Datei " << filename << endl;
	fstream file(filename, ios::out);
	for(typename T::iterator it = data->begin(); it != data->end(); ++it)
		file << it->second->toRawString() << endl;
	file.close();
}


/*map<string, MaterialPtr> FileHandler::loadMaterials()
{
	map<string, MaterialPtr> mapp;
	return mapp;
}

void FileHandler::saveMaterials(map<string, MaterialPtr>& map_MaterialPtr)
{
	cout << "Schreibe in Datei materials.dat" << endl;
	fstream file("materials.dat", ios::out);
	for(map<string, MaterialPtr>::iterator it = map_MaterialPtr.begin(); it != map_MaterialPtr.end(); ++it)
	{
		file << it->second->toString() << endl;
	}
	file.close();

	// unnötig und unsauber aber wayne? :O
	list<MaterialPtr> list_MaterialPtr;
	for(map<string, MaterialPtr>::iterator it = map_MaterialPtr.begin(); it != map_MaterialPtr.end(); ++it)
		list_MaterialPtr.push_back(it->second);
	saveFileData("materials.dat", list_MaterialPtr);
}

list<ItemPtr> FileHandler::loadItems()
{
	list<ItemPtr> listt;
	return listt;
}

void FileHandler::saveItems(list<ItemPtr>& list_ItemPtr)
{
	saveFileData("items.dat", list_ItemPtr);
}

template <typename T> T& FileHandler::loadFileData(string filename, T& data)
{
	T data;

	ConsoleParser parser;
	string str;
	ifstream file;
	file.open(filename, ios::in);
	while (!file.eof())
    {
        getline(file, string);
        parser.parse(string); // an der Stelle in den Parser einspeisen?
    }
	file.close();

	return data; // rm
}

template <typename T> void FileHandler::saveFileData(string filename, T& data)
{
	cout << "Schreibe in Datei " << filename << endl;
	fstream file(filename, ios::out);
	for(typename T::iterator it = data.begin(); it != data.end(); ++it)
		file << (*it)->toString() << endl;
	file.close();
}*/
