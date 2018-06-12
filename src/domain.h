//
// Created by Chang Liao on 4/26/18.
//

#ifndef HEXAGONHYDRO_DOMAIN_H
#define HEXAGONHYDRO_DOMAIN_H

#include <cmath>

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

#include "ogrsf_frmts.h"

#include "system.h"
#include "cell.h"
#include "conversion.h"

using namespace std;
namespace hexagon
  {
      class domain
        {
       public:

        domain();

        domain(std::string sFilename_configuration);

        ~domain();

        int iFlag_debug;
        int iFlag_configuration_file;

        double dResolution_elevation;
        double dX_origin;
        double dY_origin;
        int nColumn_elevation;
        int nRow_elevation;
        long nRecord_shapefile;

        std::string sFilename_configuration;
        std::string sWorkspace_data;
        std::string sFilename_elevation;
        std::string sFilename_shapefile;

        std::string sExtension_header;
        std::string sExtension_envi;
        std::string sExtension_text;
        std::map<std::string, std::string> mParameter; //for input data and parameters
        std::vector<cell> vCell;
        std::vector<cell> vCell_active;
        std::vector<cell> vCell_watershed;
        std::vector<float> vElevation;

        std::vector<cell>  domain_get_boundary( std::vector<cell> vCell_in);
int check_digital_elevation_model_depression(std::vector<cell> vCell_in);
        int domain_setup();

std::array<long, 2> find_lowest_cell(std::vector<cell> vCell_in);
        int domain_read_data();

        int domain_read_configuration_file();

        int domain_retrieve_user_input();

        int domain_delineate_watershed();
        int find_all_neighbors();

        int read_shapefile(std::string sFilename_shapefile);

        int read_digital_elevation_model(std::string sFilename_elevation);

        int read_all_cell_information(std::string sFilename_shapefile, std::string sFilename_elevation);

        };
  }

#endif //HEXAGONHYDRO_DOMAIN_H
