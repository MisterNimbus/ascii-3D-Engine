# ascii-3D-Engine
A 3D engine for rendering objects on the console.

Points form triangles, triangles form meshes and meshes form objects...


To rotate an object you rotate all points, which in return rotates all triangles, which in return turns all meshes, which results in the rotated object.

I have only created a cube and a tetrahedron. More can be done but it takes a long time to enter coordinates of the points one by one. Triangles can be rotated to accelerate the creation process. I have experimented with that and was able to create a cube by rotating and duplicating a single surface. But again it is also not so fun to find out the measurements and angles for polyhedrons in 3D.

I have experimented with changing the surfaceChars depending on the normal of the surface. It worked to some extent but I decided it was too much fuss and I have already lost my apetite for this project. I might try that on a pixel engine one day...

## To build and run use:
```
make run
```


## Visuals
<p align="center">
   <img src="https://github.com/MisterNimbus/ascii-3D-Engine/blob/rework/imgs/menu.jpg" width="100%" />
<div align="center">
  ⬆ Opening Dialog
  </div>
</p>

<p align="center">
   <img src="https://github.com/MisterNimbus/ascii-3D-Engine/blob/rework/imgs/rotating_cube.gif" width="100%" />
<div align="center">
  ⬆ Rotating Cube
  </div>
</p>

<p align="center">
   <img src="https://github.com/MisterNimbus/ascii-3D-Engine/blob/rework/imgs/rotating_cube_5x.gif" width="100%" />
<div align="center">
  ⬆ Rotating Cube (accelerated 5 times)
  </div>
</p>

<p align="center">
   <img src="https://github.com/MisterNimbus/ascii-3D-Engine/blob/rework/imgs/rotating_tetrahedron.gif" width="100%" />
<div align="center">
  ⬆ Rotating Tetrahedron
  </div>
</p>

<p align="center">
   <img src="https://github.com/MisterNimbus/ascii-3D-Engine/blob/rework/imgs/rotating_tetrahedron_5x.gif" width="100%" />
<div align="center">
  ⬆ Rotating Tetrahedron (accelerated 5 times)
  </div>
</p>


