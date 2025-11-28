#include <iostream>

void LOGI(const std::string &msg) {
    std::cout << "\033[32m[INFO]  " << msg << "\033[0m\n";    
}

void LOGW(const std::string &msg) {
    std::cout << "\033[33m[WARN]  " << msg << "\033[0m\n";   
}

void LOGE(const std::string &msg) {
    std::cout << "\033[31m[ERROR] " << msg << "\033[0m\n";    
}

void LOGD(const std::string &msg) {
    std::cout << "\033[36m[DEBUG] " << msg << "\033[0m\n";    
}