############
Installation
############


********
Overview
********

HexWatershed was originally released in C++ 11.

Since HexWatershed v3.0, it was redesigned using a Hybrid Python and C++ approach. Only the HexWatershed v3.0 will be maintained and supported.

************
Requirements
************

It is possible to build the HexWatershed on Linux/Mac/Windows if your system can support both the C++ and Python environments:



C++ Requirements
################

=====
CMake
=====

cmake (v3.1.0 and above) is used to generate the makefile.

- Linux: cmake can be installed through a package manager. If you are on a Linux HPC, you administration should have already installed in most cases.

- Mac: cmake can be installed through Homebrew (https://brew.sh/): https://formulae.brew.sh/formula/cmake

- Windows: cmake can be installed following the instruction from hexwatershed (https://cmake.org/download/).


===
GCC
===

GCC (v8.1.0 and above) is used to compile the C++ source code.

Similar to cmake, you can install GCC on linux or Mac.

- Linux: gcc can be installed through a package manager.

- Mac: gcc can be installed through Homebrew (https://formulae.brew.sh/formula/gcc).

- Windows: gcc can be installed using either Cygwin or MinGW (https://gcc.gnu.org/install/binaries.html).

A Linux version CMakeLists file is provided as an example. Two optional bash scripts are provided to assist this process.


Python Requirements
###################
=====
CMake
=====

***********
Instruction 
***********

- In the terminal, create a folder for this project
- Clone the repository into the folder with::

    git clone git@github.com:pnnl/hexwatershed.git
 
- Create a folder outside the hexwatershed repository::
 
    mkdir CMake
 
- Go into the CMake folder and copy the CMakeLists.txt file from the repository into the CMake folder::
 
    cp ./installation/figure/CMakeLists.txt  ./
    cp ./installation/figure/cmake.sh  ./
    cp ./installation/figure/make.sh  ./
 
You should also change the permission of the bash files::
 
    chmod 755 cmake.sh
    chmod 755 make.sh
 
- Open the CMakeLists.txt file and edit the path of gdal based on your system with your preferred editor.

The highlight rectangle is where you can change the gdal library.



- Run the cmake bash script to load modules and run the cmake command::
 
    ./cmake.sh
 


This script should generates some results as follow:

- Run the make bash file::
 
    ./make.sh




This script should generates some results as follow:



- By now, your build should be successful if you receive no errors. And you will see the binary file in the CMake folder and another one within the repository as well.



Congratulations, you have successfully built the HexWatershed model!

Now you can test the model with the example following this instruction: https://github.com/pnnl/hexwatershed/tree/master/example
