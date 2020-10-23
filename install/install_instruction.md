This document provides the steps to build the HexWatershed model.

It is possible to build and run the HexWatershed on Linux/Mac/Windows if your system meets the requirements:
* GCC 5.2.0 and above
* GDAL 2.3.1 

In this instruction, I only use a Linux machine as an example. For other platform, you need to adjust several files. 

Figures provided to illustrate the steps when needed.

* In the terminal, create a folder for this project
* Clone the repository into the folder with 
```
git clone git@github.com:pnnl/hexwatershed.git
```
* Create a folder outside the hexwatershed repository å
```å
mkdir CMake
```
* Go into the CMake folder and copy the CMakeLists.txt file from the repository into the CMake folder
```
cp ../hexwatershed/install/CMakeLists.txt  ./
```
* Open the CMakeLists.txt file and edit the path of gdal based on your system with your preferred editor.
The highlight rectangle is where you can change the gdal library.
![CMakeLists file](https://github.com/pnnl/hexwatershed/blob/master/install/figure/cmakelists.png?raw=true)

