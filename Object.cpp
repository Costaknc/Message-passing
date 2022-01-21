#include "Object.h"
#include <iostream>

Object alpha;

Object::Object(){}

Object::Object(char reset_alpha){
    alpha.map.clear();
}

Object Object::operator[](const Object& obj) {
    
    return obj;
}

Object Object::operator[](const TmpObject& obj){
    Object new_obj = Object();
    new_obj.map = obj.map;
    return new_obj;
}