#include "vertex.h"
namespace hexwatershed
{

vertex::vertex()
{
    lIndex = 0;
    dX = -9999; //map projection
    dY = -9999; //map projection
    dZ = -9999; //elevation of VTK
}
vertex::~vertex()
{
}

bool operator==(const vertex &cVertex)
{
    if (this.dX == cVertex.dX && this.dY == cVertex.dY)
    {
        return true;
    }
    else
    {
        return false;
    }
}
} // namespace hexwatershed