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

# Abstract

# Statement of need

Watershed delineation is the first step in most watershed scale hydrology simulations. This process often relies on a square grid based raster digital elevation model (DEM). From now on, the traditional method refers to method based on square grid unless otherwise stated.

Our recent study shows that watershed delineation on a hexagon mesh has several advantages compared with the traditional method:
* It can represent adjacency uniformly because it only has one type of connectivity [@DeSousa2006].
* It can elminate the island effect and diagonal travel path issues, which often occur in the traditional method [@Johnston2009].
* It can be potentially applied at the global scale using a digital global grid system (DGGS) to provide better sphere coverage.
* Because of the dependency of hydrologic processes on watershed characteristics, the hexagon mesh grid based watershed hydrology simulations may also be improved.

However, such a software package speficially designed for watershed delineation on the hexagon mesh grid is not available.
In this study, we present HexWatershed, the first watershed delineation model based on the hexagon mesh grid, as our effort to close the gap. 

# Algorithms and implementation

HexWatershed was developed based on existing algorithms and philosophies from the traditional methods. However, due to the differences in mesh grid, significant changes are made in model design and implementation. Below we only provide information if the algorithm is significantly different from traditional methods.

1. Hexagon DEM
In Hexwatershed 1.0, the elevation of each hexagon is assigned by its location and high resolution tradition DEM due to data availability.

2. Neighborhood definition

In tradtional methods, the neighbors of a grid can be referred by moving its indices up and down. However, in an unstructured mesh such as hexagon grid, a specially designed index system is required. In HexWatershed 1.0, the neighborhood information of each hexagon is defined using the following steps:
    1. A global ID is assigned to each hexagon;
    2. Loop through each hexagon and find its neighbors using shared vertices and edges;
    3. Save the neighborhood information in a lookup table.
  
3. Depression filling
To remove the local depression, aka, ``pit'', within the hexagon DEM, a depression filling algorithm was implemented based on the priority-flood algorithm, which is the first implementation of the priority-flood algorithm on a D6 grid [@Barnes2014]. 

![Illustration of the priority-flood depression filling on the hexagon mesh.](https://github.com/pnnl/hexwatershed/blob/master/algorithm/depression_filling.png?raw=true)

4. Flow direction
In HexWatershed 1.0, only the single flow direction is supported, which is defined as from the hexagon center to one of its neighbors which has the lowest elevation.

5. Flow accumulation
The flow accumulation algorithm was developed based on the concept from ArcGIS flow accumulation. The algorithm runs in the following steps:

  1. Assign each hexagon flow accumulation as 1;
  2. Assign a flag (FALSE) to each hexagon as untreated;
  3. Loop through all hexagon grid, if it is untreated and all of its upslope grids are treated, then sum up it flow accumulation and set its flag as treated (TRUE);
  4. Exit until all grids are treated.

6. Stream segment
Unlike most traditional methods, HexWatershed defines stream segment reversely from the watershed outlet to maintain an ascending order of stream indices.

7. Subbasin boundary
Similar to stream segment, HexWatershed define subbasin reversely. The subbasin indices are the same with corresponding stream segments.

# Results

1. Flow direction

![The spatial distribtuion of flow direction.](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_flow_direction_90_full.png?raw=true)

2. Flow accumulation

![The spatial distribtuion of flow accumulation.](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_flow_accumulation_90_full.png?raw=true)

3. Stream order

![The spatial distribtuion of stream order.](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_stream_order_90_full.png?raw=true)

4. Subbasin boundary

![The spatial distribtuion of subbasin boundary.](https://github.com/pnnl/hexwatershed/blob/master/example/columbia_basin_flat/output/cbf_subbasin_90_full.png?raw=true)

# Conclusion



# Acknowledgement

The model described in this repository was supported by:

* Laboratory Directed Research and Development (LDRD) Program Quickstarter project at Pacific Northwest National Laboratory. 
* Earth System Model Development and Regional and Global Modeling and Analysis program areas of the U.S. Department of Energy, Office of Science, Office of Biological and Environmental Research as part of the multi-program, collaborative Integrated Coastal Modeling (ICoM) project.
* U.S. Department of Energy Office of Science Biological and Environmental Research through the Earth and Environmental System Modeling program as part of the Energy Exascale Earth System Model (E3SM) project. 

A portion of this research was performed using PNNL Research Computing at Pacific Northwest National Laboratory. 

PNNL is operated for DOE by Battelle Memorial Institute under contract DE-AC05-76RL01830.

# References

