/*
 * Parser.cpp
 *
 * @author Joseph Zehe
 *
 */

#include "Parser.h"

ConsoleCommand::ConsoleCommand(ConsoleCommandName name, const vector<string>& sArgs, const vector<float>& fArgs)
: m_name(name), m_sArgs(sArgs), m_fArgs(fArgs)
{
}

ConsoleCommand::ConsoleCommand(ConsoleCommandName name, const vector<string>& sArgs)
: m_name(name), m_sArgs(sArgs)
{
}

ConsoleCommand::ConsoleCommand(ConsoleCommandName name)
: m_name(name)
{
}

ConsoleCommand::~ConsoleCommand()
{
	m_sArgs.clear();
	m_fArgs.clear();
}

Parser::Parser()
{
}

Parser::~Parser()
{
}

string& Parser::lowerStr(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

/*void Parser::lowerVector(vector<string>& vectorStr)
{
	for(vector<string>::iterator it = vectorStr.begin(); it != vectorStr.end(); ++it)
		lowerStr(*it);
}*/

ConsoleCommandPtr Parser::parseConsole(const string& str)
{
	vector<string> tokens = tokenize(str, " ");
	// speicher vom tokens vector sollte wieder freigegeben werden...

	if(!tokens.empty())
	{
		if(tokens.size() >= 1)
			tokens[0] = lowerStr(tokens[0]);
		if(tokens.size() >= 2)
			tokens[1] = lowerStr(tokens[1]);
	}

	if(!tokens.empty())
		switch(tokens.size())
		{
			case 1:
				if(tokens[0] == "help") return new ConsoleCommand(eCmdHelp);
				if(tokens[0] == "exit") return new ConsoleCommand(eCmdExit);
			break;
			case 2:
				if(tokens[0] == "list" && tokens[1] == "materials")
					return new ConsoleCommand(eCmdListMaterials);
				if(tokens[0] == "list" && tokens[1] == "items")
					return new ConsoleCommand(eCmdListItems);
				if(tokens[0] == "list" && tokens[1] == "tools")
					return new ConsoleCommand(eCmdListTools);
			break;
			case 3:
				if(tokens[0] == "remove" && tokens[1] == "material")
				{
					vector<string> v_str = { tokens[2] };
					return new ConsoleCommand(eCmdRemoveMaterial, v_str);
				}
				if(tokens[0] == "remove" && tokens[1] == "item")
				{
					vector<string> v_str = { tokens[2] };
					return new ConsoleCommand(eCmdRemoveItem, v_str);
				}
			break;
			case 4:
				if(tokens[0] == "create" && tokens[1] == "material")
				try
				{
					float d = stof(tokens[3]);
					vector<string> v_str = { tokens[2] };
					vector<float> v_fl = { d };
					return new ConsoleCommand(eCmdCreateMaterial, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
			case 5:
			break;
			case 6:
				if( (tokens[0] == "create" && tokens[1] == "item") && ( lowerStr(tokens[3]) == "sphere") )
				try
				{
					float r = stof(tokens[4]);
					vector<string> v_str = { tokens[2], tokens[5] };
					vector<float> v_fl = { r };
					return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
			case 7:
				if( (tokens[0] == "create" && tokens[1] == "item") && ( lowerStr(tokens[3]) == "cylinder") )
				try
				{
					float r = stof(tokens[4]); float h = stof(tokens[5]);
					vector<string> v_str = { tokens[2], tokens[6] };
					vector<float> v_fl = { r, h };
					return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
			case 8:
				if( (tokens[0] == "create" && tokens[1] == "item") && ( lowerStr(tokens[3]) == "cuboid") )
				try
				{
					float l = stof(tokens[4]); float w = stof(tokens[5]); float h = stof(tokens[6]);
					vector<string> v_str = { tokens[2], tokens[7] };
					vector<float> v_fl = { l, w, h };
					return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
		}

	if(!tokens.empty())
		if( (tokens.size() >= 4) && (tokens[0] == "create" && tokens[1] == "tool") )
		{
			vector<string> v_str = { tokens[2]/*,  tokens[3]*/ };
			//for(vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
			// alle weiteren Elemente einfügen
			for(unsigned int i = 3; i < tokens.size(); ++i)
				v_str.push_back(tokens[i]);//cout << tokens[i] << " " << i << " " << tokens.size() << endl;//v_str[i-2] = tokens[i];
			return new ConsoleCommand(eCmdCreateTool, v_str);
		}

	return new ConsoleCommand(eCmdEmpty);
}

ConsoleCommandPtr Parser::parseMaterial(const string& str)
{
	vector<string> tokens = tokenize(str, " ");
	if(!tokens.empty())
		if(tokens.size() == 2)
			try
			{
				float d = stof(tokens[1]);
				vector<string> v_str = { tokens[0] };
				vector<float> v_fl = { d };
				return new ConsoleCommand(eCmdCreateMaterial, v_str, v_fl);
			}
			catch( ... ) { return new ConsoleCommand(eCmdEmpty); }

	return new ConsoleCommand(eCmdEmpty);
}

ConsoleCommandPtr Parser::parseItem(const string& str)
{
	vector<string> tokens = tokenize(str, " ");

	if(!tokens.empty() && tokens.size() >= 4)
		tokens[1] = lowerStr(tokens[1]);

	if(!tokens.empty())
		switch(tokens.size())
		{
			case 4:
				if(tokens[1] == "sphere")
				try
				{
					float r = stof(tokens[2]);
					vector<string> v_str = { tokens[0], tokens[3] };
					vector<float> v_fl = { r };
					return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
			case 5:
				if(tokens[1] == "cylinder")
				try
				{
					float r = stof(tokens[2]); float h = stof(tokens[3]);
					vector<string> v_str = { tokens[0], tokens[4] };
					vector<float> v_fl = { r, h };
					return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
			case 6:
				if(tokens[1] == "cuboid")
				try
				{
					float l = stof(tokens[2]); float w = stof(tokens[3]); float h = stof(tokens[4]);
					vector<string> v_str = { tokens[0], tokens[5] };
					vector<float> v_fl = { l, w, h };
					return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
				}
				catch( ... ) { break; }
		}
	return new ConsoleCommand(eCmdEmpty);
}

ConsoleCommandPtr Parser::parseTool(const string& str)
{
	vector<string> tokens = tokenize(str, " ");

	if(!tokens.empty() && tokens.size() >= 2)
		return new ConsoleCommand(eCmdCreateTool, tokens);

	//~ if(!tokens.empty())
		//~ for(i=0; i<tokens.size(); ++i)
		//~ {
//~
		//~ }
	return new ConsoleCommand(eCmdEmpty);
}

/*MaterialPtr Parser::parseMaterial(const string& str)
{
	vector<string> tokens = tokenize(str, " ");
	if(tokens.size() == 2)
		return createMaterial(tokens[0], tokens[1]);
	return 0;
}

MaterialPtr Parser::createMaterial(const string& sName, string sDensity)
{
	try
	{
		float fDensity = stof(sDensity);
		return new Material(sName, fDensity);
	}
	catch( ... ) { return 0; }
}

ItemPtr Parser::parseItem(const string& str)
{
	vector<string> tokens = tokenize(str, " ");
	if(tokens.size() >= 4 && tokens.size() <= 6)
		return spezifyItem(tokens);
	return 0;
}

ItemPtr Parser::spezifyItem(vector<string> tokens)
{
	switch(tokens.size())
	{
		case 4:
			if(tokens[3] == "cylinder")
				createItem(sName, new Cylinder())
		break;
		case 5:
		break;
		case 6:
	}
}

ItemPtr Parser::createItem(const string& sName, ShapePtr p_shape, const string& sMaterial)
{
	try
	{
		float l = stof(tokens[4]);
		float w = stof(tokens[5]);
		float h = stof(tokens[6]);
		vector<string> v_str = { tokens[2], tokens[7] };
		vector<float> v_fl = { l, w, h };
		return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
	}
	catch( ... ) { break; }
}*/

// TODO: Bei Anführungszeichen soll nicht getrennt werden!
vector<string> Parser::tokenize(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t p0 = 0, p1 = string::npos;

	while(p0 != string::npos)
	{
		p1 = str.find_first_of(delim, p0);
		if(p1 != p0)
		{
			string token = str.substr(p0, p1 - p0);
			tokens.push_back(token);
		}
		p0 = str.find_first_not_of(delim, p1);
	}
	return tokens;
}
