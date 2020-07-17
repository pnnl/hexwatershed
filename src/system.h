/**
 * @file system.h
 * @author Chang Liao (chang.liao@pnnl.gov)
 * @brief 
 * @version 0.1
 * @date 2019-08-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once
//the global variables for all other modules
//c library
#include <limits.h>
#include <stdio.h>
#include <cstring>
//c++ library

#include <fstream>
#include <iostream>

#include <string>
//50==================================================
//cros-platform header
#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <direct.h>
#include <windows.h>
#ifdef _WIN64
//define something for Windows (64-bit only)
#else
//define something for Windows (32-bit only)
#endif
#elif __APPLE__
#include <sys/stat.h>
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#elif TARGET_OS_IPHONE
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#elif __linux__
// linux
#include <sys/stat.h>
#include <sys/types.h>
#elif __unix__ // all unices not caught above
// Unix
#elif defined(_POSIX_VERSION)
// POSIX
#else
#error "Unknown compiler"
#endif

//50==================================================
#include "global.h"

//50==================================================
using namespace std;
//50==================================================
//functions
//50==================================================

//50==================================================
//test whether a file exists or not
//50==================================================
int file_test(std::string sFilename);

//50==================================================
//make directory ()
//50==================================================
int make_directory(std::string sDirectory);

//50==================================================
//check whether a directory exists or not
//50==================================================
int path_test(std::string sPath);

int run_command(std::string sCommand);

long get_file_size(std::string sFilename);
