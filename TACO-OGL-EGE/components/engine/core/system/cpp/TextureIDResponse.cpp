#include "../h/TextureIDResponse.h"
#include "../../core/h/Scene.h"

TextureIDResponse::TextureIDResponse(){

}

TextureIDResponse::TextureIDResponse(ResponseType type, std::string shortMessage, std::string longMessage, GLuint * textureID) : Response(type, shortMessage, longMessage){
	this->textureID = textureID;
}

TextureIDResponse::~TextureIDResponse(){
}

GLuint * TextureIDResponse::getTextureID(){
	return this->textureID;
}
