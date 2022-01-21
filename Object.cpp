#include "Object.h"
#include<iostream>

std::string  index;
Object beta;

Object::Object(){

}


Object Object::operator=(int i){
    std::cout << index <<"\t" << i << std::endl;
    beta.map[index] = Value(i);

    return Object();
}

Object Object::operator=(double d){
    std::cout << index <<"\t" << d << std::endl;
    beta.map[index] = Value(d);
    return Object();
}

Object Object::operator=(const char* str){
    beta.map[index] = Value(str);
    return Object();
}

Object Object::operator=(MyBool b){
    std::cout << index << "\t " << b.val << std::endl;
    beta.map[index] = Value(b.val);
    return Object();
}

Object Object::operator=(std::function<Value(void)> l){
    std::cout << index << "\t " /* << l */ << std::endl;
    beta.map[index] = Value(l);
    return Object();
}

Object Object::operator=(Object obj){
    beta.map[index] = Value(obj);
    return Object();
}


Object Object::operator[](const Object& obj) {
    // do some stuff here boi
    return obj;
}
