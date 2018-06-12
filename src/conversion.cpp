  //50==================================================
/*!
  \file   conversion.cpp
  \brief

  <long description>

  \author Chang Liao
  \date   2016-10-06
*/
  //50==================================================
#include "conversion.h"

  //50==================================================
//it is used to convert integer to string since c++ 11 doesn't support well
  //50==================================================

std::string convert_integer_to_string(int iNumber_in)
{
	std::string str_out;
	std::stringstream ss;
	ss << iNumber_in;
	str_out = ss.str();
	return str_out;
}

std::string convert_integer_to_string(int iNumber_in,
	int iWidth_in
)
{
	std::string str_out ;
	std::stringstream ss;
	ss << setfill('0') << setw(iWidth_in) << iNumber_in;
	str_out = ss.str();
	return str_out;
}
std::string convert_double_to_string(int iPrecision_in,
	int iWidth_in,
	double dNumber_in
)
{
	std::string str_out ;
	std::stringstream ss;
	ss << std::fixed << std::setw(iWidth_in) << std::setprecision(iPrecision_in) << dNumber_in;
	str_out = ss.str();
	return str_out;
}


double convert_from_kelvin_to_fahrenheit(double dTemperature_kelvin_in)
{
	double dTemperature_celsius = dTemperature_kelvin_in + kelvin_2_celsius;
	double dTemperature_fahrenheit_out = dTemperature_celsius * 1.8 + 32.0;
	return dTemperature_fahrenheit_out;
}
double convert_from_fahrenheit_to_kelvin(double dTemperature_fahrenheit_in)
{
	double dTemperature_celsius = (dTemperature_fahrenheit_in - 32.0) / 1.8;
	double dTemperature_kelvin_out = dTemperature_celsius - 273.15;
	return dTemperature_kelvin_out;
}
double convert_from_joule_per_meter_to_calorie_per_centimeter(double dJoule_per_meter_in)
{
	double dCalorie_per_meter = dJoule_per_meter_in * joule_2_calorie;
	double dCalorie_per_centimeter_out = dCalorie_per_meter / 10000.0;
	return dCalorie_per_centimeter_out;
}

double convert_from_calorie_per_centimeter_to_joule_per_meter(double dCalorie_per_centimeter_in)
{
	double dCalorie_per_meter = dCalorie_per_centimeter_in * 10000;
	double dJoule_per_meter_out = dCalorie_per_meter * calorie_2_joule;
	return dJoule_per_meter_out;
}

  //50==================================================
/*!
  <long-description>

  \param sString_in
*/
  //50==================================================

std::vector<std::string> split_string_by_space(std::string sString_in)
{
	std::size_t lLength = sString_in.length();
	if (lLength > 0)
	{
		std::istringstream iss(sString_in);
		std::istream_iterator<std::string> iterator_begin(iss), iterator_end;
		std::vector<std::string> vTokens_out(iterator_begin, iterator_end); // done!
		return vTokens_out;
	}
	else
	{
		std::vector<std::string> nothing;
		return nothing;
	}
}

  //50==================================================
/*!
  <long-description>

  \param sString_in
  \param cDelimiter
*/
  //50==================================================

std::vector<std::string> split_string_by_delimiter(std::string sString_in,
	char cDelimiter)
{
	std::size_t lLength = sString_in.length();
	std::vector<std::string> vTokens_out;
	if (lLength > 0)
	{
		std::stringstream ss;
		ss.str(sString_in);
		std::string dummy;
		while (std::getline(ss, dummy, cDelimiter))
		{
			vTokens_out.push_back(dummy);
		}

	}
	else
	{

	}
	return vTokens_out;
}
