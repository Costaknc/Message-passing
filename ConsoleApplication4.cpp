#include "MSGlang.h"

int main(){
	let x = object;
	let y = object[values "asd", 4, 4.14, true, lambda{ std::cout << "Welcome to HY352"; return none; }, lambda{ return none; }];
	let z = object[
        key("one") = 11,
        key("two") = 13.21,
        key("three") = lambda{ return none; }
    ];

    let yy = object[values "XX", 44444];

	std::cout << y << std::endl;
    std::cout << z << std::endl;
    std::cout << yy << std::endl;

    //std::cout << y[2] << std::endl;

    let gg = y["1"];
    y["1"] = 33;
    let rr = y["1"];
    std::cout << gg << std::endl;
    std::cout << rr << std::endl;

    let f = ref(y);

    std::cout << *f << std::endl;
}