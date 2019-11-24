
/**
 * @file segment.cpp
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief 
 * @version 0.1
 * @date 2019-08-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "segment.h"

namespace hexwatershed
{
    segment::segment()
    {
      iFlag_headwater = 0;
      iSegment = 0;
      iSegment_order=-1;
      iSegment_downstream =-1;
      //iSegment_upstream=-1;
      iFlag_has_upstream = -1;
      iFlag_has_downstream=-1;
      nSegment_upstream =-1;

    }

    segment::~segment()
    {

    }
}
