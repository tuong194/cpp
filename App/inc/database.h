#ifndef DATABASE_H__
#define DATABASE_H__
#include "key_board.h"
#include <map>
#include <string>

#include <iostream>


class database : public KeyBoard::Observer
{
private:
    std::map<std::string, std::string> data_store;
    void write_data_default();
    int init_file_csv();
    int write_data(const std::string key, const std::string value);
public:
    database();
    ~database() = default;
    int onKeyPress(SystemAttribute key) override;
    int onKeyRelease(SystemAttribute key) override;
    void read_data();
    void write_all_data();

    
    template <typename EnumType1>
    int write_data(EnumType1 T, std::string value){
        static_assert(std::is_enum_v<EnumType1>,
            "write_data(EnumType1, string) only accepts enums");
        return write_data(Utils::enum_to_string(T), value);
    }

};

inline int database::onKeyPress(SystemAttribute key){
    return write_data(key, "1");
}
inline int database::onKeyRelease(SystemAttribute key){
    return write_data(key, "0");
}



#endif /*  */
