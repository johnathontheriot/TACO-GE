#include "../h/DirectiveParser.h"
#include "../h/Response.h"
#include "../defaults/Constants.h"
#include <iostream>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>
#include <GL/freeglut.h>


using namespace boost::filesystem;

Response DirectiveParser::user_defined(){
	path p(user_system_directory);
	try{
		std::vector<directory_entry> entries;
		if (exists(p) && is_directory(p)){
			copy(directory_iterator(p), directory_iterator(), back_inserter(entries));
			for (std::vector<directory_entry>::const_iterator it = entries.begin(); it != entries.end(); it++){
				if (((*it).path().extension().string()).compare(".dirc") == 0){
					return Response(VALID, (*it).path().string(), "");
				}
			}
		}
		else{
			return Response(INVALID, "Error reading from file system\n", "Error reading from file system at:\n\t" + user_system_directory + "\n\n");
		}
		return Response(INVALID, "nOT Found", "");

	}
	catch (const filesystem_error & ex){
		return Response(INVALID, "Error reading from file system\n", "Error reading from file system in:\n\tDirectiveParser::user_defined()\n\n");
	}


}

Response DirectiveParser::parse_display(std::ifstream & directive_file){
	char token;
	string data = "";
	std::vector<string> enums;
	bool block = true;
	directive_file.get(token);
	while (token != EOF && block){
		switch (token){
		case '}':
			enums.push_back(data);
			data = "";
			block = false;
			break;
		case ' ':
		case '\t':
		case '\n':
			directive_file.get(token);
			break;
		case ',':
			enums.push_back(data);
			data = "";
			directive_file.get(token);
			break;
		default:
			data = data + token;
			directive_file.get(token);
			break;
		}
	}
	if (token == EOF){
		return Response(INVALID, "End of file reached\n", "Error, end of file reached before finished parsing.\nCould result from improper syntax.\n\n");
	}
	else if(enums.size() > 0){
		unsigned int displayMode = GLenum_map.at(enums.at(0));
		for (int i = 0; i < enums.size(); i++){
			if (GLenum_map.find(enums.at(i)) != GLenum_map.end()){
				displayMode = displayMode | GLenum_map.at(enums.at(i));
			}
			else{
				return Response(INVALID, "", "");
			}
		}
		glutInitDisplayMode(displayMode);
		return Response(INVALID, "Display modes set", "");

	}

}

Response DirectiveParser::parse_dimensions(std::ifstream & directive_file){
	char token;
	string data = "";
	std::vector<string> dims;
	bool block = true;
	directive_file.get(token);
	while (token != EOF && block){
		switch (token){
		case '}':
			dims.push_back(data);
			data = "";
			block = false;
			break;
		case ' ':
		case '\t':
		case '\n':
			directive_file.get(token);
			break;
		case ',':
			dims.push_back(data);
			data = "";
			directive_file.get(token);
			break;
		default:
			data = data + token;
			directive_file.get(token);
			break;
		}
	}
	if (token == EOF){
		return Response(INVALID, "End of file reached\n", "Error, end of file reached before finished parsing.\nCould result from improper syntax.\n\n");
	}
	else if (dims.size() == 2){
		W = stoi(dims.at(0));
		H = stoi(dims.at(1));
		return Response(VALID, "Dimensions changed.\n", "Dimesions changed to:\n\tW: " + to_string(W) + "\nH: " + to_string(H) + "\n\n");

	}
	else{
		return Response(INVALID, "", "");
	}

}

Response DirectiveParser::parse_enable(std::ifstream & directive_file){
	char token;
	string data = "";
	std::vector<string> enums;
	bool block = true;
	directive_file.get(token);
	while (token != EOF && block){
		switch (token){
		case '}':
			enums.push_back(data);
			data = "";
			block = false;
			break;
		case ' ':
		case '\t':
		case '\n':
			directive_file.get(token);
			break;
		case ',':
			enums.push_back(data);
			data = "";
			directive_file.get(token);
			break;
		default:
			data = data + token;
			directive_file.get(token);
			break;
		}
	}
	if (token == EOF){
		return Response(INVALID, "End of file reached\n", "Error, end of file reached before finished parsing.\nCould result from improper syntax.\n\n");
	}
	else if (enums.size() > 0){
		unsigned int displayMode = GLenum_map.at(enums.at(0));
		for (int i = 0; i < enums.size(); i++){
			if (GLenum_map.find(enums.at(i)) != GLenum_map.end()){
				glEnable(GLenum_map.at(enums.at(i)));
			}
			else{
				return Response(INVALID, "", "");
			}
		}
		return Response(VALID, "", "");

	}

}

Response DirectiveParser::parse_tag(std::string tag, std::ifstream & directive_file){
	if (tag.compare("display") == 0){
		return parse_display(directive_file);
	}
	else if (tag.compare("enable") == 0){
		return parse_enable(directive_file);
	}
	else if (tag.compare("dimensions") == 0){
		return parse_dimensions(directive_file);
	}
	else{
		return Response(INVALID, "", "");
	}
}


Response DirectiveParser::parse_file(std::ifstream & directive_file){
	string tag = "";
	char token;
	directive_file.get(token);
	Response tag_res;
	while (!directive_file.eof() && token != EOF){
		cout << token;
		switch (token){
		case ' ':
		case '\t':
		case '\n':
			break;
		case '{':
			tag_res = parse_tag(tag, directive_file);
			tag = "";
			//check response exit if necessary

			break;
		default:
			tag = tag + token;
			break;
		}
		directive_file.get(token);

	}
	return tag_res;
}

Response DirectiveParser::Parse(){
	Response user_def_res = user_defined();
	if (user_def_res.getID() == INVALID){
		std::ifstream directive_file(default_system_directory + "/default.dirc");
		if (directive_file.good()){
			parse_file(directive_file);
		}
		else{
			return Response(INVALID, "No directive file.", "No user defined directive file was found in:\n\t" + user_system_directory + "\nNor was a default found at:\n\t" + default_system_directory + "\n\n");
		}
	}
	else{
		std::ifstream directive_file(user_def_res.getSimpleMessage());
		if (directive_file.good()){
			return parse_file(directive_file);
		}
		else{
			return Response(INVALID, "Error loading directive file.", "No user defined directive file was found in:\n\t" + user_system_directory + "\nThere was an error loading the default at:\n\t" + default_system_directory + "\n\n");
		}
	}
}