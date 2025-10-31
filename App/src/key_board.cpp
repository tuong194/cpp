#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <conio.h> //keyboard


void task() {
    
    while (1)
    {
        if (_kbhit())
        {
            int ch = _getch();
            std::cout << "Nhan: " << ch  << " - " << (char)ch << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
}