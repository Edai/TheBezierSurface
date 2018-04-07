FUNDAMENTALS OF COMPUTER GRAPHICS -  PROJECT 3 REPORT

Author: Valentin KAO <valentin.kao@epitech.eu> 张有请 - 2017280242
		
The purpose of this project is to implement an OpenGl program in which
there is a textured Bezier surface with 25 control points (5 per lines)
and you can change the smoothness of the surface;

---------------------------------------------------------------------------
VIDEO CAPTURE
---------------------------------------------------------------------------

The video capture of my program named screenrecord.mp4, is available from
the root of the folder.

---------------------------------------------------------------------------
REQUIREMENTS
---------------------------------------------------------------------------
•	GCC 5 or later
•	CMake 3.9 or later
•	OpenGL, GLUT and SOIL libraries.
The code hasn't been tested on Windows but should work on Visual Studio
2015 and later.

---------------------------------------------------------------------------
BUILD AND USAGE
---------------------------------------------------------------------------
From the folder in which you found this report, please enter the following
command lines.
1.		mkdir build && cd build
2.		cmake ..
3.		make

Once the compilated was successful, you can execute the program. 
Here is the usage of the program.

	./assignment4 [--width=x] [--height=y] [--title=”Assignment 4]
	
---------------------------------------------------------------------------
FLAGS – OPTIONS	DESCRIPTION	DEFAULT
---------------------------------------------------------------------------
width, w	Set the width of the window	900
height, h	Set the height of the window	900
title, t	Set the title of the window	“Assignment 4”

---------------------------------------------------------------------------
SOFTWARE DESIGN
---------------------------------------------------------------------------
In order to implement future project easily, I define a simple application
design. Those three classes are singletons avoiding any multiple instances.

Application - Graphical Core - Engine

---------------------------------------------------------------------------
ALGORITHM IMPLEMENTED
---------------------------------------------------------------------------

By default, we set 5x5 coordinates of points in an array of GLfloat repre-
senting the control points in static in the Class Engine.
Then, we use the functions glMap2f, glMapGrid2f and glEvalMesh2 to display
the Bezier Surface in the Update function.

The user can modify the positions of the control points and the options 
of glMap2f to change the smoothness of the Bezier surface.

---------------------------------------------------------------------------
FUNCTIONNALITIES
---------------------------------------------------------------------------
By pressing the key ESC or the key Q, you close the program properly.
By pressing the key H, it hides the help text.
By pressing 1, the texture applied is the Tsinghua image.
By pressing 2, the texture applied is the Dog image.
BY pressing 0, it switches to the grid display or textured display.
As said previously, the user can navigate into the array of points with the
arrows of the keyboard, by default, the current point is the (0, 0) point.

By pressing Q, W or E. the user can increase the coordinate x, y or z of
the point.
By pressing A, S or D. the user can decrease the coordinate x, y or z of
the point.
By pressing R or T, the user can increase the smoothness of u or v.
By pressing F or G, the user can decrease the smoothness of u or v.

Here is the array :
      0 1 2 3 4
    0 x . . . .
    1 . . . . .
    2 . . . . .
    3 . . . . .
    4 . . . . .
 