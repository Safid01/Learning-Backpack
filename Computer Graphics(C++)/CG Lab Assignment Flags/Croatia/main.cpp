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
        glColor3f(0.8f, 0.0f, 0.0f);
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
        glColor3f(0.0f, 0.15f, 0.55f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(100.0f, 0.0f);
        glVertex2f(100.0f, 20.0f);
        glVertex2f(0.0f, 20.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(42.0f, 42.0f);
        glVertex2f(58.0f, 42.0f);
        glVertex2f(58.0f, 22.0f);
        glVertex2f(50.0f, 16.0f);
        glVertex2f(42.0f, 22.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.0f, 0.0f);

        glVertex2f(42.0f, 38.4f);
        glVertex2f(45.2f, 38.4f);
        glVertex2f(45.2f, 42.0f);
        glVertex2f(42.0f, 42.0f);

        glVertex2f(48.4f, 38.4f);
        glVertex2f(51.6f, 38.4f);
        glVertex2f(51.6f, 42.0f);
        glVertex2f(48.4f, 42.0f);

        glVertex2f(54.8f, 38.4f);
        glVertex2f(58.0f, 38.4f);
        glVertex2f(58.0f, 42.0f);
        glVertex2f(54.8f, 42.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.0f, 0.0f);

        glVertex2f(45.2f, 34.8f);
        glVertex2f(48.4f, 34.8f);
        glVertex2f(48.4f, 38.4f);
        glVertex2f(45.2f, 38.4f);

        glVertex2f(51.6f, 34.8f);
        glVertex2f(54.8f, 34.8f);
        glVertex2f(54.8f, 38.4f);
        glVertex2f(51.6f, 38.4f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.0f, 0.0f);

        glVertex2f(42.0f, 31.2f);
        glVertex2f(45.2f, 31.2f);
        glVertex2f(45.2f, 34.8f);
        glVertex2f(42.0f, 34.8f);

        glVertex2f(48.4f, 31.2f);
        glVertex2f(51.6f, 31.2f);
        glVertex2f(51.6f, 34.8f);
        glVertex2f(48.4f, 34.8f);

        glVertex2f(54.8f, 31.2f);
        glVertex2f(58.0f, 31.2f);
        glVertex2f(58.0f, 34.8f);
        glVertex2f(54.8f, 34.8f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.0f, 0.0f);

        glVertex2f(45.2f, 27.6f);
        glVertex2f(48.4f, 27.6f);
        glVertex2f(48.4f, 31.2f);
        glVertex2f(45.2f, 31.2f);

        glVertex2f(51.6f, 27.6f);
        glVertex2f(54.8f, 27.6f);
        glVertex2f(54.8f, 31.2f);
        glVertex2f(51.6f, 31.2f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.0f, 0.0f);

        glVertex2f(42.0f, 24.0f);
        glVertex2f(45.2f, 24.0f);
        glVertex2f(45.2f, 27.6f);
        glVertex2f(42.0f, 27.6f);

        glVertex2f(48.4f, 24.0f);
        glVertex2f(51.6f, 24.0f);
        glVertex2f(51.6f, 27.6f);
        glVertex2f(48.4f, 27.6f);

        glVertex2f(54.8f, 24.0f);
        glVertex2f(58.0f, 24.0f);
        glVertex2f(58.0f, 27.6f);
        glVertex2f(54.8f, 27.6f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.0f, 0.0f);
        glVertex2f(48.4f, 20.0f);
        glVertex2f(51.6f, 20.0f);
        glVertex2f(51.6f, 23.2f);
        glVertex2f(48.4f, 23.2f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.8f, 0.0f, 0.0f);

        glVertex2f(40.0f, 42.0f);
        glVertex2f(44.0f, 43.0f);
        glVertex2f(48.0f, 43.5f);
        glVertex2f(52.0f, 43.5f);
        glVertex2f(56.0f, 43.0f);
        glVertex2f(60.0f, 42.0f);

        glVertex2f(58.0f, 41.2f);
        glVertex2f(54.0f, 41.6f);
        glVertex2f(50.0f, 41.8f);
        glVertex2f(46.0f, 41.6f);
        glVertex2f(42.0f, 41.2f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.45f, 0.85f);

        glVertex2f(40.0f, 42.0f);
        glVertex2f(41.0f, 48.0f);
        glVertex2f(44.0f, 46.0f);
        glVertex2f(44.0f, 42.0f);
        glVertex2f(42.0f, 41.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.60f);

        glVertex2f(44.0f, 42.0f);
        glVertex2f(44.0f, 46.0f);
        glVertex2f(47.0f, 50.0f);
        glVertex2f(50.0f, 46.0f);
        glVertex2f(50.0f, 42.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.45f, 0.85f);

        glVertex2f(50.0f, 42.0f);
        glVertex2f(50.0f, 46.0f);
        glVertex2f(53.0f, 50.0f);
        glVertex2f(56.0f, 46.0f);
        glVertex2f(56.0f, 42.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.60f);

        glVertex2f(56.0f, 42.0f);
        glVertex2f(56.0f, 46.0f);
        glVertex2f(59.0f, 48.0f);
        glVertex2f(60.0f, 42.0f);
        glVertex2f(58.0f, 41.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0f, 0.85f, 0.0f);

        glVertex2f(42.0f, 43.5f); glVertex2f(42.0f, 46.0f);
        glVertex2f(40.8f, 44.7f); glVertex2f(43.2f, 44.7f);
        glVertex2f(41.2f, 43.9f); glVertex2f(42.8f, 45.5f);
        glVertex2f(42.8f, 43.9f); glVertex2f(41.2f, 45.5f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.0f, 0.0f);

        glVertex2f(44.5f, 45.0f);
        glVertex2f(49.5f, 44.3f);
        glVertex2f(49.5f, 43.3f);
        glVertex2f(44.5f, 44.0f);

        glVertex2f(44.5f, 42.8f);
        glVertex2f(49.5f, 42.1f);
        glVertex2f(49.5f, 41.1f);
        glVertex2f(44.5f, 41.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.85f, 0.0f);

        glVertex2f(51.5f, 45.0f);
        glVertex2f(50.7f, 46.5f);
        glVertex2f(52.3f, 46.5f);

        glVertex2f(54.5f, 45.0f);
        glVertex2f(53.7f, 46.5f);
        glVertex2f(55.3f, 46.5f);

        glVertex2f(53.0f, 42.7f);
        glVertex2f(52.2f, 44.2f);
        glVertex2f(53.8f, 44.2f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.75f, 0.0f);

        glVertex2f(57.5f, 44.7f);
        glVertex2f(59.3f, 44.7f);
        glVertex2f(60.0f, 43.7f);
        glVertex2f(59.3f, 42.7f);
        glVertex2f(57.5f, 42.7f);
        glVertex2f(56.9f, 43.7f);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(42.0f, 42.0f);
        glVertex2f(58.0f, 42.0f);
        glVertex2f(58.0f, 22.0f);
        glVertex2f(50.0f, 16.0f);
        glVertex2f(42.0f, 22.0f);
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
    glutCreateWindow("Croatia Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
