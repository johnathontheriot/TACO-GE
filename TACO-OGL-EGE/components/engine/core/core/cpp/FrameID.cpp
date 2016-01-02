#include "../h/FrameID.h"

int FrameID::_f_id = 0;

FrameID::FrameID() : ID(){
	instance_id = _f_id;
	_f_id++;
}

int FrameID::getInstanceID() const{
	return this->instance_id;
}

std::string FrameID::getNameID() const{
	return this->name_id;
}