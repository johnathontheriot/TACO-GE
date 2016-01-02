#ifndef TEXTURE_ID_RESPONSE_H
#define TEXTURE_ID_RESPONSE_H

#include "Response.h"
#include "../../core/h/Scene.h"
#include <string>

class TextureIDResponse : public Response{
public:
	TextureIDResponse();
	virtual ~TextureIDResponse();
	TextureIDResponse(ResponseType type, std::string shortMessage, std::string longMessage, GLuint * scene);

	GLuint * getTextureID();

private:

protected:
	GLuint * textureID;
};

#endif