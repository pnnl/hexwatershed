
/**
 * @file data.h
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief The header of data I/O component source code.
 * @version 0.1
 * @date 2017-01-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

//50==================================================
//C header
//50==================================================
//C++ header
#include <algorithm>
#include <array>  //the small sized array
#include <fstream> //file stream
#include <iterator> //for vector and stream
#include <string> //c++ string
#include <vector> //vector
#include "gdal.h"
#include "system.h"
//50==================================================
using namespace std;
//50==================================================
class data
{
 public:
  data();
  ~data();
  //50==================================================
  //Traditional data IO
  //50==================================================
  static float * read_binary(std::string sFilename_in);
  static float ** read_binary(std::string sFilename_in,
                              long lColumn_in,
                              long lRow_in);
  static std::vector<double> read_binary_vector(std::string sFilename_in);
  static int write_binary_vector(std::string sFilename_in,
                                 vector <double> vData_in);
  //50==================================================
  //advanced data io using MPI
  //dataIO using PETSc
  //50==================================================
  //Mat Read_Binary(string filErtame,int m,int n);
  //50==================================================
};
