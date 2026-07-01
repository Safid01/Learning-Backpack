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
    setColor(0.85f, 0.0f, 0.0f); drawRectangle(0, 300, 900, 600);
    setColor(0.0f, 0.1f, 0.65f); drawRectangle(0, 0, 900, 300);
    setColor(1.0f, 1.0f, 1.0f); drawTriangle(0, 600, 460, 300, 0, 0); drawRectangle(300, 250, 900, 350);
    setColor(0.0f, 0.45f, 0.2f); drawTriangle(0, 540, 385, 300, 0, 60); drawRectangle(300, 270, 900, 330);
    setColor(1.0f, 0.75f, 0.0f); drawTriangle(0, 500, 300, 300, 0, 100);
    setColor(0.0f, 0.0f, 0.0f); drawTriangle(0, 455, 230, 300, 0, 145);
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
    glutCreateWindow("South Africa Flag - CG Lab Assignment 1");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
