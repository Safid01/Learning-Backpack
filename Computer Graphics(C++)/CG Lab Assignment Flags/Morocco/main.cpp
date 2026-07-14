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
        glColor3f(0.75f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(100.0f, 0.0f);
        glVertex2f(100.0f, 60.0f);
        glVertex2f(0.0f, 60.0f);
    glEnd();

    glLineWidth(4.0f);

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.45f, 0.0f);
        glVertex2f(50.0f, 45.0f);
        glVertex2f(58.82f, 17.86f);
        glVertex2f(35.73f, 34.64f);
        glVertex2f(64.27f, 34.64f);
        glVertex2f(41.18f, 17.86f);
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
    glutCreateWindow("Morocco Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
