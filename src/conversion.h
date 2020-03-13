/**
 * @file conversion.h
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief The header file of the conversion source file
 * @version 0.1
 * @date 2019-08-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#pragma once
//50==================================================
//c++ library
//50==================================================
#include <string>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <vector>


//50==================================================
//local header
//50==================================================
#include "global.h"
using namespace std;
//50==================================================



//50==================================================
//unit conversion
//50==================================================
double convert_from_kelvin_to_fahrenheit(double dTemperature_kelvin_in);
double convert_from_fahrenheit_to_kelvin(double dTemperature_fahrenheit_in);
double convert_from_joule_per_meter_to_calorie_per_centimeter(double dJoule_per_meter_in);
double convert_from_calorie_per_centimeter_to_joule_per_meter(double dCalorie_per_centimeter_in);

std::string convert_integer_to_string(int iNumber_in);
std::string convert_long_to_string(long iNumber_in);
std::string convert_integer_to_string(int iNumber_in,
	int iWidth_in);
std::string convert_double_to_string( double dNumber_in);
std::string convert_double_to_string(int iPrecision_in,
	int iWidth_in,
	double dNumber_in);


std::vector<std::string> split_string_by_space(std::string sString_in);
std::vector<std::string> split_string_by_delimiter(std::string sString_in, char cDelimiter_in);
