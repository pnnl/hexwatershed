# Overview
This document provides the instruction to run a HexWatershed model simulation.

# Data structure

HexWatershed uses a text based file as model input.
Within this text file, each line represents a model configuration.
An example of such a text file is provided here: https://github.com/pnnl/hexwatershed/tree/master/example/columbia_basin_flat/input/cbf.meta

The content of this text file is as follow:
![Model input](https://github.com/pnnl/hexwatershed/blob/master/example/figure/cbfmeta.png?raw=true)

At each line, the configuration parameter is defined using a key-value pair, which is separated by a comma ",".

The program retrieves these information and defines all the model inputs using a look-up table.

| key  |  Usage |
|---|---|
|  sWorkspace_data |  The parent directory of input data |
| sWorkspace_output  |  The output directory |
|  sFilename_hexagon_polygon_shapefile |  The file name of the hexagon mesh |
| sFilename_elevation_raster | The file name of the DEM raster in geotiff format|
|iCase| The case index|
|dAccumulation_threshold| The threshold to define stream grid |

The program combines file name and directory to obtain the full path of actual file. For example, the actual DEM file will be constructed as: 
```
sFilename_elevation_raster = sWorkspace_data + slash + "raster" + slash + sFilename_elevation_raster;
```
You need to strictly follow the file system tree structure when preparing your own simulation cases.

In HexWatershed 1.0, the dAccumulation_threshold is the flow accumulation threshold (https://pro.arcgis.com/en/pro-app/tool-reference/spatial-analyst/identifying-stream-networks.htm).

# Data preparation
In HexWatershed 1.0, only the DEM raster and hexagon mesh shapefile are needed as input files.

The DEM raster and mesh shapefile must have the same spatial projection and spatial extent.
This can be done using the following steps:
1. Download a watershed boundary shapefile of the study area.
If your study area is in the USA, you can use the USGS Watershed Boundary Datasets (WBD). (https://www.usgs.gov/core-science-systems/ngp/national-hydrography/watershed-boundary-dataset?qt-science_support_page_related_con=4#qt-science_support_page_related_con)

2. Creating a buffer zone around the boundary shapefile. This can be done using either ArcGIS program (https://desktop.arcgis.com/en/arcmap/10.3/manage-data/creating-new-features/creating-a-buffer-around-a-feature.htm) or QGIS (https://docs.qgis.org/2.8/en/docs/gentle_gis_introduction/vector_spatial_analysis_buffers.html).

3. Download the DEM raster covering the entire study area buffer one. Re-project the raster and convert to Geotiff format accordingly.

4. Extract the DEM raster geotiff file with the buffer zone shapefile.

5. Generate the hexaon mesh using the MMQGIS plugin and the extracted DEM as spatial extent
(http://michaelminn.com/linux/mmqgis/). The resolution of the hexagon should be defined using its area instead of edge length. 

# Model simulation

After all the input files are prepared, you can update the text file as the model input parameter. 

Then you can prepare another bash script similar to:
![Run bash](https://github.com/pnnl/hexwatershed/blob/master/example/figure/run.png?raw=true)

Then you may run the simulation by typing in the terminal:
```
chmod 755 run.sh
./run.sh
```

The terminal will output some model information directly:

![Run log](https://github.com/pnnl/hexwatershed/blob/master/example/figure/run_log.png?raw=true)

By then, you should have a successful hexWatershed simulation. 

# Simulation results

After the simulation is finished, you should see a list of shapefiles within the output firectory.
1. hexagon DEM
2. flow direction
3. flow accumulation
4. stream segment
5. stream order
6. subbasin boundary
7. watershed boundary
![List of results](https://github.com/pnnl/hexwatershed/blob/master/example/figure/result_list.png?raw=true)

You can use any GIS tools (ArcGIS, ENVI, and QGIS, etc.) to visulize the results.

Below are some example outputs from this example:
* Flow direction
![Flow direction](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_flow_direction_90_full.png?raw=true)
* Flow accumulation
![Flow accumulation](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_flow_accumulation_90_full.png?raw=true)
* Stream order
![Stream order](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_stream_order_90_full.png?raw=true)
* Subbasin
![Subbasin](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_subbasin_90_full.png?raw=true)