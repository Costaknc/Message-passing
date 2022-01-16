#include <iostream>
#include <string>
#include <functional>
#include <variant>
#include <map>

#define let auto
#define object Object()
#define none Value()

class Value;

class Object {
    private:

    public:
        std::unordered_map<std::string, Value> map;

        inline Object operator[](const Object& obj){
            //do some stuff n $hit
            return Object();
        }
        
}alpha;

inline void expand(){

}

template <typename T, typename... Types>
inline void expand(T arg0, Types... rest){
    std::cout << typeid(arg0).name() << std::endl;
    alpha.map[std::to_string(alpha.map.size())] = Value(arg0);
    return expand(rest...);
}

template <typename... Types>
inline Object operator,(Pbject obj, Types... args){
    alpha.map.clear();
    expnd(args...);
    return alpha;
}

class Value {
    private:
        enum Type {INT, DOUBLE, STRING, BOOL, FUNCTION, OBJECT, _NULL} type;
        std::variant<int, double, std::string, bool, std::function<Value(void)>, Object> value;

    public:
        inline Value(){
            type = _NULL;
        }

        template <typename T>
        inline Value(T arg){
            value = typeid(arg).name();
            type = value;
        }
};
