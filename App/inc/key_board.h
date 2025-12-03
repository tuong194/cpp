#ifndef KEY_BOARD_H__
#define KEY_BOARD_H__

#include <type_traits> // std::underlying_type_t
#include <map>
#include <vector>
#include "Define.h"

// using Underlying_SystemAttribute = std::underlying_type_t<SystemAttribute>;


class KeyBoard {
    public:
        class Observer{
            public:
            virtual int onKeyPress(SystemAttribute key) = 0;
            virtual int onKeyRelease(SystemAttribute key) = 0;
            virtual ~Observer() = default;
        };
        KeyBoard();
        ~KeyBoard(){}
        void listenKeyBoard();
        void stopListen();
        void attach(Observer* ob);
        void detach(Observer* ob);
    private:
        std::vector<Observer*> observers;
        std::vector<SystemAttribute> pressed_key;
        std::map<int, SystemAttribute> key_map;
        bool is_listening;
        void processKeyBoard();
        int notify(SystemAttribute key, bool is_press);
};  

#endif /*  */
