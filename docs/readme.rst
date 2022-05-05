#####################
What is HexWatershed?
#####################

*********
Overview
*********

.. image:: https://zenodo.org/badge/DOI/10.5281/zenodo.6512369.svg
   :target: https://doi.org/10.5281/zenodo.6512369

HexWatershed is a mesh independent flow direction model for hydrological models.

******************************
Why do we develop HexWatershed
******************************

Spatial discretization is the cornerstone of all spatially-distributed numerical simulations including watershed hydrology. Traditional square grid spatial discretization has several limitations:

* It cannot represent adjacency uniformly;

* It leads to the "island effect" and the diagonal travel path issue in D8 scheme;

* It cannot provide a spherical coverage without significant spatial distortion;

* It cannot be coupled with other unstructured mesh-based models such as the oceanic models.

Therefore, we developed a watershed delineation model (HexWatershed) based on the hexagon mesh spatial discretization. 

We further improve HexWatershed to fully unstructured mesh-based to support variable-resolution meshes such as the MPAS mesh.

We propose that spatially distributed hydrologic simulations should consider using a hexagon grid spatial discretization.




