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