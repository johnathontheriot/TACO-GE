#include <string>
#include "../../system/h/Response.h"
#include "../../system/defaults/Constants.h"
#include <boost/functional/hash.hpp>
#include "../h/TextureID.h"
#include "../../system/h/TextureIDResponse.h"


int TextureID::_ti_id = 0;

TextureID::TextureID(){
	//should never be called without a file
}

TextureID::TextureID(std::string filePath){
	if (_ti_id < MaxTextureUnits){
		TextureIDResponse re = load_image(filePath);
		if (re.getID() == INVALID){
			this->filepath_id = re.getComplexMessage();
		}
		else{
			this->filepath_id = filePath;
			this->instance_id = _ti_id;
			this->texID = *re.getTextureID();
			_ti_id++;
		}
	}
}

Response TextureID::create(std::string filepath){
	TextureID tex(filepath);
	if (tex.getTexID() < 0){
		return Response(INVALID, filepath, tex.getPath());
	}
	return Response(VALID, "", "");
}

GLenum TextureID::getInstanceID() const{
	return this->instance_id;
}

std::string TextureID::getPath() const{
	return this->filepath_id;
}

GLuint TextureID::getTexID() const{
	return this->texID;
}

int TextureID::getIntInstanceID() const{
	return this->int_instance_id;
}


TextureIDResponse TextureID::load_bmp(std::string filepath, FILE * file){
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int width, height;
	unsigned int imageSize;
	unsigned char * data;

	if (fread(header, 1, 54, file) != 54){
		return TextureIDResponse(INVALID, "Incorrect BMP format\n", "File found at path:\n\tusr/textures/" + filepath + "has invalid header format. Invalid length.\n\n", NULL);

	}
	if (header[0] != 'B' || header[1] != 'M'){
		return TextureIDResponse(INVALID, "Incorrect BMP format\n", "File found at path:\n\tusr/textures/" + filepath + "has invalid header format. Lacking \"BM\" intro.\n\n", NULL);
	}
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	if (imageSize == 0)
		imageSize = width*height * 3;
	if (dataPos == 0)
		dataPos = 54;
	data = new unsigned char[imageSize];
	fread(data, 1, imageSize, file);
	fclose(file);
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return TextureIDResponse(VALID, "Image Loaded\n", "File found at path:\n\tusr/textures/" + filepath + "has been loaded.\nDimensions W = " + std::to_string(width) + " H = " + std::to_string(height) + "\n\n", &textureID);

}


TextureIDResponse TextureID::load_image(std::string filepath){



	FILE * file = fopen(("usr/textures/" + filepath).c_str(), "rb");
	if (!file){
		return TextureIDResponse(INVALID, "Image not found\n", "Image not found at path:\n\tusr/textures/" + filepath + "\n\n", NULL);
	}
	int extPosition = filepath.find('.');
	std::string extension = filepath.substr(extPosition + 1);
	if (extension.compare(".bmp") == 0){
		return load_bmp(filepath, file);
	}
	else{
		return TextureIDResponse(INVALID, "Image type not supported\n", "Image at path:\n\tusr/textures/" + filepath + "not supported.\n\n", NULL);
	}
	//extend this to parse the other image types


}
