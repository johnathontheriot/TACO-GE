#ifndef SCENE_H
#define SCENE_H

/**
@author Johnathon Theriot
**/

#include <unordered_map>
#include <vector>
#include <string>
#include "GLobject.h"
#include "ObjectID.h"
#include "FrameID.h"
#include "../../system/h/Response.h"
#include "../../system/defaults/Constants.h"
#include "FrameBuffer.h"

class Scene{
public:

	Response AddObject(GLobject * object);
	int getInstanceID() const{ return this->instance_id; };
	std::string getNameID() const { return this->name_id; };
	Response setNameID(std::string newNameID){ return Response(); };
	friend std::ostream& operator<<(std::ostream& os, const Scene & sceneid){ return os; };
	bool operator==(Scene & other) const {
		return this->getNameID() == other.getNameID();
	}
	friend class SceneManager;
private:
	static int _s_id;
	Scene();
	Scene(std::string name_id);
	Scene(int id, std::string name_id);
protected:
	friend class SceneManager;
	std::unordered_map<ObjectID, GLobject*, ObjectIDHasher> * objects;
	std::unordered_map<FrameID, FrameBuffer*, FrameIDHasher> * renderFrames;
	int instance_id;
	std::string name_id;
};


#endif