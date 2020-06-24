/**
 * @file hexagon.h
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief The header file the hexagon class.
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
#include <vector>
#include <array>
#include "global.h"
#include "vertex.h"
using namespace std;
namespace hexwatershed
  {

      class hexagon
      {
      public:
          hexagon();

          ~hexagon();

          long lGlobalID;
          long lID;
          int iFlag_active;
          int iFlag_watershed;
          int iFlag_stream;
          int iFlag_first_reach;
          int iFlag_last_reach;
          int iFlag_headwater;
          int iFlag_neighbor;

          int iSegment;
          int iSegment_order;
          int iSubbasin;
          int iFlag_confluence;
          int nNeighbor;
          int nUpslope;
          int iSegment_downstream;

          int nVertex; //the vertex number from polygon
          //std::string sMeta;
          long lIndex_downslope;
          long lAccumulation;
            
          double dSlope;
          double dLength_edge;
          double dX; //map projection
          double dY; //map projection
          double dZ; 
          double dLatitude;
          double dLongitude;
          double dElevation;
          double dArea;
          double dTwi;

          std::vector<long> vNeighbor;
          std::vector<long> vUpslope;
          std::vector<long> vVertex_index;
          std::vector<vertex> vVertex;

      };

  }

