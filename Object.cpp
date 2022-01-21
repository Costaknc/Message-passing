#include "Object.h"

Object::Object(){

}


Object Object::operator=(int i){
    // do some
    return Object();
}

Object Object::operator=(double d){
    // do some
    return Object();
}

Object Object::operator=(const char* str){
    // do some
    return Object();
}

// Object Object::operator=(bool b){
//
// }

Object Object::operator=(std::function<Value(void)> l){
    // do some
    return Object();
}

Object Object::operator=(Object obj){
    // do some
    return Object();
}


Object Object::operator[](const Object& obj) {
    // do some stuff here boi
    return obj;
}