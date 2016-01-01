#include "../h/Scene.h"
#include "../h/SceneID.h"
#include "../h/SceneManager.h"
#include "../h/FrameID.h"

Scene::Scene(){
	this->id = new SceneID();
	this->renderFrames = new std::unordered_map<FrameID, FrameBuffer*, FrameIDHasher>();
	//create framebuffer and add it to the renderFrames
	SceneManager::getInstance().addScene(this);
}

Scene::Scene(std::string name){
	this->id = new SceneID(name);
	this->renderFrames = new std::unordered_map<FrameID, FrameBuffer*, FrameIDHasher>();
	//create framebuffer and add it to the renderFrames
	SceneManager::getInstance().addScene(this);
}

Response Scene::AddObject(GLobject * object){
	if (!this->objects){
		this->objects = new std::unordered_map<ObjectID, GLobject*, ObjectIDHasher>();
		return Response();
	}
	//change here for adding the object
	return Response();
}
