#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <unordered_map>
#include <vector>
#include "ShaderInput.h"
#include "Shader.h"
#include "../../system/h/Response.h"

/**
@author Johnathon Theriot
**/


class ShaderProgram{
public:

	Response AddVariable(std::string varName);
	Response RemoveVariable(std::string varName);
	Shader getShader(GLenum shaderType);

private:

protected:
	GLuint id;
	std::unordered_map<std::string, ShaderInput> variables;
	std::vector<Shader> shaders;

};

#endif