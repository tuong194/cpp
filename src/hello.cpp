#include <iostream>
#include "hello.h"

void say_hello() {
    std::cout << "Hello, World!" << std::endl;
}

void Display::update(int x){
    std::cout << "Display updated with value: " << x << std::endl;
}