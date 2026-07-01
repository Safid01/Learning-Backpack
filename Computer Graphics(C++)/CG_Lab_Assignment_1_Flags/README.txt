# Computer Graphics Lab Assignment 1 - Country Flags

This repository contains separate OpenGL/GLUT projects for drawing different country flags manually using basic computer graphics primitives.

## Course Information

- Course: CSC 4118 Computer Graphics
- Assignment: Lab Assignment 1
- Topic: Drawing Country Flags Using OpenGL and GLUT
- Institution: American International University-Bangladesh
- Department: Computer Science
- Language: C++
- Graphics Library: OpenGL and GLUT / FreeGLUT

## Assignment Objective

The purpose of this assignment is to practice drawing 2D graphical objects using OpenGL primitives. Each flag is created manually using geometric shapes such as rectangles, triangles, polygons, lines, circles, and stars.

No image files are used to draw the flags. All visual elements are generated through OpenGL code.

## Included Flag Projects

The repository contains separate projects for the following flags:

1. Canada
2. USA
3. New Zealand
4. Jordan
5. Morocco
6. Ghana
7. Cape Verde
8. South Africa
9. Croatia
10. Haiti

Each flag has its own separate project folder.

## Repository Structure

```text
CG_Lab_Assignment_1_Flags/
│
├── Canada_Flag/
│   ├── main.cpp
│   └── Canada_Flag.cbp
│
├── USA_Flag/
│   ├── main.cpp
│   └── USA_Flag.cbp
│
├── New_Zealand_Flag/
│   ├── main.cpp
│   └── New_Zealand_Flag.cbp
│
├── Jordan_Flag/
│   ├── main.cpp
│   └── Jordan_Flag.cbp
│
├── Morocco_Flag/
│   ├── main.cpp
│   └── Morocco_Flag.cbp
│
├── Ghana_Flag/
│   ├── main.cpp
│   └── Ghana_Flag.cbp
│
├── Cape_Verde_Flag/
│   ├── main.cpp
│   └── Cape_Verde_Flag.cbp
│
├── South_Africa_Flag/
│   ├── main.cpp
│   └── South_Africa_Flag.cbp
│
├── Croatia_Flag/
│   ├── main.cpp
│   └── Croatia_Flag.cbp
│
├── Haiti_Flag/
│   ├── main.cpp
│   └── Haiti_Flag.cbp
│
├── CG_Lab_Assignment_1_Report_Template.docx
└── README.txt
```

## Technologies Used

- C++
- OpenGL
- GLUT / FreeGLUT
- Code::Blocks IDE

## OpenGL Primitives and Techniques Used

The projects use the following OpenGL primitives and manual drawing techniques:

| Element Type | Technique Used |
|---|---|
| Rectangular stripes and backgrounds | `GL_QUADS` |
| Triangles and flag sections | `GL_TRIANGLES` |
| Stars | Manually calculated vertex points with triangle filling |
| Circles | Parametric circle drawing using loop |
| Shields and emblems | Manually plotted polygons |
| Lines and outlines | `GL_LINES` or `GL_LINE_STRIP` |
| Complex symbols | Combination of polygons, triangles, circles, and rectangles |

## How to Run a Project

1. Open Code::Blocks.
2. Go to `File > Open`.
3. Select the `.cbp` file from the flag project folder.
4. Build and run the project.
5. The flag will appear in a GLUT window.

Example:

```text
South_Africa_Flag/South_Africa_Flag.cbp
```

## Required Libraries

Make sure the project is linked with the following libraries:

```text
-lopengl32
-lglu32
-lfreeglut
```

For Code::Blocks, these are usually added in:

```text
Project > Build Options > Linker Settings
```

## General Code Structure

Most projects follow this structure:

```cpp
#include <GL/glut.h>

void drawFlag()
{
    // Flag drawing code
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawFlag();
    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 900, 0, 600);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Country Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
```
## Notes

- Each flag is drawn manually using OpenGL.
- No external image is used for flag drawing.
- Every flag project is kept separate according to the assignment requirement.
- The code is written in a beginner-friendly structure suitable for Computer Graphics lab practice.
