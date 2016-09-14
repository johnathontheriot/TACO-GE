#include "../h/SceneManager.h"
#include <unordered_map>

#include <ostream>
#include <iostream>

SceneManager::SceneManager(){
	scenes = new MultiSceneManager();
}

SceneManager * SceneManager::getInstance(){
	static SceneManager * instance = new SceneManager();
	return instance;
}

SceneResponse SceneManager::getScene(Scene id){
	auto &instance_id = this->scenes->get<1>();
	auto it = instance_id.find(id.getInstanceID());
	if (it != instance_id.end()){
		return SceneResponse(VALID, "Scene found.", "Scene with name \"" + id.getNameID() + "\" and id " + std::to_string(id.getInstanceID()) + " found.", *it);
	}
	else {
		return SceneResponse(INVALID, "Scene not found.", "Scene with name \"" + id.getNameID() + "\" and id " + std::to_string(id.getInstanceID()) + " not found.", NULL);
	}
}

SceneResponse SceneManager::getScene(int iid){
	auto &instance_id = this->scenes->get<1>();
	auto it = instance_id.find(iid);
	if (it != instance_id.end()){
		return SceneResponse(VALID, "Scene found.", "Scene with id " + std::to_string(iid) + " found.", *it);
	}
	else {
		return SceneResponse(INVALID, "Scene not found.", "Scene with id " + std::to_string(iid) + " not found.", NULL);
	}
}
 
SceneResponse SceneManager::getScene(std::string sid){
	auto &instance_id = this->scenes->get<0>();
 	auto it = instance_id.find(sid);
	if (it != this->scenes->end()){
		return SceneResponse(VALID, "Scene found.", "Scene with name \"" + sid + "\" found.", *it);
	}
	else {
		return SceneResponse(INVALID, "Scene not found.", "Scene with name \"" + sid + "\" not found.", NULL);
	}
}

void SceneManager::listScenes(){
	auto it = this->scenes->begin();
	cout << "- - - - - - Scene List - - - - -" << endl;
	cout << "- - - ( intID : stringID ) - - -" << endl;
	if (this->scenes->size() == 0){
		cout << "There are currently no Scenes." << endl << "- - - - - - - - - - - - - - -" << endl << endl;
		return;
	}
	for (it; it != this->scenes->end(); it++){
		cout << std::to_string((*it)->getInstanceID()) << " : " << (*it)->getNameID() << endl;
		cout << "- - - - - - - - - - - - - - -" << endl;
	}
	cout << endl;
}

SceneResponse SceneManager::addScene(std::string sceneName){
	SceneResponse found = this->getScene(0);
	if (found.getID() != INVALID){
		return SceneResponse(INVALID, "Scene already exists.", "Scene with name " + sceneName + " already exists", found.getScene());
	}
	Scene * newScene = new Scene(sceneName);
	this->scenes->insert(newScene);
	return SceneResponse(VALID, "Scene created.", "Scene with name " + sceneName + " was created.", newScene);
}