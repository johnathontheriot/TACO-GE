#ifndef SCENE_RESPONSE_H
#define SCENE_RESPONSE_H

#include "Response.h"
#include "../../core/h/Scene.h"
#include <string>

class SceneResponse : public Response{
public:
	SceneResponse(){};
	virtual ~SceneResponse();
	SceneResponse(ResponseType type, std::string shortMessage, std::string longMessage, Scene * scene);

	Scene * getScene();

private:

protected:
	Scene * scene;
};

#endif