/**
 * @file system.h
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief Provide interface to the hexagon vertex 
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
#include <string>
#include "global.h"
using namespace std;
namespace hexwatershed
{
class vertex
{
     public:
      vertex();

    ~vertex();
    long lIndex;
    double dX ; //map projection
    double dY ; //map projection
    double dZ ; //elevation of VTK
    bool operator==(const vertex &cVertex);
};
} // namespace hexwatershed