
/**
 * @file depression.h
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief The depression header file
 * @version 0.1
 * @date 2019-08-02
 * @citation Liao, C., Tesfa, T., Duan, Z., & Leung, L. R. (2020). 
 * Watershed delineation on a hexagonal mesh grid. Environmental Modelling & Software, 104702.
 * https://www.sciencedirect.com/science/article/pii/S1364815219308278
 * @github page https://github.com/changliao1025/hexwatershed
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

#include <vector>

#include "hexagon.h"
namespace hexwatershed
{

class depression
{
    std::vector<hexagon> find_the_boundary(std::vector<hexagon> cCell);
    //this function is actually implemented within the domain class
    //it is possible to remove this class in future development
    int depression_fill(std::vector<hexagon> cCell);
};
} // namespace hexwatershed


