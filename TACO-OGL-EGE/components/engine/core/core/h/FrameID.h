#ifndef FRAME_ID_H
#define FRAME_ID_H

#include "ID.h"
#include <boost/functional/hash.hpp>

//not well defined

class FrameID : public ID{
public:
	FrameID();
	int getInstanceID() const;
	std::string getNameID() const;
private:
	static int _f_id;
protected:
	int instance_id;
	std::string name_id;

};


struct FrameIDHasher{
	std::size_t operator()(const FrameID & fid) const{
		std::size_t s = 0;
		boost::hash_combine(s, boost::hash_value(fid.getInstanceID()));
		boost::hash_combine(s, boost::hash_value(fid.getNameID()));
		return s;
	}
};

#endif