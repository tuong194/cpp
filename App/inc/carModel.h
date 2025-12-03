#ifndef CAR_MODEL_H__
#define CAR_MODEL_H__

#include "Define.h"
#include <map>


class carModel
{
private:
    carBranch branch;
    std::map<carAttribute, int> data;
public:
    carModel(carBranch branch);
    ~carModel() {};

    int getTempMax(){return data[carAttribute::AC_TEMP_MAX];}
    int getTempMin(){return data[carAttribute::AC_TEMP_MIN];}
    int getMaxWindLevel(){return data[carAttribute::WIND_LEVEL_MAX];}
};




#endif /*  */
