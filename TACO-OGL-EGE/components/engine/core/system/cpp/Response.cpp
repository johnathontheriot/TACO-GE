#include "../h/Response.h"

using namespace std;



Response::Response(ResponseType T, std::string S, std::string C){
	this->response_id = T;
	this->simple_message = S;
	this->complex_message = C;
}

Response::~Response(){
}

ResponseType Response::getID(){
	return this->response_id;
}

std::string Response::getSimpleMessage(){
	return this->simple_message;
}

std::string Response::getComplexMessage(){
	return this->complex_message;
}