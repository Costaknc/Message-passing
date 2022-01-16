#include <iostream>
#include <string>
#include <functional>
#include <variant>
#include <map>

#define let auto
#define object Object()
#define none Value()

class Object {
<<<<<<< HEAD
    private:

    public:
        
};

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
=======
    
};
>>>>>>> f016a70a6d4ec5bd0105c42a77c3822d25858473
