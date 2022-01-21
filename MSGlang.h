#pragma once

#include <iostream>
#include <assert.h>

#include "Object.h"
#include "Value.h"
#include "MyBool.h"

#define let auto
#define object Object()
#define values alpha,
#define lambda []() -> Value
#define none Value()
#define true MyBool(true)
#define false MyBool(false)

Object alpha;


inline Object key(std::string str) {
	//std::cout << "aa" << std::endl;
	return Object();
}

// inline void expand() {
// 	//do not remove me :)
// }

// template <typename T, typename... Types>
// inline void expand(T arg0, Types... rest) {
// 	std::cout << typeid(arg0).name() << std::endl;
// 	alpha.map[std::to_string(alpha.map.size())] = Value(arg0);
// 	return expand(rest...);
// }

// template <typename... Types>
// inline Object operator,(Object obj, Types... args) {
// 	alpha.map.clear();
// 	expand(args...);
// 	return alpha;
// }

// template <typename T>
// inline Object operator,(Object obj, T arg){
// 	alpha.map[std::to_string(alpha.map.size())] = Value(arg);
// 	return alpha;
// }
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

inline std::ostream& operator<<(std::ostream& os, Object obj){
	os << "object [";
	for(auto iter = obj.map.begin(); iter != obj.map.end(); ++iter){
		os << "\"" << iter->first << "\" : ";
		//os << "valueXX, ";
		std::cout << iter->second.type << std::endl;
		// std::cout << "!!!!!!!!\n";

		switch (iter->second.type){
		case INT:
			os << iter->second.value.i;
			break;
		
		case DOUBLE:
			os << iter->second.value.d;
			break;
		
		case STRING:
			os << "\"" << iter->second.value.str << "\"";
			break;

		case BOOL:
			if(iter->second.value.b)
				os << "true, ";
			else
				os << "false, ";
			
			break;

		case FUNCTION:
			os << "lambda";
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