#include <windows.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 60);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(25.0f, 0.0f);
        glVertex2f(25.0f, 60.0f);
        glVertex2f(0.0f, 60.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(25.0f, 0.0f);
        glVertex2f(75.0f, 0.0f);
        glVertex2f(75.0f, 60.0f);
        glVertex2f(25.0f, 60.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(75.0f, 0.0f);
        glVertex2f(100.0f, 0.0f);
        glVertex2f(100.0f, 60.0f);
        glVertex2f(75.0f, 60.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(50.0f, 44.0f);
        glVertex2f(47.0f, 36.0f);
        glVertex2f(42.0f, 38.0f);
        glVertex2f(44.0f, 32.0f);
        glVertex2f(39.0f, 31.0f);
        glVertex2f(44.0f, 27.0f);
        glVertex2f(41.0f, 22.0f);
        glVertex2f(48.0f, 25.0f);
        glVertex2f(48.0f, 15.0f);
        glVertex2f(52.0f, 15.0f);
        glVertex2f(52.0f, 25.0f);
        glVertex2f(59.0f, 22.0f);
        glVertex2f(56.0f, 27.0f);
        glVertex2f(61.0f, 31.0f);
        glVertex2f(56.0f, 32.0f);
        glVertex2f(58.0f, 38.0f);
        glVertex2f(53.0f, 36.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 480);
    glutInitWindowPosition(150, 50);
    glutCreateWindow("Canada Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
