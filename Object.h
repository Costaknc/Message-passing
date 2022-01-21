#ifndef _OBJECT_
#define _OBJECT_

class Object;
#include "Value.h"
#include <map>
#include <functional>
class Object {
private:
	
public:
	std::map<std::string, Value> map;

    Object();
    Object operator=(int i);
    Object operator=(double d);
    Object operator=(const char* str);
    //Object operator=(bool b);
	Object operator=(std::function<Value(void)> l);
	Object operator=(Object obj);

	Object operator[](const Object& obj);
};


#endif