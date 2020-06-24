/**
 * @file watershed.h
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief This class provide interface to watershed characteristics, 
 * @version 0.1
 * @date 2019-08-02
 *  @citation Liao, C., Tesfa, T., Duan, Z., & Leung, L. R. (2020). 
 * Watershed delineation on a hexagonal mesh grid. Environmental Modelling & Software, 104702.
 * https://www.sciencedirect.com/science/article/pii/S1364815219308278
 * @github page https://github.com/changliao1025/hexwatershed
 * @copyright Copyright (c) 2019
 * 
 */



#include <vector>
#include "hexagon.h"
using namespace std;

namespace hexwatershed
    {
        //some improvements are needed in next development
        class watershed
            {

                std::vector<hexagon> vCell;
            };
    }


