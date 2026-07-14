#include <windows.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 52, 0);
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

    //stripes
    for (int i = 0; i < 13; i++)
    {
        if (i % 2 == 0)
            glColor3f(0.70f, 0.0f, 0.0f);   // Red
        else
            glColor3f(1.0f, 1.0f, 1.0f);   // White

        glBegin(GL_QUADS);
            glVertex2f(0, i * 4);
            glVertex2f(100, i * 4);
            glVertex2f(100, (i + 1) * 4);
            glVertex2f(0, (i + 1) * 4);
        glEnd();
    }

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.12f, 0.35f);
        glVertex2f(0, 0);
        glVertex2f(40, 0);
        glVertex2f(40, 28);
        glVertex2f(0, 28);
    glEnd();

    //stars
    glColor3f(1.0f, 1.0f, 1.0f);

    drawStar(4, 3, 0.9f);
    drawStar(10, 3, 0.9f);
    drawStar(16, 3, 0.9f);
    drawStar(22, 3, 0.9f);
    drawStar(28, 3, 0.9f);
    drawStar(34, 3, 0.9f);

    drawStar(7, 6, 0.9f);
    drawStar(13, 6, 0.9f);
    drawStar(19, 6, 0.9f);
    drawStar(25, 6, 0.9f);
    drawStar(31, 6, 0.9f);

    drawStar(4, 9, 0.9f);
    drawStar(10, 9, 0.9f);
    drawStar(16, 9, 0.9f);
    drawStar(22, 9, 0.9f);
    drawStar(28, 9, 0.9f);
    drawStar(34, 9, 0.9f);

    drawStar(7, 12, 0.9f);
    drawStar(13, 12, 0.9f);
    drawStar(19, 12, 0.9f);
    drawStar(25, 12, 0.9f);
    drawStar(31, 12, 0.9f);

    drawStar(4, 15, 0.9f);
    drawStar(10, 15, 0.9f);
    drawStar(16, 15, 0.9f);
    drawStar(22, 15, 0.9f);
    drawStar(28, 15, 0.9f);
    drawStar(34, 15, 0.9f);

    drawStar(7, 18, 0.9f);
    drawStar(13, 18, 0.9f);
    drawStar(19, 18, 0.9f);
    drawStar(25, 18, 0.9f);
    drawStar(31, 18, 0.9f);

    drawStar(4, 21, 0.9f);
    drawStar(10, 21, 0.9f);
    drawStar(16, 21, 0.9f);
    drawStar(22, 21, 0.9f);
    drawStar(28, 21, 0.9f);
    drawStar(34, 21, 0.9f);

    drawStar(7, 24, 0.9f);
    drawStar(13, 24, 0.9f);
    drawStar(19, 24, 0.9f);
    drawStar(25, 24, 0.9f);
    drawStar(31, 24, 0.9f);

    drawStar(4, 27, 0.9f);
    drawStar(10, 27, 0.9f);
    drawStar(16, 27, 0.9f);
    drawStar(22, 27, 0.9f);
    drawStar(28, 27, 0.9f);
    drawStar(34, 27, 0.9f);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 416);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("USA Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
