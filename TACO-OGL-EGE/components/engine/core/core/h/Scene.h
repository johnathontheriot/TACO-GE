#ifndef SCENE_H
#define SCENE_H

/**
@author Johnathon Theriot
**/

#include <unordered_map>
#include <vector>
#include <string>
#include "GLobject.h"
#include "SceneID.h"
#include "ObjectID.h"
#include "FrameID.h"
#include "../../system/h/Response.h"
#include "../../system/defaults/Constants.h"
#include "FrameBuffer.h"

class Scene{
public:

	Scene();
	Scene(std::string name);
	Response AddObject(GLobject * object);



private:

protected:
	SceneID * id;
	std::unordered_map<ObjectID, GLobject*, ObjectIDHasher> * objects;
	std::unordered_map<FrameID, FrameBuffer*, FrameIDHasher> * renderFrames;

};


#endif