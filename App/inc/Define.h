#ifndef DEFINE_H__
#define DEFINE_H__

#include <stdexcept>
#include <type_traits>
#include <string>

enum class DriveMode
{
    ECO,  // Chế độ tiết kiệm năng lượng
    SPORT, // Chế độ thể thao
};

enum class SystemAttribute
{
    VEHICLE_SPEED, // tốc độ xe
    DRIVE_MODE, // chế độ lái
    GEAR_SHIFT, // 
    TURN_SIGNAL,
    ROUTE_PLANNER,
    BATTERY_LEVEL,// phần trăm pin
    ODOMETER, // công tơ mét
    BRAKE, // phanh
    ACCELERATOR,
    BATTERY_TEMP, // nhiệt độ pin
    AC_CONTROL,
    AC_STATUS,
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
        throw std::invalid_argument("Unsupported enum type for string conversion");
    }
}

#endif /*  */
