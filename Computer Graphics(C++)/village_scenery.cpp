// Assignment 2 - Part 2: Simple Village Scenery
// Built using OpenGL's own primitives (GL_QUADS, GL_TRIANGLES, GL_POLYGON, GL_LINES).
// No manual pixel-plotting algorithms needed here - same glBegin/glEnd style as the
// quads/triangles programs shown in class.

#include <windows.h>
#include <GL/glut.h>
#include <cmath>

// Draws a filled circle approximation using GL_POLYGON (used for sun / clouds / leaves)
void drawCircle(float cx, float cy, float r, int segments)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++)
    {
        float theta = 2.0f * 3.14159f * i / segments;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
}

// One house = body (GL_QUADS) + roof (GL_TRIANGLES) + door (GL_QUADS) + window (GL_QUADS + GL_LINES)
void drawHouse(float x, float y, float w, float h)
{
    // body
    glColor3f(0.85f, 0.7f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(x,     y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x,     y + h);
    glEnd();

    // roof
    glColor3f(0.6f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
        glVertex2f(x - 10,     y + h);
        glVertex2f(x + w + 10, y + h);
        glVertex2f(x + w / 2,  y + h + 40);
    glEnd();

    // door
    glColor3f(0.35f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(x + w / 2 - 8, y);
        glVertex2f(x + w / 2 + 8, y);
        glVertex2f(x + w / 2 + 8, y + 30);
        glVertex2f(x + w / 2 - 8, y + 30);
    glEnd();

    // window pane
    glColor3f(0.9f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(x + 10, y + 35);
        glVertex2f(x + 25, y + 35);
        glVertex2f(x + 25, y + 50);
        glVertex2f(x + 10, y + 50);
    glEnd();

    // window cross-frame
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(x + 17.5f, y + 35); glVertex2f(x + 17.5f, y + 50);
        glVertex2f(x + 10,    y + 42.5f); glVertex2f(x + 25, y + 42.5f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ---------------- Part A: Background ----------------
    // Sky
    glColor3f(0.53f, 0.81f, 0.92f);
    glBegin(GL_QUADS);
        glVertex2f(0,   250);
        glVertex2f(800, 250);
        glVertex2f(800, 600);
        glVertex2f(0,   600);
    glEnd();

    // Ground
    glColor3f(0.42f, 0.65f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2f(0,   0);
        glVertex2f(800, 0);
        glVertex2f(800, 250);
        glVertex2f(0,   250);
    glEnd();

    // Sun
    glColor3f(1.0f, 0.85f, 0.0f);
    drawCircle(700, 520, 40, 40);

    // Clouds (2 clusters of overlapping circles)
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(150, 500, 25, 30);
    drawCircle(180, 510, 30, 30);
    drawCircle(210, 500, 22, 30);

    drawCircle(500, 540, 20, 30);
    drawCircle(525, 545, 25, 30);

    // ---------------- Part C (extra 1): Mountains ----------------
    glColor3f(0.5f, 0.4f, 0.35f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0,   250); glVertex2f(120, 380); glVertex2f(240, 250);
        glVertex2f(180, 250); glVertex2f(300, 400); glVertex2f(420, 250);
    glEnd();

    // River, long quad across the scene (also doubles as the required road/river element)
    glColor3f(0.25f, 0.55f, 0.85f);
    glBegin(GL_QUADS);
        glVertex2f(0,   60);
        glVertex2f(800, 40);
        glVertex2f(800, 90);
        glVertex2f(0,   110);
    glEnd();

    // ---------------- Part B: Village elements ----------------
    drawHouse(300, 130, 80, 70);
    drawHouse(470, 130, 80, 70);

    // Tree trunk
    glColor3f(0.4f, 0.25f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(650, 130);
        glVertex2f(670, 130);
        glVertex2f(670, 200);
        glVertex2f(650, 200);
    glEnd();

    // Tree leaves (circle cluster)
    glColor3f(0.1f, 0.5f, 0.15f);
    drawCircle(660, 220, 35, 30);
    drawCircle(640, 210, 25, 30);
    drawCircle(680, 210, 25, 30);

    // ---------------- Part C (extra 2): Birds ----------------
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(370, 560); glVertex2f(385, 570);
        glVertex2f(385, 570); glVertex2f(400, 560);

        glVertex2f(440, 540); glVertex2f(455, 552);
        glVertex2f(455, 552); glVertex2f(470, 540);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Simple Village Scenery - OpenGL Built-in Functions");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
