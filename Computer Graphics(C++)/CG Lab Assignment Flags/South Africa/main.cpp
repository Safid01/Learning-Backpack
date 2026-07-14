#include <windows.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 60, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(0.85f, 0.0f, 0.0f);
        glVertex2f(0, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 30);
        glVertex2f(0, 30);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.05f, 0.55f);
        glVertex2f(0, 30);
        glVertex2f(100, 30);
        glVertex2f(100, 60);
        glVertex2f(0, 60);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(34, 23);
        glVertex2f(100, 23);
        glVertex2f(100, 37);
        glVertex2f(34, 37);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0, 0);
        glVertex2f(14, 0);
        glVertex2f(46, 23);
        glVertex2f(34, 23);
        glVertex2f(0, 8);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0, 60);
        glVertex2f(14, 60);
        glVertex2f(46, 37);
        glVertex2f(34, 37);
        glVertex2f(0, 52);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.45f, 0.18f);
        glVertex2f(0, 0);
        glVertex2f(43, 30);
        glVertex2f(0, 60);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.45f, 0.18f);
        glVertex2f(36, 25);
        glVertex2f(100, 25);
        glVertex2f(100, 35);
        glVertex2f(36, 35);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.45f, 0.18f);
        glVertex2f(0, 0);
        glVertex2f(8, 0);
        glVertex2f(43, 25);
        glVertex2f(36, 25);
        glVertex2f(0, 6);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.45f, 0.18f);
        glVertex2f(0, 60);
        glVertex2f(8, 60);
        glVertex2f(43, 35);
        glVertex2f(36, 35);
        glVertex2f(0, 54);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.45f, 0.18f);
        glVertex2f(28, 30);
        glVertex2f(36, 25);
        glVertex2f(45, 25);
        glVertex2f(52, 30);
        glVertex2f(45, 35);
        glVertex2f(36, 35);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.45f, 0.18f);
        glVertex2f(28, 25);
        glVertex2f(42, 27);
        glVertex2f(49, 30);
        glVertex2f(42, 33);
        glVertex2f(28, 35);
        glVertex2f(33, 30);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.75f, 0.0f);
        glVertex2f(0, 7);
        glVertex2f(34, 30);
        glVertex2f(0, 53);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0, 13);
        glVertex2f(25, 30);
        glVertex2f(0, 47);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.45f, 0.18f);
        glVertex2f(34, 30);
        glVertex2f(40, 27);
        glVertex2f(47, 29);
        glVertex2f(47, 31);
        glVertex2f(40, 33);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 480);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("South Africa Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
