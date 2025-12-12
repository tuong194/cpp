#include "database.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "my_log.h"

#define DATA_PATH "..//Data//Database.csv"
#define DATA_PATH_VINFAST "..//Data//dbVinfast.csv"
#define DATA_PATH_TESLA   "..//Data//dbTesla.csv"

void read_data(carBranch branch, std::map<carAttribute, int>& data_map){
    std::string file_path;
    switch (branch)
    {
    case carBranch::VINFAST:
        file_path = DATA_PATH_VINFAST;
        break;
    case carBranch::TESLA:
        file_path = DATA_PATH_TESLA;
        break;
    
    default:
        break;
    }

    std::ifstream file(file_path.c_str());
    if (!file.is_open())
    {
        LOGE("Failed to open database file for reading ^-^ ");
        return;
    }
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string key;
        std::string value;
        if (std::getline(ss, key, ',') && ss >> value)
        {
            carAttribute carAtt = Utils::string_to_enum<carAttribute>(key);
            data_map[carAtt] = std::stoi(value);
        }
    }
    file.close();        
}

database::database(){
    init_file_csv();
    read_data(); //test
    // key_board.attach(this);
}


int database::init_file_csv()
{
    std::ifstream file(DATA_PATH);
    if (!file.is_open())
    {
        LOGE("Database file does not exist. Creating a new one with default values.");
        write_data_default();
        file.close(); 
        return -1;
    }else{
        LOGI("Database file exists.");
        file.close(); 
    }
    
    return 0;
}

int database::write_data(std::string key, std::string value){
    auto it =data_store.find(key);
    if(it != data_store.end()){
        data_store[key] = value;
        write_all_data();
        return 1;
    }
    return 0;
} 

void database::write_data_default()
{
    std::map<std::string, std::string> Database_Structure = {
        {"VEHICLE_SPEED", "0"},
        {"DRIVE_MODE", "ECO"},
        {"GEAR_SHIFT", "P"},
        {"TURN_SIGNAL", "0"},
        {"ROUTE_PLANNER", "0"},
        {"BATTERY_LEVEL", "0"},
        {"ODOMETER", "0"},
        {"BRAKE", "0"},
        {"ACCELERATOR", "0"},
        {"BATTERY_TEMP", "0"},
        {"AC_CONTROL", "0"},
        {"AC_STATUS", "0"},
        {"WIND_LEVEL", "0"},
        {"UP", "0"},
        {"DOWN", "0"},
        {"RIGHT", "0"},
        {"V", "0"},
        {"B", "0"},
        {"SPACE", "0"},
        {"ENTER", "0"},
        {"N", "0"},
        {"M", "0"}};
    std::ofstream file(DATA_PATH);
    if (!file.is_open())
    {
        LOGE("Failed to open database file for writing default values.");
        return;
    }
    file<<"key,value\n";
    for (const auto &pair : Database_Structure)
    {
        file << pair.first << "," << pair.second << "\n";
    }
    file.close(); 
}
void database::write_all_data()
{
    // std::ofstream file(DATA_PATH, std::ios::app); // ghi tiếp vào cuối file
    std::ofstream file(DATA_PATH); // ~ std::ofstream file(DATA_PATH, std::ios::out | std::ios::trunc): open file và xóa sạch nội dung cũ
    if (!file.is_open())
    {
        LOGE("Failed to open database file for writing.");
        return;
    }
    file<<"key,value\n";
    for (const auto &pair : data_store)
    {
        file << pair.first << "," << pair.second << "\n";
    }
    file.close();
}

void database::read_data()
{
    LOGI("read data from database");
    std::ifstream file(DATA_PATH);
    if (!file.is_open())
    {
        LOGE("Failed to open database file for reading.");
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string key;
        std::string value;
        if (std::getline(ss, key, ',') && ss >> value)
        {
            data_store[key] = value;
            std::cout << line << "\n";
        }
    }
    file.close(); 
}




