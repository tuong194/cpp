#include <iostream>

void logInfo(const std::string &msg) {
    std::cout << "\033[32m[INFO]  " << msg << "\033[0m\n";    
}

void logWarn(const std::string &msg) {
    std::cout << "\033[33m[WARN]  " << msg << "\033[0m\n";   
}

void logError(const std::string &msg) {
    std::cout << "\033[31m[ERROR] " << msg << "\033[0m\n";    
}

void logDebug(const std::string &msg) {
    std::cout << "\033[36m[DEBUG] " << msg << "\033[0m\n";    
}