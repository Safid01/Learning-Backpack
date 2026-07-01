#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265359f;

void setColor(float r, float g, float b)
{
    glColor3f(r, g, b);
}

void drawRectangle(float x1, float y1, float x2, float y2)
{
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

void drawStar(float cx, float cy, float outerR, float innerR, float rotationDeg)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 10; i++)
    {
        float r = (i % 2 == 0) ? outerR : innerR;
        float angle = (rotationDeg + i * 36.0f) * PI / 180.0f;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();
}


void drawFlag()
{
    setColor(0.85f, 0.0f, 0.0f); drawRectangle(0, 400, 900, 600);
    setColor(1.0f, 1.0f, 1.0f); drawRectangle(0, 200, 900, 400);
    setColor(0.0f, 0.15f, 0.65f); drawRectangle(0, 0, 900, 200);
    setColor(0.0f, 0.0f, 0.5f);
    glBegin(GL_POLYGON);
        glVertex2f(360, 430); glVertex2f(540, 430);
        glVertex2f(540, 260); glVertex2f(450, 180); glVertex2f(360, 260);
    glEnd();
    float startX = 380, startY = 270, cell = 32;
    for (int row = 0; row < 5; row++)
        for (int col = 0; col < 5; col++)
        {
            if ((row + col) % 2 == 0) setColor(0.85f, 0.0f, 0.0f);
            else setColor(1.0f, 1.0f, 1.0f);
            drawRectangle(startX + col*cell, startY + row*cell,
                          startX + (col+1)*cell, startY + (row+1)*cell);
        }
    setColor(0.0f, 0.15f, 0.65f);
    drawRectangle(365, 430, 395, 470); drawRectangle(400, 430, 430, 470);
    drawRectangle(435, 430, 465, 470); drawRectangle(470, 430, 500, 470);
    drawRectangle(505, 430, 535, 470);
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
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Croatia Flag - CG Lab Assignment 1");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
