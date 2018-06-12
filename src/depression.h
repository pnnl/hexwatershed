//
// Created by Chang Liao on 4/26/18.
//

#ifndef HEXAGONHYDRO_DEPRESSION_H
#define HEXAGONHYDRO_DEPRESSION_H

#include <vector>

#include "cell.h"
namespace hexagon
    {

        class depression
            {
std::vector<cell> find_the_boundary(std::vector<cell> cCell);


int depression_fill(std::vector<cell> cCell);
            };
    }


#endif //HEXAGONHYDRO_DEPRESSION_H
