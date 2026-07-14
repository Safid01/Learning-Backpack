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
        glColor3f(0.81f, 0.0f, 0.0f);
        glVertex2f(0, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 20);
        glVertex2f(0, 20);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.84f, 0.0f);
        glVertex2f(0, 20);
        glVertex2f(100, 20);
        glVertex2f(100, 40);
        glVertex2f(0, 40);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.55f, 0.0f);
        glVertex2f(0, 40);
        glVertex2f(100, 40);
        glVertex2f(100, 60);
        glVertex2f(0, 60);
    glEnd();

    //Black star
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLES);

        glVertex2f(50, 30); glVertex2f(50, 21); glVertex2f(52.5, 27);
        glVertex2f(50, 30); glVertex2f(52.5, 27); glVertex2f(59, 27);
        glVertex2f(50, 30); glVertex2f(59, 27); glVertex2f(54, 31.5);
        glVertex2f(50, 30); glVertex2f(54, 31.5); glVertex2f(56, 38.5);
        glVertex2f(50, 30); glVertex2f(56, 38.5); glVertex2f(50, 34.5);
        glVertex2f(50, 30); glVertex2f(50, 34.5); glVertex2f(44, 38.5);
        glVertex2f(50, 30); glVertex2f(44, 38.5); glVertex2f(46, 31.5);
        glVertex2f(50, 30); glVertex2f(46, 31.5); glVertex2f(41, 27);
        glVertex2f(50, 30); glVertex2f(41, 27); glVertex2f(47.5, 27);
        glVertex2f(50, 30); glVertex2f(47.5, 27); glVertex2f(50, 21);

    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 480);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Ghana Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
