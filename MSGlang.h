#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <variant>
#include <map>

#define let auto
#define object Object()
#define values alpha,
#define lambda []() -> Value
#define none Value()

class Value;

class Object {
private:
	
public:
	std::unordered_map<std::string, Value> map;

	inline Object operator[](const Object& obj) {
		// do some stuff here boi
		return Object();
	}
} alpha;



inline void expand() {
	//do not remove me :)
}

template <typename T, typename... Types>
inline void expand(T arg0, Types... rest) {
	std::cout << typeid(arg0).name() << std::endl;
	alpha.map[std::to_string(alpha.map.size())] = Value(arg0);
	return expand(rest...);
}

template <typename... Types>
inline Object operator,(Object obj, Types... args) {
	alpha.map.clear();
	expand(args...);
	return alpha;
}

// unused for now
class Value {
private:
	enum Type {INT, DOUBLE, STRING, BOOL, FUNCTION, OBJECT, _NULL} type; // might be usefull
	std::variant<int, double, std::string, bool, std::function<Value(void)>, Object> value; // something like a union

public:
	inline Value() {
		type = _NULL;
	}

	template <typename T>
	inline Value(T arg) {
		//assign correct type to 'type' variable ( maybe using typeid(arg).name() ) - might be usefull
		value = arg;
	}
};