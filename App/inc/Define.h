#ifndef DEFINE_H__
#define DEFINE_H__

#include <stdexcept>
#include <type_traits>
#include <string>

enum class ERR_CODE
{
    SUCCESS = 0,
    FAILURE = -1,
};

enum class AirConditionStt{
    OFF = 0,
    ON = 1,
    UP,
    DOWN
};

enum class DriveMode
{
    ECO,  // Chế độ tiết kiệm năng lượng
    SPORT, // Chế độ thể thao
};

enum class SystemAttribute
{
    VEHICLE_SPEED, // tốc độ xe
    DRIVE_MODE, // chế độ lái
    GEAR_SHIFT, // số
    TURN_SIGNAL, // xi nhan
    ROUTE_PLANNER, // quãng đường dự kiến
    BATTERY_LEVEL,// phần trăm pin
    ODOMETER, // công tơ mét
    BRAKE, // phanh
    ACCELERATOR, // ga
    BATTERY_TEMP, // nhiệt độ pin
    AC_CONTROL, // điều hòa
    AC_STATUS, // trạng thái điều hòa
    WIND_LEVEL, // tốc độ gió

    UP,  // tăng nhiệt độ
    DOWN, // giảm nhiệt độ
    RIGHT, //tăng mức gió
    V, // xi nhan trái
    B, // xi nhan phải
    SPACE, // đạp ga
    ENTER, //phanh
    N, // on/off điều hòa
    M, // chuyển chế độ lái
    UNKNOWN
};

enum class carBranch
{
    VINFAST,
    TESLA
};

enum class carAttribute
{
    ENGINE_TOTAL,     //Số lượng động cơ
    BATTERY_CAPACITY, //Kwh -> dung luong pin
    BATTERY_VOLTAGE,  //V   -> dien ap pin
    MAX_RANGE,        //km  -> quang duong toi da di duoc neu day pin
    MAX_TORQUE,       //Nm  -. momen xoan
    MAX_ENGINE_POWER, //kW  -> cong suat toi da cua dong co
    MAX_AC_POWER,     //W   -> cong suat toi da cua dieu hoa   
    MAX_SPEED_SPORT,  //Km/h-> toc do toi da o che do sport
    MAX_SPEED_ECO,    //Km/h-> toc do toi da o che do sport
    MAX_RPM,          //rotation per minute -> so vong quay 
    WEIGHT,           //kg -> khoi luong khong tai cua xe
    WHEEL_RADIUS,     //cm -> ban kinh banh xe
    AC_TEMP_MAX,      //do c -> nhiet do toi da dieu ching duoc tren dieu hoa
    AC_TEMP_MIN,      //do c -> nhiet do nho nhat dieu chinh duoc tren dieu hoa
    WIND_LEVEL_MAX    //muc gio manh nhat tren dieu hoa
};



namespace Utils {
    /**
     * @brief chuyển đổi enum sang kiểu nguyên thủy underlying type (thường là int)
     * ko ném exeption
     * auto: trả về tự động, ở đây trả về kiểu std::underlying_type_t<E>
     */
    template <typename E>
    constexpr auto to_underlying(E e) noexcept { 
        return static_cast<std::underlying_type_t<E>>(e);
    }

    /**
     * @brief hàm chuyển đổi enum --> string
     * 
     */
    template <typename EnumType>
    inline std::string enum_to_string(EnumType e) {
        if constexpr (std::is_same_v<EnumType, SystemAttribute>) {
            switch (e) {
                case SystemAttribute::VEHICLE_SPEED: return "VEHICLE_SPEED";
                case SystemAttribute::DRIVE_MODE: return "DRIVE_MODE";
                case SystemAttribute::GEAR_SHIFT: return "GEAR_SHIFT";
                case SystemAttribute::TURN_SIGNAL: return "TURN_SIGNAL";
                case SystemAttribute::ROUTE_PLANNER: return "ROUTE_PLANNER";
                case SystemAttribute::BATTERY_LEVEL: return "BATTERY_LEVEL";
                case SystemAttribute::ODOMETER: return "ODOMETER";
                case SystemAttribute::BRAKE: return "BRAKE";
                case SystemAttribute::ACCELERATOR: return "ACCELERATOR";
                case SystemAttribute::BATTERY_TEMP: return "BATTERY_TEMP";
                case SystemAttribute::AC_CONTROL: return "AC_CONTROL";
                case SystemAttribute::AC_STATUS: return "AC_STATUS";
                case SystemAttribute::WIND_LEVEL: return "WIND_LEVEL";
                case SystemAttribute::UP: return "UP";
                case SystemAttribute::DOWN: return "DOWN";
                case SystemAttribute::RIGHT: return "RIGHT";
                case SystemAttribute::V: return "V";
                case SystemAttribute::B: return "B";
                case SystemAttribute::SPACE: return "SPACE";
                case SystemAttribute::ENTER: return "ENTER";
                case SystemAttribute::N: return "N";
                case SystemAttribute::M: return "M";
                default: return "UNKNOWN";
            }
        }else if constexpr (std::is_same_v<EnumType, SystemAttribute>) {
            switch (e) {
                case DriveMode::ECO: return "ECO";
                case DriveMode::SPORT: return "SPORT";
                default: return "UNKNOWN";
            }
        }
        return "UNKNOWN";
    }

