#include <iostream>
#include <algorithm> //func std::remove
#include "Observer.h"


void Display::update(int x){
    std::cout << "Display updated with value: " << x << std::endl;
}

void Logger::update(int x){
    std::cout << "Logger updated with value: " << x << std::endl;
}

void Subject::attach(Observer* o){
    obs.push_back(o);
}

void Subject::detach(Observer* o){
    obs.erase(
        std::remove(obs.begin(), obs.end(), o),
        obs.end()
    );
}

void Subject::setState(int x){
    state = x;
    notify(x);
}

void Subject::notify(int x){
    for(auto& o : obs){
        o->update(x);
    }
}