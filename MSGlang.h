#include <iostream>
#include <string>
#include <functional>
#include <variant>
#include <map>

#define let auto
#define object Object()
#define none Value()

// class Object {
//     private:

//     public:
        
// }alpha;

class Value {
    private:
        enum Type {INT, DOUBLE, STRING, BOOL, FUNCTION, OBJECT, _NULL} type;
        std::variant<int, double, std::string, bool, std::function<Value(void)>, Object> value;

    public:
        inline Value(){
            type = _NULL;
        }

        template <typename T>;
        inline Value(T arg){
            value = arg;
        }
};