    /**
     * @brief hàm chuyển đổi string --> enum
     * 
     * @tparam EnumType 
     * @param str 
     * @return EnumType 
     */
    template <typename EnumType>
    EnumType string_to_enum(const std::string& str) {
        if constexpr (std::is_same_v<EnumType, SystemAttribute>) {
            if (str == "VEHICLE_SPEED") return SystemAttribute::VEHICLE_SPEED;
            else if (str == "DRIVE_MODE") return SystemAttribute::DRIVE_MODE;
            else if (str == "GEAR_SHIFT") return SystemAttribute::GEAR_SHIFT;
            else if (str == "TURN_SIGNAL") return SystemAttribute::TURN_SIGNAL;
            else if (str == "ROUTE_PLANNER") return SystemAttribute::ROUTE_PLANNER;
            else if (str == "BATTERY_LEVEL") return SystemAttribute::BATTERY_LEVEL;
            else if (str == "ODOMETER") return SystemAttribute::ODOMETER;
            else if (str == "BRAKE") return SystemAttribute::BRAKE;
            else if (str == "ACCELERATOR") return SystemAttribute::ACCELERATOR;
            else if (str == "BATTERY_TEMP") return SystemAttribute::BATTERY_TEMP;
            else if (str == "AC_CONTROL") return SystemAttribute::AC_CONTROL;
            else if (str == "AC_STATUS") return SystemAttribute::AC_STATUS;
            else if (str == "WIND_LEVEL") return SystemAttribute::WIND_LEVEL;
            else if (str == "UP") return SystemAttribute::UP;
            else if (str == "DOWN") return SystemAttribute::DOWN;
            else if (str == "RIGHT") return SystemAttribute::RIGHT;
            else if (str == "V") return SystemAttribute::V;
            else if (str == "B") return SystemAttribute::B;
            else if (str == "SPACE") return SystemAttribute::SPACE;
            else if (str == "ENTER") return SystemAttribute::ENTER;
            else if (str == "N") return SystemAttribute::N;
            else if (str == "M") return SystemAttribute::M;
            else return SystemAttribute::UNKNOWN;
        }else if constexpr (std::is_same_v<EnumType, SystemAttribute>) {
            if (str == "ECO") return DriveMode::ECO;
            else if (str == "SPORT") return DriveMode::SPORT;
            else return DriveMode::ECO; // default
        }
        else if constexpr (std::is_same_v<EnumType, carAttribute>) {
            if (str == "ENGINE_TOTAL") return carAttribute::ENGINE_TOTAL;
            else if (str == "BATTERY_CAPACITY") return carAttribute::BATTERY_CAPACITY;
            else if (str == "BATTERY_VOLTAGE") return carAttribute::BATTERY_VOLTAGE;
            else if (str == "MAX_RANGE") return carAttribute::MAX_RANGE;
            else if (str == "MAX_TORQUE") return carAttribute::MAX_TORQUE;
            else if (str == "MAX_ENGINE_POWER") return carAttribute::MAX_ENGINE_POWER;
            else if (str == "MAX_AC_POWER") return carAttribute::MAX_AC_POWER;
            else if (str == "MAX_SPEED_SPORT") return carAttribute::MAX_SPEED_SPORT;
            else if (str == "MAX_SPEED_ECO") return carAttribute::MAX_SPEED_ECO;
            else if (str == "MAX_RPM") return carAttribute::MAX_RPM;
            else if (str == "WEIGHT") return carAttribute::WEIGHT;
            else if (str == "WHEEL_RADIUS") return carAttribute::WHEEL_RADIUS;
            else if (str == "AC_TEMP_MAX") return carAttribute::AC_TEMP_MAX;
            else if (str == "AC_TEMP_MIN") return carAttribute::AC_TEMP_MIN;
            else if (str == "WIND_LEVEL_MAX") return carAttribute::WIND_LEVEL_MAX;
            // else throw std::invalid_argument("Invalid string for carAttribute enum conversion");
        }

        throw std::invalid_argument("Unsupported enum type for string conversion");
    }
}

#endif /*  */
