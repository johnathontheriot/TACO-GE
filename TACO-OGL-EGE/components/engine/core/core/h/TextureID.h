#ifndef TEXTURE_ID_H
#define TEXTURE_ID_H

#include "ID.h"
#include <string>

#include "../../system/h/Response.h"
#include "../../system/defaults/Constants.h"
#include <boost/functional/hash.hpp>
#include "../../system/h/TextureIDResponse.h"


class TextureID : public ID{
public:

	static Response create(std::string filePath);
	GLenum getInstanceID() const;
	std::string getPath() const;
	GLuint getTexID() const;
	int getIntInstanceID() const;

	friend std::ostream& operator<<(std::ostream& os, const TextureID & sceneid);
	//overload operators

private:
	static int _ti_id;
	
	TextureID();
	TextureID(std::string name_id);

	TextureIDResponse load_image(std::string filepath);
	TextureIDResponse load_bmp(std::string filepath, FILE * file);
	TextureIDResponse load_jpg(std::string filepath, FILE * file);
	TextureIDResponse load_ppm(std::string filepath, FILE * file);
	TextureIDResponse load_gif(std::string filepath, FILE * file);
	TextureIDResponse load_png(std::string filepath, FILE * file);

protected:

	GLenum instance_id = -1;
	int int_instance_id = -1;
	std::string filepath_id = "";
	GLuint texID = -1;

};

struct TextureIDHasher{
	std::size_t operator()(const TextureID & sid) const{
		std::size_t s = 0;
		boost::hash_combine(s, boost::hash_value(sid.getIntInstanceID()));
		boost::hash_combine(s, boost::hash_value(sid.getPath()));
		boost::hash_combine(s, boost::hash_value(sid.getTexID()));
		return s;
	}


};

struct TextureIDEq
{
public:
	bool operator() (TextureID const& t1, TextureID const& t2) const
	{
		return t1.getIntInstanceID() == t2.getIntInstanceID();
	}
};


#endif