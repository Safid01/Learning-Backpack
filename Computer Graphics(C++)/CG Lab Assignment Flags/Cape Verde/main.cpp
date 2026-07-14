#include <windows.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 60, 0);
}

void drawStar(float cx, float cy, float s)
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
        glColor3f(0.0f, 0.18f, 0.55f);
        glVertex2f(0, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 60);
        glVertex2f(0, 60);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0, 30);
        glVertex2f(100, 30);
        glVertex2f(100, 35);
        glVertex2f(0, 35);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.85f, 0.0f, 0.0f);
        glVertex2f(0, 35);
        glVertex2f(100, 35);
        glVertex2f(100, 40);
        glVertex2f(0, 40);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0, 40);
        glVertex2f(100, 40);
        glVertex2f(100, 45);
        glVertex2f(0, 45);
    glEnd();

    glColor3f(1.0f, 0.85f, 0.0f);

    drawStar(36, 22, 3.0f);

    drawStar(26, 25, 3.0f);
    drawStar(46, 25, 3.0f);

    drawStar(20, 33, 3.0f);
    drawStar(52, 33, 3.0f);

    drawStar(20, 43, 3.0f);
    drawStar(52, 43, 3.0f);

    drawStar(26, 50, 3.0f);
    drawStar(46, 50, 3.0f);

    drawStar(36, 53, 3.0f);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 480);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Cape Verde Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
