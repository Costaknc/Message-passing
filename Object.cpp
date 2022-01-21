#include "Object.h"
#include<iostream>

Object::Object(){

}


Object Object::operator=(int i){
    std::cout << "I do crazy staff\t " << i << std::endl;
    return Object();
}

Object Object::operator=(double d){
    std::cout << "I do crazy staff too\n";
    return Object();
}

Object Object::operator=(const char* str){
    // do some
    return Object();
}

Object Object::operator=(MyBool b){
    // do some
    return Object();
}

Object Object::operator=(std::function<Value(void)> l){
    std::cout << "Kosta gamiesai\n";
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
