#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <string>
#include <unordered_map>
#include "ID.h"
#include "SceneID.h"
#include "Scene.h"
#include "../../system/h/SceneResponse.h"
#include "../../system/h/Response.h"
#include "../../system/defaults/Constants.h"


//singleton
class SceneManager{
public:

	static SceneManager getInstance();
	SceneResponse getScene(SceneID id);
	SceneResponse getScene(int id);
	SceneResponse getScene(std::string id);
	SceneResponse addScene(Scene * Scene);
	SceneResponse updateScene(SceneID oldID, Scene * updatedScene);
	SceneResponse updateScene(int oldID, Scene * updatedScene);
	SceneResponse updateScene(std::string oldID, Scene * updatedScene);

	void listScenes();

private:

	SceneManager();

protected:

	std::unordered_map<SceneID, Scene*, SceneIDHasher, SceneIDEq> * scenes;
};

#endif