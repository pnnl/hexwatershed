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

*******************
Model configuration
*******************

HexWatershed (as well as its submodule **PyFlowline**) uses two **JSON** files (main and basin) as the configuration files.

Main configuration
##################

The main configuration JSON file contains the domain scale parameters.
Each domain may contain one or more basins.

.. list-table:: Main configuration JSON file
   :widths: 25 25 25 25
   :header-rows: 1

   * - Keyword
     - Data type
     - Value
     - Description
   * - sFilename_model_configuration
     - string
     - 
     - The full path to the main configuration file
   * - sModel
     - string
     - "hexwatershed"
     - The model name
   * - sRegion
     - string
     - 
     - The study region
   * - sWorkspace_bin
     - string
     - 
     - The directory of the complied HexWatershed binary
   * - sWorkspace_input
     - string
     - 
     - The directory of the input
   * - sWorkspace_output
     - string
     - 
     - The directory of the output
   * - sJob
     - string
     - 
     - The job name for HPC   
   * - iFlag_create_mesh
     - int
     - 0 or 1
     - Flag to generate mesh 
   * - iFlag_save_mesh
     - int
     - 0 or 1
     - Flag to save mesh 
   * - iFlag_simplification
     - int
     - 0 or 1
     - Flag for flowline simplication 
   * - iFlag_intersect
     - int
     - 0 or 1
     - Flag to flowline mesh intersection
   * - iFlag_resample_method
     - int
     - 1 or 2
     - Method for DEM resampling 
   * - iFlag_flowline
     - int
     - 0 or 1
     - Flag for flowline 
   * - iFlag_global
     - int
     - 0 or 1
     - Flag for global simulation 
   * - iFlag_multiple_outlet
     - int
     - 0 or 1
     - Flag for multiple basin simulation   
   * - iFlag_use_mesh_dem
     - int
     - 0 or 1
     - Flag to use DEM within the mesh
   * - iFlag_elevation_profile
     - int
     - 0 or 1
     - Flag to turn on elevation profile 
   * - iFlag_rotation
     - int
     - 0 or 1
     - Flag for mesh generation using rotation 
   * - iFlag_stream_burning_topology
     - int
     - 0 or 1
     - Flag to turn on stream burning topology
   * - iFlag_save_elevation
     - int
     - 0 or 1
     - Flag to save elevation 
   * - iCase_index
     - int
     - 
     - ID of case
   * - iMesh_type
     - int
     - 1 to 5
     - Mesh type 
   * - dMissing_value_dem
     - float
     - 
     - The missing value in the DEM
   * - dBreach_threshold
     - float
     - 
     - The threshold parameter for the hybrid breaching filling algorithm
   * - dAccumulation_threshold
     - float
     - 
     - The accumulation parameter to define stream cell
   * - dLongitude_left
     - float
     - 0 or 1
     - The domain left boundary
   * - dLongitude_right
     - float
     - 
     - The domain right boundary
   * - dLatitude_bot
     - float
     - 
     - The domain bottom boundary
   * - dLatitude_top
     - float
     - 
     - The domain top boundary
   * - dResolution_degree
     - float
     - 
     - Mesh resolution in degree
   * - dResolution_meter
     - float
     - 
     - Mesh resolution in meter
   * - sDate
     - string
     - 
     - The date of the simulation
   * - sMesh_type
     - string
     - hexagon
     - The mesh type
   * - sFilename_hexwatershed
     - string
     - 
     - The filename of the binary 
   * - sFilename_spatial_reference
     - string
     - 
     - The spatial reference of the river network 
   * - sFilename_dem
     - string
     - 
     - The filename of the DEM
   * - sFilename_mesh_netcdf
     - float
     - 
     - The filename of the MPAS netcdf file
   * - sFilename_basins
     - string
     - 
     - The full path of the basin configuration file 

Basin configuration
###################

The basin configuration file contains one or more block of JSON basin object. Each block contains the configuration to a unique basin. Different basin may have different parameters.


.. list-table:: Basin configuration JSON file
   :widths: 25 25 25 25
   :header-rows: 1

   * - Keyword
     - Data type
     - Value
     - Description
   * - dLatitude_outlet_degree
     - float
     - 
     - The outlet latitude
   * - dLongitude_outlet_degree
     - float
     - 0 or 1
     - The outlet longitude 
   * - dAccumulation_threshold
     - float
     - 
     - The accumulation parameter to define the stream cell
   * - dThreshold_small_river
     - float
     - 
     - The threshold parameter to remove small river 
   * - iFlag_dam
     - int
     - 0
     - Reserved for dam burning
   * - iFlag_disconnected
     - int
     - 0
     - Reserved for disconnected flowline
   * - lBasinID
     - long
     - 
     - The basin ID
   * - sFilename_dam
     - string
     - 
     - Reserved for dam burning
   * - sFilename_flowline_filter
     - string
     - 
     - The filename of the stream vector 
   * - sFilename_flowline_raw
     - string
     - 
     - The filename of the raw stream vector 
   * - sFilename_flowline_topo
     - string
     - 
     - Reserved for dam burning

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



********
Tutorial
********

A full tutorial is provide at `<https://github.com/changliao1025/hexwatershed_tutorial>`_
