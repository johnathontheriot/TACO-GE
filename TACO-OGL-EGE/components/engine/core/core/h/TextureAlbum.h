#ifndef TEXTURE_ALBUM_H
#define TEXTURE_ALBUM_H

#include "../h/Texture.h"
#include "../../system/h/TextureIDResponse.h"
#include <unordered_map>
#include <string>

class TextureAlbum{
public:
	static TextureAlbum getInstance();

private:
	TextureAlbum();
protected:
	std::unordered_map<std::string, Texture*> * scenes;

};

#endif


/**
should be called to add an image. Add image should
check if the image was previously loaded, then if so return the GLuint with the response.

It should also be used to track the textures that are loaded
with a map from the file path to the actual texture
**/