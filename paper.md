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

# Abstarct

Spatial discretization is the cornerstone of all spatially-distributed numerical simulations including watershed hydrology. Traditional square grid spatial discretization has several limitations including inability to represent adjacency uniformly. In this study, we developed a watershed delineation model (HexWatershed) based on the hexagon grid spatial discretization. Model evaluations show that the hexagon grid spatial discretization exhibits many advantages over the tradition method. We propose that spatially distributed hydrologic simulations should consider using a hexagon grid spatial discretization.

# Introduction

Spatial discretization is the cornerstone of all spatially distributed numerical simulations including hydrologic simulations. In hydrologic modeling the study domain is commonly discretized using a Square Grid Spatial Discretization (SGSD). Few studies have investigated the performance of other spatial discretizations such as Hexagon Grid Spatial Discretization (HGSD) in hydrology [@Weller2009].

In Geographic Information System (GIS), SGSD is the most widely used approach to represent spatial information. For example, a raster Digital Elevation Model (DEM) dateset is usually used to describe the surface elevation of a Region Of Interest (ROI) on the Earth's surface [@Gesch2002]. Because SGSD data structure can be represented by a rectangular array/matrix directly, it is convenient for computation, analysis, visualization and storage. However, SGSD has several limitations:

* SGSD cannot represent adjacency uniformly
* SGSD will create island effect due to the differences in D4 and D8 neighbor definitions
* SGSD cannot effectively represent a spherical topology

In contrast, the HGSD method can resolve these limitations:

* In HGSD, each grid has only one type of neighbor with the same connectivity and distance As a result, we can route both surface and subsurface water flow consistently without using different weights, thus getting rid of the decadal old assumption on travel length. This will improve spatially distributed hydrologic models that rely on grid connectivity.
* The island effect is automatically eliminated because all neighbors are connected through faces. No manual corrections are needed to resolve the diagonal traveling path issue. 
* It can provide continental to global coverage at consistent or variable spatial resolutions. It can be used to couple land surface/hydrologic models with oceanic models using a unified mesh grid (e.g., the Voronoi tessellation of the Model for Prediction Across Scale (MPAS)) [@Ringler2013, @Sahr2019].

Additionally, it has other advantages:

* It can be used for coupled surface (D6) and subsurface (9-point structured connectivity) hydrologic modeling to resolve the inconsistency in connectivity.
* The conceptual model is more compatible with the flow width information because the flow path can be contained within the grid boundary.
* It can improve model performance as many studies show that numerical simulations based on hexagon grid perform better when compared with other mesh grids. 
* Other flow direction methods (e.g., D-infinity) can also be implemented on HGSD with modifications to improve flow direction and partitions [@Tarboton1991].

In this study, we made the first attempt to develop a watershed delineation model (HexWatershed) with a set of algorithms based on the HGSD method. And we applied this model in a watershed within the Columbia river basin to demonstrate its capability.

# Algorithms

Following the traditional watershed delineation algorithms, we developed a list of algorithms for the HGSD method [@Liao2020]. 
Because these algorithms are fundamentally similar in principle, we mainly focus on the differences that were introduced in the new model.

1. Depression filling

Similar to traditional DEM, hexagonal DEM could potentially have local depressions when generated. We developed an algorithm following the method proposed by Richard Barnes, which uses the priority-flood method to fill the depressions in any grid system [@Barnes2014]. Priority-flood is an efficient algorithm to fill DEM depressions by sequentially ``flooding" the domain from the boundary inward to adjust elevations to assure that surface will drain.

![Illustration of the priority-flood depression filling for the HGSD method.](https://github.com/pnnl/hexwatershed/blob/master/example/depression_filling.png?raw=true)

2. Flow direction

Flow direction is defined from the hexagon center to the center of neighbor hexagon which has the lowest elevation. In other words, flow direction is the flow path which has the steepest slope.

3. Flow accumulation

We developed a flow accumulation algorithm based on the concept from ArcGIS flow accumulation. In short, this algorithm scans all the hexagon grids and sums up the accumulations once all the accumulations of upslope hexagons are calculated. It runs recursively until accumulations of all hexagons are calculated.

4. Stream topology

Stream topology is defined based on the stream reaches information.

![Illustration of the stream topology. Different colors represent 4 different stream segments, respectively. Each stream segment is made up by several stream reaches.](https://github.com/pnnl/hexwatershed/blob/master/example/stream_topology.png?raw=true)

# Results

1. Flow direction

Flow direction is defined from the hexagon center to the center of neighbor hexagon which has the lowest elevation. In other words, flow direction is the flow path which has the steepest slope.

![The spatial distribtuion of flow direction.](https://github.com/pnnl/hexwatershed/blob/master/example/cbf_flow_direction_90_full.png?raw=true)

2. Flow accumulation

![The spatial distribtuion of flow accumulation.](https://github.com/pnnl/hexwatershed/blob/master/example/cbf_flow_accumulation_90_full.png?raw=true)

3. Subbasin

![The spatial distribtuion of subbasin boundary.](https://github.com/pnnl/hexwatershed/blob/master/example/cbf_subbasin_90_full.png?raw=true)

3. Stream order

![The spatial distribtuion of stream order.](https://github.com/pnnl/hexwatershed/blob/master/example/cbf_stream_order_90_full.png?raw=true)

# Conclusion

We have developed a watershed delineation model (HexWatershed) using the hexagon grid spatial discretization method. We have applied this model to two different types of watersheds in the western US featuring steep and flat terrain. Model outputs have shown that HexWatershed can reproduce all the watershed delineation characteristics.

Our model can be applied to continental or global scale to improve large scale hydrologic simulations.


# Acknowledgement
The model described in this repository was supported by

* Laboratory Directed Research and Development (LDRD) Program Quickstarter project at Pacific Northwest National Laboratory. 
* Earth System Model Development and Regional and Global Modeling and Analysis program areas of the U.S. Department of Energy, Office of Science, Office of Biological and Environmental Research as part of the multi-program, collaborative Integrated Coastal Modeling (ICoM) project.
* U.S. Department of Energy Office of Science Biological and Environmental Research through the Earth and Environmental System Modeling program as part of the Energy Exascale Earth System Model (E3SM) project. 

A portion of this research was performed using PNNL Research Computing at Pacific Northwest National Laboratory. 

PNNL is operated for DOE by Battelle Memorial Institute under contract DE-AC05-76RL01830.

# References

