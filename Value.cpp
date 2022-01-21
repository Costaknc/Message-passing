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

Value::Value(bool val){
    this->type = BOOL;
    this->value.b = val;
}

Value::Value(std::function<Value(void)> val){
    this->type = FUNCTION;
    this->value.l = val;
}

Value::Value(Object val){
    this->type = OBJECT;
    Object* _val = new Object();
    // .... copy map from val to _val
    this->value.o = _val;
}