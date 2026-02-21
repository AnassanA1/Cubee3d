*This project has been created as part of the 42 curriculum by <azghibat>[, <msidry>].*

# cube3D

## Description

**cube3D** is a graphical project inspired by early 3D games such as *Wolfenstein 3D*.
The goal of this project is to implement a **real-time 3D rendering engine using raycasting**, entirely in C, following strict constraints and performance requirements.

The program parses a configuration file describing a map and textures, then renders a firstperson view of the environment. The player can move, rotate, and explore the map while respecting collision rules.

This project focuses on:
- Low level graphics rendering
- Mathematical concepts behind raycasting
- Event handling and real time input
- Memory management and performance

---

## Instructions
Make Run the program with a valid map file: ./cube3D maps/example.cub
the MinilibX is provided in libs.
Controls:
    - W, A, S, D Move the player
    - Arrow keys Rotate the camera
    - ESC — Exit the program
To compile the project, run:
make run


### Resources
The raycasting system in this project is implemented following the classical approach described in Lode Vandevenne’s raycasting tutorial.
Reference: https://lodev.org/cgtutor/raycasting.html


### Additional section

    - project overview : Raycasting part.
        The engine is based on three core vectors:
            - Position vector represents the player current position in the map.
            - Direction vector represents the direction the player is facing
            - Camera plane vectorrepresents the 2D plane perpendicular to the direction vector defining the player’s field of view

    - For each vertical stripe of the screen, a ray is cast into the map.
        The horizontal position of the ray on the screen is determined by a normalized value called camera_x, which ranges from:

    - -1 on the left side of the screen
    - 0 at the center
    - 1 on the right side

This value is used to compute the ray direction using the following relationship:
ray_direction = direction + camera_plane * camera_x
Using this method allows the engine to:
Correctly simulate perspective
Control the field of view using the camera plane
Render walls with proper depth and distortion correction

The ray traversal through the gridbased map is handled using a DDA algorithm to efficiently detect wall intersections

    - the DDA determine two things:
        - the delta distance which is delta_dist_x basically how much unit we move in one grid square
        - calculate the side distance its the initially the distance the ray travel from the start position to the first side 

    - We performe the dda loop the smallest delta (x or y side) is the one that is incremented
    - The variable perpWallDist will be used later to calculate the length of the ray this distance is crucial to avoid the fish eye effect and to ensure correct perspective rendering
    - Instead of using the raw ray length, the perpendicular distance represents how far the wall is directly in front of the camera plane
        - Closer walls appear taller
        - Farther walls appear shorter
    - The rule: wall_height = screen_height / perpendicular_distance
    - This value determines the vertical size of the wall slice drawn for the current screen column.
