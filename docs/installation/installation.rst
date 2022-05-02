############
Installation
############


********
Overview
********



**HexWatershed** was originally released in C++ 11.

Since HexWatershed v3.0, it was redesigned using a **hybrid** Python (front-end) and C++ (back-end) approach. 
Only the HexWatershed v3.0 will be maintained and supported.

The Python front-end is used to generate the mesh, build the topological relationship, and a list of other pre and post-processing algorithms.

The C++ back-end is used to run the core HexWatershed model.

************
Requirements
************

It is possible to build the HexWatershed on Linux/Mac/Windows if your system can support both the C++ and Python environments:

C++ Requirements
################


=====
CMake
=====

**cmake** (v3.1.0 and above) is used to generate the makefile.

- Linux: cmake can be installed through a package manager. If you are on a Linux HPC, you administration should have already installed in most cases.

- Mac: cmake can be installed through Homebrew (`<https://brew.sh/>`_): `<https://formulae.brew.sh/formula/cmake/>`_

- Windows: cmake can be installed following the instruction from hexwatershed (`<https://cmake.org/download/>`_).


===
GCC
===

**GCC** (v8.1.0 and above) is used to compile the C++ source code.

Similar to cmake, you can install GCC on linux or Mac.

- Linux: gcc can be installed through a package manager.

- Mac: gcc can be installed through Homebrew (`<https://formulae.brew.sh/formula/gcc>`_).

- Windows: gcc can be installed using either Cygwin or MinGW (`<https://gcc.gnu.org/install/binaries.html>`_).

A Linux version CMakeLists file is provided as an example. Two optional bash scripts are provided to assist this process.


Python requirements
###################

=====
Conda
=====
The **Conda** platform is recommended to install the dependency Python package.
Conda can be installed throught either `<https://docs.conda.io/en/latest/miniconda.html>`_
or 
`<https://anaconda.org/>`_.


======
Python
======
**Python** (3.8 and above) is required to run the Python package.
It can be installed using the conda tool.

===
Pip
===
The Python **pip** is used to install the HexWatershed Python package.
Pip is installed along with the Python.


Step by step instruction 
########################

Only an exmaple on Mac is provided below:

- Open the terminal, cd to a desired directory and create a folder for this project::
    
    mkdir hexwatershed_tutorial

    cd hexwatershed_tutorial

- Clone the repository into the current folder and go inside it::

    git clone https://github.com/changliao1025/hexwatershed.git

    cd hexwatershed
 
- Go into the build folder and run cmake::

    cd build

    cmake CMakeLists.txt  
 
- Build and install the HexWatershed C++ program::

    make install

- Create the conda environment for the HexWatershed and activate it::

    conda create --name hexwatershed python=3.8

    conda activate hexwatershed

- Install the dependency Python package pyflowline::

    conda install -c conda-forge pyflowline

- Install the Python package using pip::

    pip install hexwatershed

By now, your should have installed both the C++ and Python components of the HexWatershed model.

Next, you can test the model with the example following this instruction.
`<https://github.com/changliao1025/pyhexwatershed/>`_


