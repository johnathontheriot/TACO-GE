#ifndef CONSTANTS_H
#define CONSTANTS_H

/**
@author Johnathon Theriot
**/

using namespace std;

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm-0.9.6.3\glm\glm\glm.hpp>
#include <glm-0.9.6.3\glm\glm\gtc\matrix_transform.hpp>
#include <string>
#include <unordered_map>

/**
---------------------------  D E F I N I T I O N S  ------------------------------------

MONOSCOPIC:
Used for toggling stereoscopic display if available.

----------------------------------------------------------------------------------------
**/
namespace{

#define MONOSCOPIC

	/**
	----------------------------  C O N S T A N T S  ---------------------------------------

	----------------------------------------------------------------------------------------
	**/

	const int RESTART = 0xFFFF;
	const int X = 0;
	const int Y = 1;
	const int Z = 2;

	/**
	----------------------------  G L O B A L S  -------------------------------------------

	----------------------------------------------------------------------------------------
	**/

	int W;
	int H;

	const std::string user_system_directory = "usr/system";
	const std::string default_system_directory = "components/engine/core/system/defaults";

	std::unordered_map<std::string, GLenum> GLenum_map({
		{ "GLUT_STEREO", GLUT_STEREO },
		{ "GLUT_RGBA", GLUT_RGBA },
		{ "GLUT_DOUBLE", GLUT_DOUBLE },
		{ "GLUT_DEPTH", GLUT_DEPTH },
		{ "GL_BLEND", GL_BLEND },
		{ "GL_PRIMITIVE_RESTART", GL_PRIMITIVE_RESTART },
		{ "GL_DEPTH_TEST", GL_DEPTH_TEST }
	});

	int MaxTextureUnits; 
	std::unordered_map<std::string, GLenum> * textureUnits;
}
#endif