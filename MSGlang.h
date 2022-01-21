#ifndef _MSGLANG_
#define _MSGLANG_

#include <iostream>
#include <assert.h>

#include "TmpObject.h"
#include "Object.h"
#include "Value.h"
#include "MyBool.h"

#define let auto
#define object Object('x')
#define values alpha,
#define lambda []() -> Value
#define none Value()
#define true MyBool(true)
#define false MyBool(false)
//#define obj["X"]  alpha.map[X]

extern Object alpha;

inline Object* ref(Object arg){
	Object* ptr = &arg;
	return ptr;
}

inline TmpObject key(std::string str) {
	return TmpObject(str);
}

inline Object operator,(Object obj, int arg){
	alpha.map[std::to_string(alpha.map.size())] = Value(arg);
	return alpha;
}
inline Object operator,(Object obj, double arg){
	alpha.map[std::to_string(alpha.map.size())] = Value(arg);
	return alpha;
}
inline Object operator,(Object obj, const char* arg){
	alpha.map[std::to_string(alpha.map.size())] = Value(arg);
	return alpha;
}
inline Object operator,(Object obj, MyBool arg){
	alpha.map[std::to_string(alpha.map.size())] = Value(arg);
	return alpha;
}
inline Object operator,(Object obj, std::function<Value(void)> arg){
	alpha.map[std::to_string(alpha.map.size())] = Value(arg);
	return alpha;
}
inline Object operator,(Object obj, Object arg){
	alpha.map[std::to_string(alpha.map.size())] = Value(arg);
	return alpha;
}

inline TmpObject operator,(TmpObject obj1, TmpObject obj2){
	obj1.map.insert(obj2.map.begin(), obj2.map.end());
	return obj1;
}

inline std::ostream& operator<<(std::ostream& os, Value val){
        switch (val.type){
        case INT:
            os << val.value.i;
            break;

        case DOUBLE:
            os << val.value.d;
            break;

        case STRING:
            os << "\"" << val.value.str << "\"";
            break;

        case BOOL:
            if(val.value.b)
                os << "true";
            else
                os << "false";
            break;

        case FUNCTION:
            os << "lambda";
            break;

        case _NULL:
            os << "null";
            break;

        default:
            os << "null";
            break;
        }

    return os;
}

inline std::ostream& operator<<(std::ostream& os, Object obj){
	os << "object [";
	for(auto iter = obj.map.begin(); iter != obj.map.end(); ++iter){
		os << "\"" << iter->first << "\" : ";

		switch (iter->second.type){
		case INT:
			os << iter->second.value.i << ", ";
			break;

		case DOUBLE:
			os << iter->second.value.d << ", ";
			break;

		case STRING:
			os << "\"" << iter->second.value.str << "\", ";
			break;

		case BOOL:
			if(iter->second.value.b)
				os << "true, ";
			else
				os << "false, ";

			break;

		case FUNCTION:
			os << "lambda, ";
			break;

		case _NULL:
			os << "null";
			break;

		default:
			assert(0);
			break;
		}
	}
	os << " ]\n";

	return os;
}

#endif
