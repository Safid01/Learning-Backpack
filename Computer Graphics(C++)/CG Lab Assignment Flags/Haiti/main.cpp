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
        glColor3f(0.0f, 0.15f, 0.65f);
        glVertex2f(0.0f, 30.0f);
        glVertex2f(100.0f, 30.0f);
        glVertex2f(100.0f, 60.0f);
        glVertex2f(0.0f, 60.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.75f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(100.0f, 0.0f);
        glVertex2f(100.0f, 30.0f);
        glVertex2f(0.0f, 30.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(36.0f, 20.0f);
        glVertex2f(64.0f, 20.0f);
        glVertex2f(64.0f, 40.0f);
        glVertex2f(36.0f, 40.0f);
    glEnd();

    glLineWidth(2.0f);

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.45f, 0.0f);
        glVertex2f(50.0f, 22.0f);
        glVertex2f(50.0f, 37.0f);
        glVertex2f(50.0f, 37.0f);
        glVertex2f(45.0f, 33.0f);
        glVertex2f(50.0f, 37.0f);
        glVertex2f(55.0f, 33.0f);
        glVertex2f(50.0f, 34.0f);
        glVertex2f(43.0f, 32.0f);
        glVertex2f(50.0f, 34.0f);
        glVertex2f(57.0f, 32.0f);
    glEnd();
    glLineWidth(1.0f);

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.2f, 0.8f);
        glVertex2f(40.0f, 35.0f);
        glVertex2f(47.0f, 32.0f);
        glVertex2f(40.0f, 29.0f);
        glVertex2f(60.0f, 35.0f);
        glVertex2f(53.0f, 32.0f);
        glVertex2f(60.0f, 29.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 0.0f, 0.0f);
        glVertex2f(40.0f, 31.0f);
        glVertex2f(47.0f, 28.0f);
        glVertex2f(40.0f, 25.0f);
        glVertex2f(60.0f, 31.0f);
        glVertex2f(53.0f, 28.0f);
        glVertex2f(60.0f, 25.0f);
    glEnd();

    glLineWidth(2.0f);

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(41.0f, 22.0f);
        glVertex2f(48.0f, 27.0f);
        glVertex2f(59.0f, 22.0f);
        glVertex2f(52.0f, 27.0f);
        glVertex2f(42.0f, 22.0f);
        glVertex2f(58.0f, 22.0f);
    glEnd();
    glLineWidth(1.0f);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 480);
    glutInitWindowPosition(150, 50);
    glutCreateWindow("Haiti Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
