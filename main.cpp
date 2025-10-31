#include <iostream>
#include <thread>
#include "key_board.h"
#include "hello.h"

// using namespace std;

int main() {
    say_hello();
    Display display;
    display.update(42);
    std::thread t(task);
    t.join();
    std::cout << "Hello from main!\n";
    return 0;
}