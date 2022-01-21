#ifndef _VALUE_
#define _VALUE_

class Value;
#include "Object.h"
#include "MyBool.h"
#include <functional>
#include <string>



enum Type {INT, DOUBLE, STRING, BOOL, FUNCTION, OBJECT, _NULL};
struct _Value {
    int i;
    double d;
    std::string str;
    bool b; // --
    std::function<Value(void)> l;
    Object* o;
    _Value(){}
    ~_Value(){}
};

class Value {
public:
	enum Type type; 
	//std::variant<int, double, std::string, bool, std::function<Value(void)>, Object*> value; // something like a union
    struct _Value value;

	Value();
	Value(int val);
	Value(double val);
	Value(const char* val);
	Value(MyBool val);
	Value(std::function<Value(void)> val);
	Value(Object val);
};


#endif