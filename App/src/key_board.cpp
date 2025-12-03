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
    // std::fill_n(key_state, static_cast<Underlying_SystemAttribute>(SystemAttribute::UNKNOWN), false);
}

void KeyBoard::listenKeyBoard() {
    if (is_listening) return;
    LOGI("Start listen keyboard");
    is_listening = true;
    // thực chất khi gọi processKeyBoard() trình biên dịch sẽ dịch thành processKeyBoard(this)
    std::thread t(&KeyBoard::processKeyBoard, this); 
    /*
    - join(): sẽ chờ luồng con kết thúc mới chạy tiếp, đồng thời sẽ giải phóng tài nguyên luồng con đúng cách
    - detach(): tách luồng con ra chạy độc lập, luồng chính không chờ nữa. Tài nguyên tự giải phóng khi luồng con kết thúc
    */
    // t.join();
    t.detach();
}
void KeyBoard::stopListen(){
    if (is_listening)
    {
        LOGI("Stopping keyboard listening...");
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
            if(it != key_map.end() && current_press != last_press){
                //std::cout << "press: " << current_press  << " - " << (char)current_press << std::endl;
                notify(it->second, true);
                pressed_key.push_back(it->second);
                last_press = current_press;
            }
        }else{
            if(last_press != -1){
                auto it = key_map.find(last_press);
                if(it != key_map.end()){
                    std::this_thread::sleep_for(std::chrono::milliseconds(200)); //giả lập nhả phím sau 200 ms
                    //std::cout << "release: " << last_press  << " - " << (char)last_press << std::endl;
                    notify(it->second, false);
                    pressed_key.erase(
                        std::remove(pressed_key.begin(), pressed_key.end(), it->second),
                        pressed_key.end()
                    );
                    last_press = -1;
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    LOGE("Stopped listening to keyboard");
}

void KeyBoard::attach(Observer* ob){
    auto is_exits = [ob](const std::vector<Observer*>& obs){ 
        return std::find(obs.begin(), obs.end(), ob) != obs.end();
    };
    if(is_exits(observers)) return;
    else observers.push_back(ob);
}

void KeyBoard::detach(Observer* ob){
    /* bản chất hàm remove chỉ dồn tất cả các phần từ khác ob về đầu vector
       và trả về vùng nhớ rác (vùng nhớ mới của ob). ob không còn trong vùng hợp lệ nhưng vẫn nằm trong vector về mặt bộ nhớ.
       ==> cần erase để xóa vùng nhớ rác đó khỏi vector
       ==> bản chất std::remove(observers.begin(), observers.end(), ob) trả về trị trí đầu tiên cần xóa 
    */
    observers.erase(
        std::remove(observers.begin(), observers.end(), ob),
        observers.end()
    );
}

int KeyBoard::notify(SystemAttribute key, bool is_press){
    if(is_press){
        for(auto& ob : observers){
            ob->onKeyPress(key);
        }
    }else{
        for(auto& ob : observers){
            ob->onKeyRelease(key);
        }
    }
    return 0;
}





