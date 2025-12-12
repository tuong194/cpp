#include <iostream>
#include <thread>
#include "key_board.h"
#include "Observer.h"
#include "database.h"
#include "EngineControlUnit.h"

// using namespace std;

int main() {
    carModel car_model(carBranch::VINFAST);
    KeyBoard kb;

    kb.listenKeyBoard();
    EngineControlUnit ECU(kb,car_model);

    while (1)
    {
        /* code */
    }
    kb.stopListen();

    // std::this_thread::sleep_for(std::chrono::seconds(15));
    // std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}