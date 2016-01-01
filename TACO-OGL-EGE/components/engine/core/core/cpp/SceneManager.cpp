#include "../h/SceneManager.h"
#include "../h/SceneID.h"
#include <unordered_map>

#include <ostream>
#include <iostream>

SceneManager::SceneManager(){
	scenes = new unordered_map<SceneID, Scene*, SceneIDHasher, SceneIDEq>();
}

SceneManager SceneManager::getInstance(){
	static SceneManager instance;
	return instance;
}

SceneResponse SceneManager::getScene(SceneID id){
	std::unordered_map<SceneID, Scene*, SceneIDHasher, SceneIDEq>::const_iterator it = (this->scenes)->find(id);
	if (it == this->scenes->end()){
		return SceneResponse(INVALID, "Scene not found", "Scene " + std::to_string(id.getInstanceID()) + ": " + id.getNameID() + " is not a valid Scene.\n\n", NULL);
	}
	return SceneResponse(VALID, std::to_string(id.getInstanceID()), id.getNameID(), it->second);
}

SceneResponse SceneManager::getScene(int iid){
	SceneID id(iid, "");
	std::unordered_map<SceneID, Scene*, SceneIDHasher, SceneIDEq>::const_iterator it = (this->scenes)->find(id);
	if (it == this->scenes->end()){
		return SceneResponse(INVALID, "Scene not found", "Scene " + std::to_string(id.getInstanceID()) + ": " + id.getNameID() + " is not a valid Scene.\n\n", NULL);
	}
	return SceneResponse(VALID, std::to_string(id.getInstanceID()), id.getNameID(), it->second);
}

SceneResponse SceneManager::getScene(std::string sid){
	SceneID id(-1, sid);
	std::unordered_map<SceneID, Scene*, SceneIDHasher, SceneIDEq>::const_iterator it = (this->scenes)->find(id);
	if (it == this->scenes->end()){
		return SceneResponse(INVALID, "Scene not found", "Scene " + std::to_string(id.getInstanceID()) + ": " + id.getNameID() + " is not a valid Scene.\n\n", NULL);
	}
	return SceneResponse(VALID, std::to_string(id.getInstanceID()), id.getNameID(), it->second);
}

void SceneManager::listScenes(){
	std::unordered_map<SceneID, Scene*, SceneIDHasher, SceneIDEq>::const_iterator it;
	cout << "- - - - - - Scene List - - - - -" << endl;
	cout << "- - - ( intID : stringID ) - - -" << endl;
	if (this->scenes->size() == 0){
		cout << "There are currently no Scenes." << "- - - - - - - - - - - - - - -" << endl << endl;
		return;
	}
	for (it = this->scenes->begin(); it != this->scenes->end(); it++){
		cout << it->first << endl;
		cout << "- - - - - - - - - - - - - - -" << endl;
	}
	cout << endl;
}

SceneResponse SceneManager::addScene(Scene * Scene){
	return SceneResponse();
}

SceneResponse SceneManager::updateScene(SceneID oldID, Scene * updatedScene){
	return SceneResponse();
}