#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <string>
#include <unordered_map>
#include "ID.h"
#include "Scene.h"
#include "../../system/h/SceneResponse.h"
#include "../../system/h/Response.h"
#include "../../system/defaults/Constants.h"
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
//singleton
class SceneManager{
public:

	static SceneManager * getInstance();
	SceneResponse getScene(Scene id);
	SceneResponse getScene(int id);
	SceneResponse getScene(std::string id);
	SceneResponse addScene(std::string scene_name);
	SceneResponse updateScene(Scene oldID, Scene * updatedScene);
	SceneResponse updateScene(int oldID, Scene * updatedScene);
	SceneResponse updateScene(std::string oldID, Scene * updatedScene);

	void listScenes();

private:

	SceneManager();

protected:
	typedef boost::multi_index_container<
		Scene*,
		boost::multi_index::indexed_by<
			boost::multi_index::hashed_non_unique<
				boost::multi_index::member<
					Scene, std::string, &Scene::name_id
				>
			>, 
			boost::multi_index::hashed_non_unique<
				boost::multi_index::member<
					Scene, int, &Scene::instance_id
				>
			>
		>
	> MultiSceneManager;

	MultiSceneManager * scenes;
};

#endif