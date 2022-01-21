#ifndef _TMPOBJECT_
#define _TMPOBJECT_

#include <map>
#include <string>
#include <functional>
class TmpObject;
#include "Object.h"
#include "Value.h"
#include "MyBool.h"

class TmpObject {
public:
    std::map<std::string, Value> map;
    std::string tmp_key;

    TmpObject();
    TmpObject(std::string key);

    TmpObject operator=(int i);
    TmpObject operator=(double d);
    TmpObject operator=(const char* str);
    TmpObject operator=(MyBool b);
	TmpObject operator=(std::function<Value(void)> l);
	TmpObject operator=(Object obj);

};

#endif