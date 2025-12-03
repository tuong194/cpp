#ifndef DATABASE_H__
#define DATABASE_H__
#include "key_board.h"
#include <map>
#include <string>

class database : public KeyBoard::Observer
{
private:
    std::map<std::string, std::string> data_store;
    void write_data_default();
    int init_file_csv();
    int change_data(SystemAttribute key, std::string value);
public:
    database(KeyBoard &key_board);
    ~database() = default;
    int onKeyPress(SystemAttribute key) override;
    int onKeyRelease(SystemAttribute key) override;
    void read_data();
    void write_data();
};

inline int database::onKeyPress(SystemAttribute key){
    return change_data(key, "1");
}
inline int database::onKeyRelease(SystemAttribute key){
    return change_data(key, "0");
}

#endif /*  */
