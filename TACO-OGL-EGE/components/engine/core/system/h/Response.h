#ifndef RESPONSE_H
#define RESPONSE_H

/*
---------------------------  I N C L U D E S  ------------------------------------------

---------------------------------------------------------------------------------------
*/

#include <string>


/**
@author Johnathon Theriot

A library to represent the resoponse
required for the engine actions.

johnathontheriot
**/

using namespace std;

typedef enum{
	VALID = 0,	//A valid Response
	INVALID,	//An invalid Response
	UNDEFINED	//An undetermined Response
} ResponseType;

class Response{
public:
	/**
		Parameterized constructor
		Accepts the type, a simple message, and a complex message,
		all optional.

		@params:
			type : ResponseType. UNDEFINED, VALID, or INVALID; default UNDEFINED.
			simpleMessage: std::string. A simple message for the response; default empty string.
			complexMessage: std::string. A define message for the response; default empty string.
	**/
	Response(ResponseType type = UNDEFINED, std::string simpleMesage = "", std::string complexMessage = "");

	/**
	Destructor for the Response.
	**/
	virtual ~Response();

	/**
	@return: the ResponseType of the Response; Note ResponseType
	indexed at 0.
	**/
	ResponseType getID();

	/**
	@return: the simple message for the response.
	**/
	std::string getSimpleMessage();

	/**
	@return: a more defined message for the response.
	**/
	std::string getComplexMessage();
private:
protected:
	/**
	The simple message describing the response.
	**/
	string simple_message;

	/**
	The complex message describing the response.
	**/
	string complex_message;

	/**
	The id type for the response.
	**/
	ResponseType response_id;
};


#endif