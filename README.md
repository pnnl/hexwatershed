# HexWatershed

HexWatershed is a hydrologic routing model based on the hexagon mesh framework.

Please navigate to https://github.com/changliao1025/hexwatershed for latest version information.

# Abstarct

Spatial discretization is the cornerstone of all spatially-distributed numerical simulations including watershed hydrology. Traditional square grid spatial discretization has several limitations including inability to represent adjacency uniformly. In this study, we developed a watershed delineation model (HexWatershed) based on the hexagon grid spatial discretization. We applied this model to two different types of watershed in the US and we evaluated its performance against the traditional method. The comparisons show that the hexagon grid spatial discretization exhibits many advantages over the tradition method. We propose that spatially distributed hydrologic simulations should consider using a hexagon grid spatial discretization.

# Illustration 
1. Depression filling
   
![Depression filling](https://github.com/pnnl/hexwatershed/blob/master/example/depression_filling.png?raw=true)

2. Flow direction
   
![Flow direction](https://github.com/pnnl/hexwatershed/blob/master/example/cbf_flow_direction_90_full.png?raw=true)

3. Stream topology
   
![Flow direction](https://github.com/pnnl/hexwatershed/blob/master/example/stream_topology.png?raw=true)
# Citation

Liao, C., Tesfa, T., Duan, Z., & Leung, L. R. (2020). Watershed delineation on a hexagonal mesh grid. Environmental Modelling & Software, 104702. https://doi.org/10.1016/j.envsoft.2020.104702


# Acknowledgement
The model described in this repository was primarily funded by a Laboratory Directed Research and Development (LDRD) Program Quickstarter project at Pacific Northwest National Laboratory. 
This work was also supported by the Earth System Model Development and Regional and Global Modeling and Analysis program areas of the U.S. Department of Energy, Office of Science, Office of Biological and Environmental Research as part of the multi-program, collaborative Integrated Coastal Modeling (ICoM) project.
CL was also partly supported by U.S. Department of Energy Office of Science Biological and Environmental Research through the Earth and Environmental System Modeling program as part of the Energy Exascale Earth System Model (E3SM) project. 
A portion of this research was performed using PNNL Research Computing at Pacific Northwest National Laboratory. PNNL is operated for DOE by Battelle Memorial Institute under contract DE-AC05-76RL01830.

# Compile
1. git clone git@github.com:pnnl/hexwatershed.git
2. Navigate to the directory which has the CMakeLists.txt file
3. Adjust your configuration of the CMakeLists.txt
4. cmake CMakeLists.txt
5. make

# Usage
In order to run the program, you need to prepare a few input files:
1. A hexagon grid
2. A DEM

# Contact
We are now using the Issue (https://github.com/pnnl/hexwatershed/issues) for Q&A.
For other types of questions, please contact Chang Liao (chang.liao@pnnl.gov).

