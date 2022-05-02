###########
Application
###########


********
Overview
********

The recommended approach to run a HexWatershed simulation is through the Python package interface.

**************
Data structure
**************

HexWatershed uses the JavaScript Object Notation (JSON) file format for model configuration and data exchange.

The input data includes:

* A ESRI shapefile that defines the domain boundary

* A ESRI shapefile that defines the original river network

* A raster Geotiff file that contains the digital elevation model (DEM) data



Note that depending on the configuration, not all the input files are needed, or additional input files are needed.

****************
Data preparation
****************


Boundary
########

The domain boundary file can be defined using a vector-based watershed boundary file.

River network
################

The river network file can be defined using a vector-based river flowline file.

Because the real-worlkd river network is often complex, some simplication is recommended. For example, the river network should only include major flowlines.


DEM
###

The DEM file can be extracted from a large DEM which contains the study domain.


****************
Model simulation
****************

The easiest way to setup a simulation is to use an existing template. You can also generate an emtpy template using the provided APIs.

Then you can edit the template by replacing with the actual input filenames and paths.

Last, you can run the model through the Python APIs.


******************
Simulation results
******************

After the simulation is finished, you should obtain a list of fils within the output directory. Depending on the configuration, not all files will be outputed.

* depression filled DEM

* flow direction

* flow accumulation

* stream segment

* stream order

* subbasin boundary

* watershed boundary

These files are saved using the GeoJSON file format.


You can use any GIS tools (ArcGIS, ENVI, and QGIS, etc.) to visualize the results.


