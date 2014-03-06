/*
 * Parser.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Material.h"
#include "Item.h"
#include "Shape.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cuboid.h"

using namespace std;

enum ConsoleCommandName
{
	eCmdEmpty,
	eCmdHelp,
	eCmdExit,
	eCmdListMaterials,
	eCmdCreateMaterial,
	eCmdRemoveMaterial,
	eCmdListItems,
	eCmdCreateItem,
	eCmdRemoveItem
};

class ConsoleCommand;
typedef ConsoleCommand* ConsoleCommandPtr;

class ConsoleCommand
{
public:
	ConsoleCommand(ConsoleCommandName name, const vector<string>& sArgs, const vector<float>& fArgs);
	ConsoleCommand(ConsoleCommandName name, const vector<string>& sArgs);
	ConsoleCommand(ConsoleCommandName name = eCmdEmpty);
	~ConsoleCommand();

	inline ConsoleCommandName getName() { return m_name; };
	inline vector<string>& getsArgs() { return m_sArgs; };
	inline vector<float>& getfArgs() { return m_fArgs; };
private:
	ConsoleCommandName m_name;
	vector<string> m_sArgs;
	vector<float> m_fArgs;
};

class Parser
{
public:
	Parser();
	~Parser();

	ConsoleCommandPtr parseConsole(const string& str);
	ConsoleCommandPtr parseMaterial(const string& str);
	ConsoleCommandPtr parseItem(const string& str);
private:
	string& lowerStr(string& str);
	vector<string> tokenize(const string& str, const string& delim);
};

#endif
