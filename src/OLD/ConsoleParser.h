/*
 * ConsoleParser.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef CONSOLEPARSER_H
#define CONSOLEPARSER_H

#include <string>
#include <vector>

#include "Item.h"

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

	inline ~ConsoleCommand() { m_sArgs.clear(); m_fArgs.clear(); };
	inline ConsoleCommandName getName() { return m_name; };
	inline vector<string>& getsArgs() { return m_sArgs; };
	inline vector<float>& getfArgs() { return m_fArgs; };
private:
	ConsoleCommandName m_name;
	vector<string> m_sArgs;
	vector<float> m_fArgs;
};

class ConsoleParser
{
public:
	ConsoleParser();
	~ConsoleParser();

	ConsoleCommandPtr parse(const string& str);

private:
	vector<string> tokenize(const string& str, const string& delim);
};

#endif
