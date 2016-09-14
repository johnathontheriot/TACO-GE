#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <GL/freeglut.h>


class FrameBuffer{
public:
	FrameBuffer(){};
private:

protected:
	/**
	GL_FRAMEBUFFER, GL_READ_FRAMEBUFFER, or GL_DRAW_FRAMEBUFFER
	**/
	GLenum frameType;
	/**
	The frame id
	**/
	GLuint frameID;
	/**
	Textures for the frame to render to, if applicable
	otherwise, null.
	**/
};

#endif 