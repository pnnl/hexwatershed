//
// Created by Chang Liao on 4/26/18.
//

#ifndef HEXAGONHYDRO_CELL_H
#define HEXAGONHYDRO_CELL_H

#include <string>
#include <vector>
#include <array>

using namespace std;
namespace hexagon
  {


      class cell
        {
       public:
        long lGlobalID;
        long lID;
        int iFlag_active;
        int nNeighbor;
        std::string sMeta;



        double dX;
        double dY;
        double dLatitude;
        double dLongitude;
        double dElevation;

        std::array<long, 6> aNeighbor;
        std::vector<long> vNeighbor;

        };


  }

#endif //HEXAGONHYDRO_CELL_H
