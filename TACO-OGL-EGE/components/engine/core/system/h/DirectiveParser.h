#ifndef DIRECTIVE_PARSER_H
#define DIRECTIVE_PARSER_H

/**
@author Johnathon Theriot

A library to parse the user's .dirc file
for information on the glut display, enable, etc
options for the instance.

johnathontheriot
**/


#include "../h/Response.h"


class DirectiveParser{
public:

	static Response Parse();
	
private:


protected:
	static Response parse_display(std::ifstream & directive_file);
	static Response parse_enable(std::ifstream & directive_file);
	static Response parse_dimensions(std::ifstream & directive_file);
	static Response parse_file(std::ifstream & directive_file);
	static Response parse_tag(std::string tag, std::ifstream & directive_file);
	static Response user_defined();

};


#endif