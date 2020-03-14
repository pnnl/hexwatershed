
/**
 * @file hexagon.cpp
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief 
 * @version 0.1
 * @date 2019-06-11Created by Chang Liao on 4/26/18.
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "hexagon.h"

namespace hexwatershed
{

hexagon::hexagon()
{
  iFlag_confluence = 0;
  iFlag_active = 0;
  iFlag_watershed = 0;
  iFlag_first_reach = 0;
  iFlag_last_reach = 0;
  iFlag_headwater = 0;
  lIndex_downslope = -1;

  lAccumulation = 0; // 0
  iSubbasin = -1;
  iSegment = -1;
  iSegment_order = -1;
  iSegment_downstream = -1;
  nUpslope = 0;

  nVertex = -1;
  dElevation = -9999.0;
  dZ = -9999.0;
  //dLength_edge = 500; //this should be read from the user configuration
  dTwi = 0.0;
}

hexagon::~hexagon()
{
}
} // namespace hexwatershed