#ifndef ENGINE_CONTROL_UNIT_H__
#define ENGINE_CONTROL_UNIT_H__

#include <cstdint>
#include "DisplayManager.h"
#include "carModel.h"
#include "database.h"

class EngineControlUnit : public KeyBoard::Observer
{
private:
    DisplayManager display_manager; carModel car_model;
    database db;

    std::string drive_mode;
    uint16_t speed;
    uint8_t battery_level, wind_level, temperature;
    bool ac_stt, is_brake_pedal, is_accelerator_pedal;

public:
    EngineControlUnit(KeyBoard &key_board, carModel car_);
    ~EngineControlUnit(){};

    int onKeyPress(SystemAttribute key) override;
    int onKeyRelease(SystemAttribute key) override{ return 0; };    

    uint16_t getSpeed() const{ return speed; };
    std::string getDriveMode() const{ return drive_mode; };
    uint8_t getBatteryLevel() const{ return battery_level; };
    uint8_t getWindLevel() const{ return wind_level; };
    bool getACStatus() const{ return ac_stt; };
    bool isBrakePedalPressed() const{ return is_brake_pedal; };
    bool isAcceleratorPedalPressed() const{ return is_accelerator_pedal; };

    void setDriveMode(DriveMode mode);
    void setSpeed(uint16_t spd);
    void setBatteryLevel(uint8_t level);
    void setWindLevel(uint8_t level);
    void setACStatus(bool status);
    void setBrakePedal(bool is_pressed);
    void setAcceleratorPedal(bool is_pressed);

};




#endif /*  */
