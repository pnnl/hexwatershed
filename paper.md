---
title: 'HexWatershed: A watershed delineation model based on hexagon mesh grid'

tags:
  - C/C++
  - Hydrology
  - watershed delineation
  - terrain analysis
  - geographic information system

authors:
  - name: Chang Liao
    orcid: 0000-0002-7348-8858    
    affiliation: 1

affiliations:
 - name: Atmospheric Sciences and Global Change, Pacific Northwest National Laboratory, Richland, WA, USA
   index: 1 
date: 15 October 2020

bibliography: paper.bib
---

# Summary

For decades, watershed delineation has been widely viewed as the first and most important step in wastershed hydrology simulations. While most studies focus on the physical processes in hydrologic simulations, less attentions have been paid to the underlying spatial discretization, the mesh grid.  HexWatershed is the first watershed delineation model that uses a hexagon mesh grid spatial discretization to resolve several limitations in current models.

# Statement of need

Watershed delineation is the first and yet most critical step in most watershed hydrology simulations. Currently, this process often requires a raster digital elevation model (DEM) dataset as input, which is based on the square grids. 
From now on, we will use ``traditional methods'' to represent all the numerical methods based on square grids unless otherwise stated.

Recent study demonstrates that watershed delineation on hexagon grids has several advantages compared with the traditional methods:

* It represents adjacency uniformly because it has only one type of connectivity [@DeSousa2006].
* It elminates the island effect and diagonal travel path issues, which often occur in the traditional method [@Johnston2009].
* It can be applied at continental to global scale using a digital global grid system (DGGS) to provide better sphere coverage.

Because of the dependency of hydrologic processes on watershed characteristics, hexagon grids based watershed hydrology simulations will be improved.

Besides, hexagon grids provide an opportunity in coupling hydrologic models with oceanic models because the latter are usually based on unstructured meshes.

Despite these advantages and practical needs, such a software specifically designed for watershed delineation on the hexagon grids is not available.
In this study, we present HexWatershed, the first watershed delineation model based on the hexagon grids.

# Algorithms and implementation

HexWatershed was developed based on existing algorithms and philosophies from traditional watershed delineation models. However, due to the fundamental differences in mesh grid, significant changes are made in model design and implementation. Below we only provide information on algorithms that are significantly different from their corresponding traditional algorithms.

* Hexagon DEM

In Hexwatershed 1.0, the elevation of each hexagon is extracted and assigned by its location from the high resolution tradition DEM. Advanced spatial resampling methods will be used in new versions.

* Neighborhood definition

In tradtional methods, the neighbors of a grid can be referred by moving its indices up and down. However, in unstructured grids such as hexagon grids, a specifically designed index system is required to manage neighborhood information. In HexWatershed 1.0, the neighborhood information of each hexagon is defined using the following steps:

1. A global ID is assigned to each hexagon;
2. Loop through each hexagon and find its neighbors using shared vertices and edges;
3. Save the neighborhood information in a lookup table.

This design is to consider a fully unstructured mesh which includes not only hexagon, but also pentagon and other polygons.
  
* Depression filling

To remove the local depression within the hexagon DEM, a depression filling algorithm was implemented based on the priority-flood algorithm. This is also the first implementation of the priority-flood algorithm on a D6 connectivity grid [@Barnes2014]. 

![Illustration of the priority-flood depression filling on the hexagon mesh.](https://github.com/pnnl/hexwatershed/blob/master/algorithm/depression_filling.png?raw=true)

Figure 1. Illustration of the priority-flood depression filling on the hexagon mesh. Light blue grids represent the initial default state; red grids represent the boundary; green grids represent the to-be-removed grid from the queue; orange grids represent the to-be-added grids into the queue; and purple grids are finished grids. Numbers within each grid represent its global ID and elevation (in parentheses, unit: m), respectively. The algorithm gradually ``floods" the domain using a boundary queue (red). If a to-be-added grid has equal or smaller elevation than a to-be-removed grid, its elevation is increased. 

* Flow direction

In HexWatershed 1.0, only the single flow direction is supported, which is defined as from the hexagon center to one of its neighbors which has the lowest elevation.

* Flow accumulation

The flow accumulation algorithm was developed based on the concept from ArcGIS flow accumulation. The new algorithm runs in the following steps:

1. Assign flow accumulation of each hexagon as 1;
2. Assign an initial flag to each hexagon as untreated (FALSE);
3. Set all hexagon grid as treated (TRUE) if it has no upslope;
4. Loop through all hexagon grids, if it is untreated (FALSE) and all of its upslope grids are treated (TRUE), then sum up its flow accumulation and set it as treated (TRUE);
5. Repeat step 4 until all grids are treated.

* Stream segment
Unlike most traditional methods, HexWatershed defines stream segment reversely from the watershed outlet to maintain an ascending order of stream indices using the following steps:

1. Start from the outlet, set the current stream segment as the maximum segment (N);
2. Search upstream and assign all the stream grids as segment N until it reaches a stream confluence;
3. The current stream segment becomes N-1, then search all the upstreams of this stream confluence;
4. Repeat step 2 until N = 1.

The maximum segment N is calculated based on stream confluence topology.

* Subbasin boundary
Similar to stream segment, HexWatershed defines subbasin reversely. The subbasin indices are the same with corresponding stream segments.

# Example results

HexWatershed produces all the watershed characteristics including stream networks and watershed boudnary.
Most model outputs are in shapefile format and can be visulized using a Geographic Information System (GIS) application.

* Flow direction

![The spatial distribtuion of flow direction.](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_flow_direction_90_full.png?raw=true)

Figure 2. The spatial distribtuion of flow direction.

* Flow accumulation

![The spatial distribtuion of flow accumulation.](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_flow_accumulation_90_full.png?raw=true)

Figure 3. The spatial distribtuion of flow accumulation.

* Stream order

![The spatial distribtuion of stream order.](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_stream_order_90_full.png?raw=true)

Figure 4. The spatial distribtuion of stream order.

* Subbasin boundary

![The spatial distribtuion of subbasin boundary.](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_subbasin_90_full.png?raw=true)

Figure 5. The spatial distribtuion of subbasin boundary.


# Acknowledgement

The model described in this repository was supported by:

* Laboratory Directed Research and Development (LDRD) Program Quickstarter project at Pacific Northwest National Laboratory. 
* Earth System Model Development and Regional and Global Modeling and Analysis program areas of the U.S. Department of Energy, Office of Science, Office of Biological and Environmental Research as part of the multi-program, collaborative Integrated Coastal Modeling (ICoM) project.
* U.S. Department of Energy Office of Science Biological and Environmental Research through the Earth and Environmental System Modeling program as part of the Energy Exascale Earth System Model (E3SM) project. 

A portion of this research was performed using PNNL Research Computing at Pacific Northwest National Laboratory. 

PNNL is operated for DOE by Battelle Memorial Institute under contract DE-AC05-76RL01830.

# References

