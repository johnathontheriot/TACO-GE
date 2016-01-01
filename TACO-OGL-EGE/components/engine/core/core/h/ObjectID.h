#ifndef OBJECTID_H
#define OBJECTID_H

/**
@author Johnathon Theriot
**/

#include "ID.h"
#include <string>

#include "../../system/h/Response.h"
#include "../../system/defaults/Constants.h"


#include <boost/functional/hash.hpp>




class ObjectID : public ID{
public:

	ObjectID();
	ObjectID(int inscene_id);
	ObjectID(std::string name_id);
	ObjectID(int inscene_id, std::string name_id);

	int getInSceneID() const;
	int getInstanceID() const;
	std::string getNameID() const;

	Response setNameID(std::string newNameID);
	Response setInSceneID(int newInSceneID);

private:

	static int _o_id;

protected:

	int instance_id;
	int inscene_id;
	std::string name_id;

};

struct ObjectIDHasher{
	std::size_t operator()(const ObjectID & oid) const{
		std::size_t s = 0;
		boost::hash_combine(s, boost::hash_value(oid.getInstanceID()));
		boost::hash_combine(s, hash_value(oid.getInSceneID()));
		boost::hash_combine(s, hash_value(oid.getNameID()));
		return s;
	}
};


#endif