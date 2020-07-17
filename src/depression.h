
/**
 * @file depression.h
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief The depression header file
 * @version 0.1
 * @date 2019-08-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef HEXAGONHYDRO_DEPRESSION_H
#define HEXAGONHYDRO_DEPRESSION_H

#include <vector>

#include "hexagon.h"
namespace hexwatershed
{

class depression
{
    std::vector<hexagon> find_the_boundary(std::vector<hexagon> cCell);

    int depression_fill(std::vector<hexagon> cCell);
};
} // namespace hexwatershed

#endif //HEXAGONHYDRO_DEPRESSION_H
