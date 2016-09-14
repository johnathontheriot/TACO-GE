 #ifndef GEOMETRY_H
#define GEOMETRY_H

/**
@author Johnathon Theriot
**/

#include "BufferObject.h"
#include <unordered_map>

typedef enum{VERTEX, INDEX, NORMAL, TANGENT, BITANGENT} GeometryAttribute;

class Geometry{
public:

private:

protected:

	float * vertex_list;
	int * index_list;
	float * normal_list;
	float * tangent_list;
	float * bitangent_list; 
	std::unordered_map<GeometryAttribute, BufferObject *> buffers;
};

#endif