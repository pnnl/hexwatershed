//
// Created by Chang Liao on 4/26/18.
//

#include "domain.h"

namespace hexagon
  {

      domain::domain()
        {
        };

      domain::~domain()
        {
        };

      domain::domain(std::string sFilename_configuration_in)
        {
        iFlag_debug = 0;
        // check the length of the configuration file
        std::size_t iLength = sFilename_configuration_in.length();
        if (iLength < 5)
          {
          this->iFlag_configuration_file = 0;
          }
        else
          {
          std::cout << "The configuration file is:" << sFilename_configuration_in
                    << std::endl;
          // check the existence of the configuration file
          if (file_test(sFilename_configuration_in) !=
                  1) // the file does not even exist
            {
            this->iFlag_configuration_file = 0;
            }
          else
            {
            this->sFilename_configuration = sFilename_configuration_in;
            this->iFlag_configuration_file = 1;
            }
          }

        sExtension_header = ".hdr";
        sExtension_envi = ".dat";
        sExtension_text = ".txt";

        }

      int domain::domain_setup()
        {
        int error_code = 1;
        mParameter.insert(std::pair<std::string, std::string>("workspace_data",
                                                              sWorkspace_data)); //where most global data is stored
        mParameter.insert(std::pair<std::string, std::string>("elevation", sFilename_elevation));
        mParameter.insert(std::pair<std::string, std::string>("shapefile", sFilename_shapefile));
        return error_code;

        }

      int domain::domain_retrieve_user_input()
        {
        int error_code = 1;
        std::string sKey = "shapefile";
        auto search = mParameter.find(sKey);
        if (search != mParameter.end())
          {
          this->sFilename_shapefile = search->second;
          }
        sKey = "elevation";
        search = mParameter.find(sKey);
        if (search != mParameter.end())
          {
          this->sFilename_elevation = search->second;
          }
        return error_code;
        }

      int domain::domain_read_data()
        {
        int error_code = 1;

        read_all_cell_information(sFilename_shapefile, sFilename_elevation);
        return error_code;
        }

      int domain::domain_read_configuration_file()
        {
        int error_code = 1;
        std::size_t iVector_size;
        std::string sLine; //used to store each sLine
        std::string sKey; //used to store the sKey
        std::string sValue; //used to store the sValue
        std::ifstream ifs; //fstream object to read_eco3d the file
        std::vector<std::string> vTokens;
        //50==================================================
        //the existence of the configuration file is checked already
        //50==================================================
        ifs.open(sFilename_configuration.c_str(), ios::in);
        if (ifs.good())
          {
          std::cout << "Start to read_eco3d the configuration file" << std::endl;
          while (!ifs.eof()) //read_eco3d all the content
            {
            //reset sKey and sValue to null for each sLine
            sKey = "";
            sValue = "";
            //50==================================================
            //we should read_eco3d one sLine at a time and then break the sLine into substrings.
            //50==================================================
            std::getline(ifs, sLine); //read_eco3d the sLine
            std::size_t iLength0 = sLine.length();
            if (iLength0 <= 2)
              {
              continue;
              }
            //split the sLine
            vTokens = split_string_by_space(sLine);
            //test the size of the vector
            iVector_size = vTokens.size();
            if (iVector_size == 2)
              {
              sKey = vTokens[0]; //sKey holds the sKey(address)!
              sValue = vTokens[1]; //the real sValue of the sKey.
              }
            else
              {
              sKey = vTokens[0]; //sKey holds the sKey(address)!
              sValue = sKey;
              }
            //50==================================================
            //check the completeness of the sLine
            //50==================================================
            std::size_t iLength1 = sKey.length();
            std::size_t iLength2 = sValue.length();
            if (iLength1 >= 1 && iLength2 >= 1)  //both of them are not NULL
              {
              auto search = this->mParameter.find(sKey); //search the dictionary
              if (search != this->mParameter.end()) //if found, add the sValue to the sKey/address
                {
                search->second = sValue;

                }
              else
                {
                //if not, insert this sKey and sValue pair into user map
                //this map should be used to output control

                }
              }
            else
              {
              //this may be a empty sLine
              continue;
              }
            }
          //close the file after reading


          }
        else
          {
          error_code = 0;
          }
        ifs.close();

        return error_code;
        }

      int domain::check_digital_elevation_model_depression(std::vector<cell> vCell_in)
        {
        int error_code = 1;
        double dElevation_min;
        std::vector<cell>::iterator iIterator_self;

        std::vector<cell>::iterator iIterator1;

        std::vector<long> vNeighbor;
        std::vector<double> vElevation_neighbor;
        std::vector<long>::iterator iIterator2;
        long lID;
        double dElevation_self;
        for (iIterator_self = vCell_in.begin(); iIterator_self != vCell_in.end(); iIterator_self++)
          {
          vNeighbor = (*iIterator_self).vNeighbor;
          dElevation_self = (*iIterator_self).dElevation;
          vElevation_neighbor.clear();
          for (iIterator2 = vNeighbor.begin(); iIterator2 != vNeighbor.end(); iIterator2++)
            {
            lID = (*iIterator2);
//find it
            for (iIterator1 = vCell_in.begin(); iIterator1 != vCell_in.end(); iIterator1++)
              {
              if ((*iIterator1).lID == lID)
                {
                vElevation_neighbor.push_back((*iIterator1).dElevation);
                }
              else
                {
                continue;
                }
              }
            }
          //if it is the lowest?
          dElevation_min = *(std::min_element(vElevation_neighbor.begin(), vElevation_neighbor.end()));

          if (dElevation_self >= dElevation_min)
            {
            error_code = 0;
            }
          else
            {
            continue;
            }
          }


        return error_code;
        }

      std::vector<cell> domain::domain_get_boundary(std::vector<cell> vCell_in)
        {
        int error_code = 1;
        std::vector<cell>::iterator iIteratr1;

        std::vector<cell> vCell_out;
        for (iIteratr1 = vCell_in.begin(); iIteratr1 != vCell_in.end(); iIteratr1++)
          {
          if ((*iIteratr1).nNeighbor < 6)
            {
            vCell_out.push_back(*iIteratr1);
            }
          }

        return vCell_out;
        }

      int domain::domain_delineate_watershed()
        {
        int error_code = 1;
        int iFlag_finished = 0;
        std::vector<cell> vCell_dummy1;
        std::vector<cell> vCell_dummy2;
        std::queue<cell> qPit;
        //find all the neighbors first

        find_all_neighbors();

        iFlag_finished = check_digital_elevation_model_depression(vCell_active);
        vCell_dummy1 = vCell_active;
        while (iFlag_finished == 0)
          {
//filling
          //get boundary
          vCell_dummy2 = domain_get_boundary(vCell_dummy1);
          if(vCell_dummy2.size() >0 || qPit.size()>0)
            {


            
            }





          iFlag_finished = check_digital_elevation_model_depression(vCell_active);
          }


        return error_code;
        }

      int domain::find_all_neighbors()
        {
        int error_code = 1;
        int iFlag_minimal = 0;
        double dX_self;
        double dY_self;
        double dDummy_X;
        double dDummy_Y;
        double dDistance;
        double dDistance_min;
        std::vector<double> vDistance;
        //find all the neighbors first
        std::vector<cell>::iterator iIterator_self, iIterator2;
        std::vector<cell> vCell_copy1, vCell_copy2;
        long lIndex_self;
        long lIndex1, lIndex2;


        for (lIndex_self = 0; lIndex_self < vCell_active.size(); lIndex_self++)
          {
          dX_self = (vCell_active.at(lIndex_self)).dX;
          dY_self = (vCell_active.at(lIndex_self)).dY;
          for (lIndex1 = 0; lIndex1 < vCell_active.size(); lIndex1++)
            {
            if (lIndex_self == lIndex1)
              {
              //itself
              }
            else
              {
              dDummy_X = (vCell_active.at(lIndex1)).dX;
              dDummy_Y = (vCell_active.at(lIndex1)).dY;
              dDistance = sqrt((dDummy_X - dX_self) * (dDummy_X - dX_self)
                                       + (dDummy_Y - dY_self) * (dDummy_Y - dY_self));
              vDistance.push_back(dDistance);
              }
            }
          //get the minimal distance
          if (iFlag_minimal == 1)
            {
            //do nothing here
            }
          else
            {
            dDistance_min = *(std::min_element(vDistance.begin(), vDistance.end()));
            iFlag_minimal = 1;
            }

          for (lIndex2 = 0; lIndex2 < vCell_active.size(); lIndex2++)
            {
            if (lIndex_self == lIndex2)
              {
              //itself
              }
            else
              {
              dDummy_X = (vCell_active.at(lIndex2)).dX;
              dDummy_Y = (vCell_active.at(lIndex2)).dY;
              dDistance = sqrt((dDummy_X - dX_self) * (dDummy_X - dX_self)
                                       + (dDummy_Y - dY_self) * (dDummy_Y - dY_self));
              if (dDistance < (1.5 * dDistance_min))
                {
                //found one
                (vCell_active.at(lIndex_self)).vNeighbor.push_back(
                        (vCell_active.at(lIndex2)).lID
                );

                if ((vCell_active.at(lIndex_self)).vNeighbor.size() > 6)
                  {
                  std::cout << "Too many neightbors" << std::endl;
                  }
                }
              //use priority_queue later
              }
            }


          }


        return error_code;
        }

      int domain::read_all_cell_information(std::string sFilename_shapefile, std::string sFilename_elevation)
        {
        int error_code = 1;
        long lRecord;
        double dDummy_X, dDummy_Y;
        long lIndex;
        long lColumn_index, lRow_index;
        cell cCell;
        std::vector<cell>::iterator iIterator;
        read_shapefile(sFilename_shapefile);

        read_digital_elevation_model(sFilename_elevation);

        //get elevation for each point

        for (lRecord = 0; lRecord < nRecord_shapefile; lRecord++)
          {
          dDummy_X = vCell.at(lRecord).dX;
          dDummy_Y = vCell.at(lRecord).dY;

          //calculate location

          lColumn_index = round((dDummy_X - dX_origin) / dResolution_elevation);
          lRow_index = round((dY_origin - dDummy_Y) / dResolution_elevation);
          lIndex = lRow_index * nColumn_elevation + lColumn_index;

          if (lColumn_index >= 0 && lColumn_index < nColumn_elevation
                  && lRow_index >= 0 && lRow_index < nRow_elevation)
            {
            //within the range
            if (vElevation.at(lIndex) == missing_value)
              {
              vCell.at(lRecord).dElevation = missing_value;
              vCell.at(lRecord).iFlag_active = 0;
              }
            else
              {
              vCell.at(lRecord).dElevation = vElevation.at(lIndex);
              vCell.at(lRecord).iFlag_active = 1;
              }
            }
          else
            {
            //out of bound
            vCell.at(lRecord).dElevation = -9999.0;
            vCell.at(lRecord).iFlag_active = 0;
            }

          }


        for (iIterator = vCell.begin(); iIterator != vCell.end(); iIterator++)
          {

          if ((*iIterator).iFlag_active == 1)
            {
            vCell_active.push_back(*iIterator);
            }

          }
        return error_code;

        }

      int domain::read_digital_elevation_model(std::string sFilename_elevation)
        {
        int error_code = 1;
        GDALAllRegister();
        float *pData;
        int nXSize;
        int nYSize;
        GDALRasterBand *poBand;
        int nBlockXSize, nBlockYSize;
        int bGotMin, bGotMax;
        double adfMinMax[2];
        GDALDataset *poDS_elevation;
        double adfGeoTransform[6];
        poDS_elevation = (GDALDataset *) GDALOpen(sFilename_elevation.c_str(),
                                                  GA_ReadOnly);
        if (poDS_elevation == NULL)
          {
          printf("Open failed.\n");
          error_code = 0;
          }
        else
          {

          printf("Driver: %s/%s\n",
                 poDS_elevation->GetDriver()->GetDescription(),
                 poDS_elevation->GetDriver()->GetMetadataItem(GDAL_DMD_LONGNAME));
          printf("Size is %dx%dx%d\n",
                 poDS_elevation->GetRasterXSize(), poDS_elevation->GetRasterYSize(),
                 poDS_elevation->GetRasterCount());
          if (poDS_elevation->GetProjectionRef() != NULL)
            {
            printf("Projection is `%s'\n", poDS_elevation->GetProjectionRef());
            }
          if (poDS_elevation->GetGeoTransform(adfGeoTransform) == CE_None)
            {
            printf("Origin = (%.6f,%.6f)\n",
                   adfGeoTransform[0], adfGeoTransform[3]);
            printf("Pixel Size = (%.6f,%.6f)\n",
                   adfGeoTransform[1], adfGeoTransform[5]);

            //-759,672.880  -20,367.788 Meters
            this->dX_origin = adfGeoTransform[0];
            this->dY_origin = adfGeoTransform[3];
            this->dResolution_elevation = adfGeoTransform[1];

            }
          poBand = poDS_elevation->GetRasterBand(1);
          poBand->GetBlockSize(&nBlockXSize, &nBlockYSize);
          printf("Block=%dx%d Type=%s, ColorInterp=%s\n",
                 nBlockXSize, nBlockYSize,
                 GDALGetDataTypeName(poBand->GetRasterDataType()),
                 GDALGetColorInterpretationName(
                         poBand->GetColorInterpretation()));
          adfMinMax[0] = poBand->GetMinimum(&bGotMin);
          adfMinMax[1] = poBand->GetMaximum(&bGotMax);
          if (!(bGotMin && bGotMax))
            GDALComputeRasterMinMax((GDALRasterBandH) poBand, TRUE, adfMinMax);
          printf("Min=%.3fd, Max=%.3f\n", adfMinMax[0], adfMinMax[1]);
          if (poBand->GetOverviewCount() > 0)
            printf("Band has %d overviews.\n", poBand->GetOverviewCount());
          if (poBand->GetColorTable() != NULL)
            printf("Band has a color table with %d entries.\n",
                   poBand->GetColorTable()->GetColorEntryCount());

          nXSize = poBand->GetXSize();
          nYSize = poBand->GetYSize();

          this->nColumn_elevation = nXSize;
          this->nRow_elevation = nYSize;

          pData = (float *) CPLMalloc(sizeof(float) * nXSize * nYSize);

          poBand->RasterIO(GF_Read,
                           0, 0, nXSize, nYSize,
                           pData, nXSize, nYSize,
                           GDT_Float32,
                           0, 0);
          //convert to vector
          std::vector<float> vDummy(pData, pData + (nXSize * nYSize));

          vElevation = vDummy;

          GDALClose(poDS_elevation);

          }

        return error_code;
        }

      int domain::read_shapefile(std::string sFilename_shapefile)
        {
        int error_code = 1;
        int nField;
        long lCellID = 0;
        GDALAllRegister();
        GDALDataset *poDS_shapefile;
        OGRLayer *poLayer;
        OGRFeatureDefn *poFDefn;
        OGRFeature *poFeature;
        OGRFieldDefn *poFieldDefn;
        poDS_shapefile = (GDALDataset *) GDALOpenEx(sFilename_shapefile.c_str(),
                                                    GDAL_OF_VECTOR,
                                                    NULL, NULL, NULL);
        if (poDS_shapefile == NULL)
          {
          printf("Open failed.\n");
          error_code = 0;
          }
        else
          {
          poDS_shapefile->GetLayerCount();
          poLayer = poDS_shapefile->GetLayer(0);
          poLayer->ResetReading();
          poFDefn = poLayer->GetLayerDefn();
          nField = poFDefn->GetFieldCount();
          cell cCell;
          while ((poFeature = poLayer->GetNextFeature()) != NULL)
            {
            for (int iField = 0; iField < nField; iField++)
              {
              switch (iField)
                {
                case 0:
                  cCell.lGlobalID = poFeature->GetFieldAsInteger64(iField);
                  break;
                case 1:
                  cCell.dX = poFeature->GetFieldAsDouble(iField);
                  break;
                case 2:
                  cCell.dY = poFeature->GetFieldAsDouble(iField);
                  break;
                case 3:
                  cCell.lID = lCellID;
                  break;
                case 4:
                  cCell.iFlag_active = 0;
                  break;
                default:
                  cCell.sMeta = "";
                  //poFeature->GetFieldAsString (iField);
                  break;
                }
              }
            vCell.push_back(cCell);
            lCellID = lCellID + 1;
            }
          }

        nRecord_shapefile = lCellID;
        return error_code;
        }
  }