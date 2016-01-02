#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../../system/defaults/Constants.h"

class Texture{
public:

	Texture();
	Texture(std::string filepath);
	std::string getFileName();
	GLuint getTexID();
	GLenum getTexEnum();
	void bind();

private:

protected:
	
	std::string filepath;
	GLuint texID;
	GLenum texEnum;

};

#endif