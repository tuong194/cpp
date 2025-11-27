#ifndef KEY_BOARD_H__
#define KEY_BOARD_H__

#include <type_traits> // std::underlying_type_t
#include <map>
#include "Define.h"

using Underlying_SystemAttribute = std::underlying_type_t<SystemAttribute>;

class KeyBoard {
    public:
        KeyBoard();
        ~KeyBoard(){}
        void listenKeyBoard();
        void stopListen();
    private:
        bool key_state[static_cast<Underlying_SystemAttribute>(SystemAttribute::UNKNOWN)];
        std::map<int, SystemAttribute> key_map;
        bool is_listening;
        void processKeyBoard();
};  

#endif /*  */
