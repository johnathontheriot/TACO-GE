#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include "../../system/h/Response.h"


/**
@author Johnathon Theriot
**/


class Shader{

public:

	Response HasVariable(std::string varName);

private:

protected:

	char * filename;
	GLenum type;
	std::vector<std::string> variables;

};

#endif