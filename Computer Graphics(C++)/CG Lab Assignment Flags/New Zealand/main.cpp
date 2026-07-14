#include <windows.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 50, 0);
}

void drawStar(float cx, float cy, float s) //Took from AI :)
{
    glBegin(GL_TRIANGLES);

        glVertex2f(cx, cy);
        glVertex2f(cx, cy - s);
        glVertex2f(cx + 0.3f * s, cy - 0.3f * s);

        glVertex2f(cx, cy);
        glVertex2f(cx - 0.3f * s, cy - 0.3f * s);
        glVertex2f(cx, cy - s);

        glVertex2f(cx, cy);
        glVertex2f(cx + 0.3f * s, cy - 0.3f * s);
        glVertex2f(cx + s, cy);

        glVertex2f(cx, cy);
        glVertex2f(cx + s, cy);
        glVertex2f(cx + 0.3f * s, cy + 0.3f * s);

        glVertex2f(cx, cy);
        glVertex2f(cx + 0.3f * s, cy + 0.3f * s);
        glVertex2f(cx + 0.6f * s, cy + s);

        glVertex2f(cx, cy);
        glVertex2f(cx + 0.6f * s, cy + s);
        glVertex2f(cx, cy + 0.45f * s);

        glVertex2f(cx, cy);
        glVertex2f(cx, cy + 0.45f * s);
        glVertex2f(cx - 0.6f * s, cy + s);

        glVertex2f(cx, cy);
        glVertex2f(cx - 0.6f * s, cy + s);
        glVertex2f(cx - 0.3f * s, cy + 0.3f * s);

        glVertex2f(cx, cy);
        glVertex2f(cx - 0.3f * s, cy + 0.3f * s);
        glVertex2f(cx - s, cy);

        glVertex2f(cx, cy);
        glVertex2f(cx - s, cy);
        glVertex2f(cx - 0.3f * s, cy - 0.3f * s);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.12f, 0.45f);
        glVertex2f(0, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 50);
        glVertex2f(0, 50);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0, 21);
        glVertex2f(3, 25);
        glVertex2f(50, 4);
        glVertex2f(50, 0);
        glVertex2f(47, 0);
        glVertex2f(0, 21);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0, 0);
        glVertex2f(3, 0);
        glVertex2f(50, 21);
        glVertex2f(50, 25);
        glVertex2f(47, 25);
        glVertex2f(0, 4);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.85f, 0.0f, 0.0f);
        glVertex2f(0, 23);
        glVertex2f(50, 1.5f);
        glVertex2f(50, 4.5f);
        glVertex2f(0, 25);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.85f, 0.0f, 0.0f);
        glVertex2f(0, 0);
        glVertex2f(0, 2.5f);
        glVertex2f(50, 25);
        glVertex2f(50, 22.5f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0, 9);
        glVertex2f(50, 9);
        glVertex2f(50, 16);
        glVertex2f(0, 16);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(20, 0);
        glVertex2f(30, 0);
        glVertex2f(30, 25);
        glVertex2f(20, 25);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.85f, 0.0f, 0.0f);
        glVertex2f(0, 11);
        glVertex2f(50, 11);
        glVertex2f(50, 14);
        glVertex2f(0, 14);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.85f, 0.0f, 0.0f);
        glVertex2f(23, 0);
        glVertex2f(27, 0);
        glVertex2f(27, 25);
        glVertex2f(23, 25);
    glEnd();
    //stars
    glColor3f(1.0f, 1.0f, 1.0f);
    drawStar(72, 12, 3.0f);
    drawStar(83, 22, 2.6f);
    drawStar(72, 34, 3.0f);
    drawStar(61, 25, 2.5f);

    glColor3f(0.85f, 0.0f, 0.0f);
    drawStar(72, 12, 2.0f);
    drawStar(83, 22, 1.8f);
    drawStar(72, 34, 2.0f);
    drawStar(61, 25, 1.7f);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("New Zealand Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
