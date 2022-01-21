#ifndef _OBJECT_
#define _OBJECT_

class Object;
#include "Value.h"
#include "MyBool.h"
#include "TmpObject.h"

#include <map>
#include <functional>

class Object {
private:

public:
	std::map<std::string, Value> map;

    Object();
    Object(char reset_alpha);

	Object operator[](const Object& obj);
    Object operator[](const TmpObject& obj);
    Value& operator[](const char* str);
};


#endif
