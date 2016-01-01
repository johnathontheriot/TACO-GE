#ifndef SCENE_ID_H
#define SCENE_ID_H

#include "ID.h"
#include <string>

#include "../../system/h/Response.h"
#include "../../system/defaults/Constants.h"
#include <boost/functional/hash.hpp>

class SceneID : public ID{
public:

	SceneID(){};
	SceneID(std::string name_id){};
	SceneID(int id, std::string name_id){};


	int getInstanceID() const{return this->getInstanceID();};
	std::string getNameID() const { return this->getNameID(); };
	Response setNameID(std::string newNameID){ return Response(); };
	friend std::ostream& operator<<(std::ostream& os, const SceneID & sceneid){ return os; };
	//overload operators

private:

	static int _s_id;

protected:

	int instance_id;
	std::string name_id;

};

struct SceneIDHasher{
	std::size_t operator()(const SceneID & sid) const{
		std::size_t s = 0;
		boost::hash_combine(s, boost::hash_value(sid.getInstanceID()));
		boost::hash_combine(s, hash_value(sid.getNameID()));
		return s;
	}


};

struct SceneIDEq
{
public:
	bool operator() (SceneID const& t1, SceneID const& t2) const
	{
		return t1.getInstanceID() == t2.getInstanceID();
	}
};


#endif