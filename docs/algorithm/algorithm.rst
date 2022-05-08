#########
Algorithm
#########


********
Overview
********

HexWatershed includes major classicial watershed delineation algorithms with modifications.

These algorithms are implemented within both the Python frontend and the C++ backend.

**********
Algorithms
**********


Distance
########

Distance is calculated using the great-circle distance, orthodromic distance, or spherical distance is the distance along a great circle.

Area
####

A closed geometric figure on the surface of a sphere which is formed by the arcs of great circles.

Angle
#####

A spherical angle is a particular dihedral angle; it is the angle between two intersecting arcs of great circles on a sphere.

Flow simplication
#################

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
##############

A topological relationship-based stream burning algorithm is implemented in HexWatershed v3.0. 

Depression filling
##################

In general, the depression filling algorithm is similar to that in the HexWatershed v1.0.

The major difference is related to the stream burning algorithm.


Flow direction
##############

The flow direction is defined based on elevation differences and distances.

Currently, only the deepest slope is used to define the single flow direction.

Multi-flow directions will be supported in future versions.


Flow accumulation
#################

The actual drainage area is used instead of flow accumulation cell number. This is because each cell may have different cell area.

Stream grid
###########

The flow accumulation threshold is used to define the stream grid.


River confluence
#################

If a stream grid has more than one upstream, this stream grid is defined as a river confluence.


Stream segment
##############

Each individual stream line between headwater-confluence is defined as a stream segment


Subbasin
########

All the cells that contributes to a stream segment are used to define a subbasin.


Watershed
#########

All the cells that contributes to a river outlet are used to define a watershed.
