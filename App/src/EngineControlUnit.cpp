#include "EngineControlUnit.h"
#include "my_log.h"

EngineControlUnit::EngineControlUnit(KeyBoard &key_board, carModel car_):car_model(car_),
    drive_mode("ECO"), speed(0), battery_level(0), wind_level(0),temperature(22),
    ac_stt(false), is_brake_pedal(false), is_accelerator_pedal(false)
{
    LOGI("EngineControlUnit initialized");
    key_board.attach(this);
    key_board.attach(&db); 
}


void EngineControlUnit::setDriveMode(DriveMode mode){

}

void EngineControlUnit::setSpeed(uint16_t spd){

}

void EngineControlUnit::setBatteryLevel(uint8_t level){

}

void EngineControlUnit::setWindLevel(uint8_t level){

}

void EngineControlUnit::setACStatus(bool status){

}

void EngineControlUnit::setBrakePedal(bool is_pressed){

}

void EngineControlUnit::setAcceleratorPedal(bool is_pressed){

}

int EngineControlUnit::onKeyPress(SystemAttribute key){
    switch (key)
    {
    case SystemAttribute::UP:{
        if(temperature < car_model.getTempMax()) temperature++;
        db.write_data(SystemAttribute::AC_CONTROL, std::to_string(temperature));
        break;
    }
    case SystemAttribute::DOWN:{
        if(temperature > car_model.getTempMin()) temperature--;
        db.write_data(SystemAttribute::AC_CONTROL, std::to_string(temperature));
        break;
    }
    case SystemAttribute::RIGHT:
        break;
    case SystemAttribute::SPACE:
        break;
    case SystemAttribute::ENTER:
        break;  
    case SystemAttribute::N:
        break;
    case SystemAttribute::M:
        break;    

    default:
        break;
    }
    return 0;
}