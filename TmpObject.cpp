#include "TmpObject.h"

TmpObject::TmpObject(){

}

TmpObject::TmpObject(std::string key){
    this->tmp_key = key;
}

TmpObject TmpObject::operator=(int i){
    TmpObject new_obj;
    new_obj.map[this->tmp_key] = Value(i);
    return new_obj;
}

TmpObject TmpObject::operator=(double d){
    TmpObject new_obj;
    new_obj.map[this->tmp_key] = Value(d);
    return new_obj;
}

TmpObject TmpObject::operator=(const char* str){
    TmpObject new_obj;
    new_obj.map[this->tmp_key] = Value(str);
    return new_obj;
}

TmpObject TmpObject::operator=(MyBool b){
    TmpObject new_obj;
    new_obj.map[this->tmp_key] = Value(b);
    return new_obj;
}

TmpObject TmpObject::operator=(std::function<Value(void)> l){
    TmpObject new_obj;
    new_obj.map[this->tmp_key] = Value(l);
    return new_obj;
}

TmpObject TmpObject::operator=(Object obj){
    TmpObject new_obj;
    new_obj.map[this->tmp_key] = Value(obj);
    return new_obj;
}
