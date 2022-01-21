#include "Value.h"


Value::Value() {
    type = _NULL;
}

Value::Value(int val){
    this->type = INT;
    this->value.i = val;
}

Value::Value(double val){
    this->type = DOUBLE;
    this->value.d = val;
}

Value::Value(const char* val){
    this->type = STRING;
    this->value.str = std::string(val);
}

Value::Value(MyBool val){
    this->type = BOOL;
    this->value.b = val.val;
}

Value::Value(std::function<Value(void)> val){
    this->type = FUNCTION;
    this->value.l = val;
}

Value::Value(Object val){
    this->type = OBJECT;
    Object* _val = new Object();
    _val->map = val.map;
    this->value.o = _val;
}

void Value::operator=(int x){
  this->type = INT;
  this->value.i = x;
}
void Value::operator=(double x){
  this->type = DOUBLE;
  this->value.d = x;
}
void Value::operator=(MyBool x){
  this->type = BOOL;
  this->value.b = x.val;
}
void Value::operator=(const char* x){
  this->type = STRING;
  this->value.str = std::string(x);
}
void Value::operator=(std::function<Value(void)> val){
  this->type = FUNCTION;
  this->value.l = val;
}
void Value::operator=(Object val){
   this->type = OBJECT;
    Object* _val = new Object();
    _val->map = val.map;
    this->value.o = _val;
}
