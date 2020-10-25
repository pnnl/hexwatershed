This document provides the steps to build the HexWatershed model.

It is possible to build and run the HexWatershed on Linux/Mac/Windows if your system meets the requirements:
* cmake 3.1.0
* GCC 5.2.0 and above
* GDAL 2.3.1 

In this instruction, I only use a Linux machine as an example. For other platform, you need to adjust three files. 
1. CMakeLists.txt
2. cmake.sh
3. make.sh

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
cp ../hexwatershed/install/cmake.sh  ./
cp ../hexwatershed/install/make.sh  ./
```
You should also change the permission of the bash files.
```
chmod 755 cmake.sh
chmod 755 make.sh
```
* Open the CMakeLists.txt file and edit the path of gdal based on your system with your preferred editor.
The highlight rectangle is where you can change the gdal library.
![CMakeLists file](https://github.com/pnnl/hexwatershed/blob/master/install/figure/cmakelists.png?raw=true)
* Run the cmake bash script to load modules and run the cmake command
![Run cmake](https://github.com/pnnl/hexwatershed/blob/master/install/figure/cmake.png?raw=true)
```
./cmake.sh
```
![Run make](https://github.com/pnnl/hexwatershed/blob/master/install/figure/cmake_result.png?raw=true)
* Run the make bash file 
![Run make](https://github.com/pnnl/hexwatershed/blob/master/install/figure/make.png?raw=true)
```
./make.sh
```
![Run make](https://github.com/pnnl/hexwatershed/blob/master/install/figure/make_result.png?raw=true)
* By now, your build should be successful if you receive no errors. And you will see the binary file in the CMake folder and another one within the repository as well.
![Installation output](https://github.com/pnnl/hexwatershed/blob/master/install/figure/final.png?raw=true)
