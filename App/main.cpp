#include <iostream>
#include <thread>
#include "key_board.h"
#include "Observer.h"

// using namespace std;

int main() {
    KeyBoard kb;
    kb.listenKeyBoard();
    // std::this_thread::sleep_for(std::chrono::seconds(15));
    // kb.stopListen();
    // std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}