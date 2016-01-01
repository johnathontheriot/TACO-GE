#include "../h/SceneResponse.h"
#include "../../core/h/Scene.h"

SceneResponse::SceneResponse(ResponseType type, std::string shortMessage, std::string longMessage, Scene * scene) : Response(type, shortMessage, longMessage){
	this->scene = scene;
}

SceneResponse::~SceneResponse(){
}

Scene * SceneResponse::getScene(){
	return this->scene;
}
