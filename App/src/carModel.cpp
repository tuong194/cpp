#include "carModel.h"
#include "my_log.h"

extern void read_data(carBranch branch, std::map<carAttribute, int>& data_map);

carModel::carModel(carBranch branch_):branch(branch_)
{
    LOGI("init car model");
    read_data(branch, data);
}