#include <iostream>
#include <thread>
#include "key_board.h"
#include "hello.h"
#include "Observer.h"

// using namespace std;

int main() {
    say_hello();
    Display display;
    Logger logger;
    Subject subject;
    subject.attach(&display);
    subject.attach(&logger);
    std::cout << "Hello from main!\n";
    for (int i = 1; i <= 5; ++i) {
        subject.setState(i * 10);
    }
    // std::thread t(task);
    // t.join();
    return 0;
}