/*
 * ConsoleParser.cpp
 *
 * @author Joseph Zehe
 *
 */

#include "ConsoleParser.h"

#include "Item.h"
#include "Shape.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cuboid.h"
#include "Material.h"

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
}

ConsoleParser::ConsoleParser()
{
}

ConsoleParser::~ConsoleParser()
{
}

ConsoleCommandPtr ConsoleParser::parse(const string& str)
{
	vector<string> tokens = tokenize(str, " ");
	// speicher vom tokens vector sollte wieder freigegeben werden...

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
					// else
					vector<string> v_str = { tokens[2] };
					vector<float> v_fl = { d };
					return new ConsoleCommand(eCmdCreateMaterial, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
			case 5:
			break;
			case 6:
				if( (tokens[0] == "create" && tokens[1] == "item") && ( tokens[3] == "sphere") )
				try
				{
					float r = stof(tokens[4]);
					// else
					vector<string> v_str = { tokens[2], tokens[5] };
					vector<float> v_fl = { r };
					return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
			case 7:
				if( (tokens[0] == "create" && tokens[1] == "item") && ( tokens[3] == "cylinder") )
				try
				{
					float r = stof(tokens[4]); float h = stof(tokens[5]);
					// else
					vector<string> v_str = { tokens[2], tokens[6] };
					vector<float> v_fl = { r, h };
					return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
			case 8:
				if( (tokens[0] == "create" && tokens[1] == "item") && ( tokens[3] == "cuboid") )
				try
				{
					float l = stof(tokens[4]); float w = stof(tokens[5]); float h = stof(tokens[6]);
					// else
					vector<string> v_str = { tokens[2], tokens[7] };
					vector<float> v_fl = { l, w, h };
					return new ConsoleCommand(eCmdCreateItem, v_str, v_fl);
				}
				catch( ... ) { break; }
			break;
		}
	return new ConsoleCommand(eCmdEmpty);
}

// TODO: Bei Anführungszeichen soll nicht getrennt werden!
vector<string> ConsoleParser::tokenize(const string& str, const string& delim)
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
