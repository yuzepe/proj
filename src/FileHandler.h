/*
 * FileHandler.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <fstream>
#include <iostream>

#include "Material.h"
#include "Item.h"
#include "Parser.h"

using namespace std;

class FileHandler
{
public:
	FileHandler(MaterialPtrMapPtr p_mapMaterials, ItemPtrMapPtr p_mapItems);
	~FileHandler();

	void loadMaterials();
	void loadItems();

	void saveMaterials();
	void saveItems();

	/*map<string, MaterialPtr> loadMaterials();
	void saveMaterials(map<string, MaterialPtr>& map_MaterialPtr);
	list<ItemPtr> loadItems();
	void saveItems(list<ItemPtr>& list_ItemPtr);
	template <typename T> T& loadFileData(string filename, T& data);
	template <typename T> void saveFileData(string filename, T& data);*/

private:
	MaterialPtrMapPtr mp_mapMaterials;
	ItemPtrMapPtr mp_mapItems;

	template <typename T> void loadData(string filename, T data);
	template <typename T> void saveData(string filename, T* data);
};

#endif
