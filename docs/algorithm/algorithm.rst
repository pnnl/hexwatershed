#########
Algorithm
#########


********
Overview
********

HexWatershed includes major classicial watershed delineation algorithms with modifications.

These algorithms are implemented within both the Python front-end and the C++ back-end.


Flowline simplication
#####################

Flowline simplication is achieved through the PyFlowline Python package (`<https://anaconda.org/conda-forge/pyflowline>`_)



Mesh generation
###############

Mesh generation is achieved through the PyFlowline Python package (`<https://anaconda.org/conda-forge/pyflowline>`_)


Topological relationship reconstruction
#######################################

Topological relationship reconstruction is achieved through the PyFlowline Python package (`<https://anaconda.org/conda-forge/pyflowline>`_)

DEM resampling
##############

HexWatershed provides two resampling methods:

==================
Nearest resampling
==================

In the nearest resampling, the model defines the cell elevation in the following steps:

* obtain cell center location in **longitude** and **latitude**

* convert location into DEM row and column indices

* obtain DEM pixel value and assign as the cell elevation

=====================
Zonal mean resampling
=====================

In the zonal mean resampling, the model defines the cell elevation in the following steps:

* obtain all the cell vertex locations in **longitude** and **latitude**

* define a polygon using the vertex locations

* extract the DEM using the polygon

* calculate the mean extracted DEM and assign as the cell elevation






Stream burning
#######################################

A topological relationship-based stream burning algorithm is implemented in HexWatershed v3.0.

Depression filling
#######################################

In general, the depression filling algorithm is similar to that in the HexWatershed v1.0.

The major difference is related to the stream burning algorithm.



Flow direction
#######################################


Flow accumulation
#######################################

Stream grid
############################


Stream confluence
############################


Stream segment
############################


Subbasin
############################


Watershed
############################
