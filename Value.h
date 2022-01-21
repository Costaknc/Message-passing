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
    bool b;
    std::function<Value(void)> l;
    Object* o;
    _Value(){}
    ~_Value(){}
};

class Value {
public:
	enum Type type;
    struct _Value value;

	Value();
	Value(int val);
	Value(double val);
	Value(const char* val);
	Value(MyBool val);
	Value(std::function<Value(void)> val);
	Value(Object val);


	void  operator=(int i);
	void  operator=(double d);
	void  operator=(MyBool b);
	void  operator=(const char* str);
	void  operator=(std::function<Value(void)> l);
	void  operator=(Object o );

};

#endif