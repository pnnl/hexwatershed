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



# Introduction



# Algorithms



1. Depression filling



![Illustration of the priority-flood depression filling for the HGSD method.](https://github.com/pnnl/hexwatershed/blob/master/algorithm/priority_flood_legend.gif?raw=true)

Stream topology is defined based on the stream reaches information.

![Illustration of the stream topology. Different colors represent 4 different stream segments, respectively. Each stream segment is made up by several stream reaches.](https://github.com/pnnl/hexwatershed/blob/master/algorithm/stream_topology.png?raw=true)

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

