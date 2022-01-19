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

enum Type {INT, DOUBLE, STRING, BOOL, FUNCTION, OBJECT, _NULL}; // might be usefull




// unused for now
class Value {
public:
	enum Type type; 
	std::variant<int, double, std::string, bool, std::function<Value(void)>, Object*> value; // something like a union


	inline Value() {
		type = _NULL;
	}
// new shit here
inline Value(int val){
  this->type = INT;
  this->value = val;
}
inline Value(double val){
  this->type = DOUBLE;
  this->value = val;
}
inline Value(const char* val){
  this->type = STRING;
  this->value = std::string(val);
}
inline Value(bool val){
  this->type = BOOL;
  this->value = val;
}
inline Value(std::function<Value(void)> val){
  this->type = FUNCTION;
  this->value = val;
}
inline Value(Object val){
  this->type = OBJECT;
  Object* _val = new Object();
  // .... copy map from val to _val
  this->value = _val;
}

class Object {
private:
	
public:
	std::unordered_map<std::string, Value> _map;

	inline Object operator=(Value val) {
		std::cout << typeid(val).name() << std::endl;
		return Object();
	}

	inline Object operator[](const Object& obj) {
		// do some stuff here boi
		return obj;
	}
} alpha;


inline Object key(std::string str) {
	std::cout << "aa" << std::endl;
	return Object();
}

inline void expand() {
	//do not remove me :)
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

inline std::ostream& operator<<(std::ostream& os, Object obj){
	os << "object [";
	for(auto iter = obj._map.begin(); iter != obj._map.end(); ++iter){
		os << "\"" << iter->first << "\" : ";
		//os << "valueXX, ";
		std::cout << iter->second.type << std::endl;
		std::cout << "!!!!!!!!\n";

		switch (iter->second.type){
		case INT:
			os << std::get<int>(iter->second.value);
			break;
		
		case DOUBLE:
			os << std::get<double>(iter->second.value);
			break;
		
		case STRING:
			os << std::get<std::string>(iter->second.value);
			break;

		//....

		default:
			break;
		}
	}
	os << " ]\n";

	return os;
}