#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <variant>
#include <map>
#include <unordered_map>

#define let auto
#define object Object()
#define values alpha,
#define lambda []() -> Value
#define none Value()

class Object;

class Value {
private:
    enum Type {INT, DOUBLE, STRING, BOOL, FUNCTION, OBJECT, _NULL} type; // might be usefull
    std::variant<int, double, std::string, bool, std::function<Value(void)>, Object*> value; // something like a union
public:
    inline Value() {
        type = _NULL;
    }

    template <typename T>
    inline Value(T arg) {
        //assign correct type to 'type' variable ( maybe using typeid(arg).name() ) - might be usefull
            value = typeid(arg).name();
            //std::cout << typeid(value).name() << std::endl;
            //type = std::get<typeid(arg).name()>(value);
    }
};

class Object {
private:
public:
    std::unordered_map<std::string, Value> _map;

    inline Object operator[](const Object& obj) {
        // do some 
        return Object();
    }
} alpha;

inline void expand() {
    //do not remove me
}

template <typename T, typename... Types>
inline void expand(T arg0, Types... rest) {
    std::cout << typeid(arg0).name() << std::endl;
    alpha._map[std::to_string(alpha._map.size())] = Value(arg0);
    return expand(rest...);
}



template <typename... Types>
inline Object operator,(Object obj, Types... args) {
    alpha._map.clear();
    expand(args...);
    return alpha;
}