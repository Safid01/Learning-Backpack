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
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 40.0f);
        glVertex2f(100.0f, 40.0f);
        glVertex2f(100.0f, 60.0f);
        glVertex2f(0.0f, 60.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, 20.0f);
        glVertex2f(100.0f, 20.0f);
        glVertex2f(100.0f, 40.0f);
        glVertex2f(0.0f, 40.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.45f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(100.0f, 0.0f);
        glVertex2f(100.0f, 20.0f);
        glVertex2f(0.0f, 20.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.75f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 60.0f);
        glVertex2f(42.0f, 30.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(14.0f, 30.0f);
        glVertex2f(14.0f, 25.0f);
        glVertex2f(15.45f, 28.62f);
        glVertex2f(14.0f, 30.0f);
        glVertex2f(17.91f, 26.88f);
        glVertex2f(15.98f, 30.27f);
        glVertex2f(14.0f, 30.0f);
        glVertex2f(18.87f, 31.11f);
        glVertex2f(15.03f, 31.72f);
        glVertex2f(14.0f, 30.0f);
        glVertex2f(16.17f, 34.5f);
        glVertex2f(13.3f, 31.87f);
        glVertex2f(14.0f, 30.0f);
        glVertex2f(11.83f, 34.5f);
        glVertex2f(12.1f, 30.62f);
        glVertex2f(14.0f, 30.0f);
        glVertex2f(9.13f, 31.11f);
        glVertex2f(12.33f, 28.9f);
        glVertex2f(14.0f, 30.0f);
        glVertex2f(10.09f, 26.88f);
        glVertex2f(13.82f, 28.01f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 480);
    glutInitWindowPosition(150, 50);
    glutCreateWindow("Jordan Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
