#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm> //fill_n, ...
#include <conio.h> //keyboard
#include "key_board.h"
#include "my_log.h"

KeyBoard::KeyBoard():is_listening(false){
    key_map = {
        {72, SystemAttribute::UP},
        {80, SystemAttribute::DOWN},
        {77, SystemAttribute::RIGHT},
        {118, SystemAttribute::V}, 
        {98, SystemAttribute::B},   
        {32, SystemAttribute::SPACE},
        {13, SystemAttribute::ENTER}, // '\n' cho phím Enter trên macOS
        {110, SystemAttribute::N},    
        {109, SystemAttribute::M}};   
    std::fill_n(key_state, static_cast<Underlying_SystemAttribute>(SystemAttribute::UNKNOWN), false);
}

void KeyBoard::listenKeyBoard() {
    if (is_listening) return;
    logInfo("Start listen keyboard");
    is_listening = true;
    // thực chất khi gọi processKeyBoard() trình biên dịch sẽ dịch thành processKeyBoard(this)
    std::thread t(&KeyBoard::processKeyBoard, this); 
    /*
    - join(): sẽ chờ luồng con kết thúc mới chạy tiếp, đồng thời sẽ giải phóng tài nguyên luồng con đúng cách
    - detach(): tách luồng con ra chạy độc lập, luồng chính không chờ nữa. Tài nguyên tự giải phóng khi luồng con kết thúc
    */
    t.join();
    //t.detach();
}
void KeyBoard::stopListen(){
    if (is_listening)
    {
        logInfo("Stopping keyboard listening...");
        is_listening = false;
    }
}

void KeyBoard::processKeyBoard() {
    int last_press = -1;
    while (is_listening)
    {
        /*
        _kbhit(): kiểm tra xem có phím nào được nhấn không, trả về true/false
        _getch(): lấy mã ASCII của phím được nhấn
        */
        if (_kbhit())
        {
            int current_press = _getch();
            if(current_press == 0){
                current_press = _getch(); //nếu phím đặc biệt (mũi tên) thì gọi thêm lần nữa để lấy mã đúng
            }
            
            auto it = key_map.find(current_press);
            if(it != key_map.end()){
                std::cout << "press: " << current_press  << " - " << (char)current_press << std::endl;
                logInfo("key press: " + std::to_string(current_press) + " - " + std::to_string(static_cast<char>(current_press)));
                SystemAttribute attr = it->second;
                Underlying_SystemAttribute index = static_cast<Underlying_SystemAttribute>(attr);
                key_state[index] = !key_state[index]; //toggle state

            }
        }else{

        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    logError("Stopped listening to keyboard");
}
