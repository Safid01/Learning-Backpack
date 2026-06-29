#include <GL/glut.h>
#include <cmath>
void drawLineDDA_mLess1(float x1, float y1, float x2, float y2)
{

    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy / dx;
    float x = x1;
    float y = y1;
    glBegin(GL_POINTS);

        for (int i = 0; i <= (int)dx; i++)
        {
            glVertex2f(x, y);
            x = x + 1;
            y = y + m; //make it round according to the rule // for m is less than 1
        }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    glColor3f(1.0f, 0.0f, 0.0f);   // Red
    // Example points (pixel coordinates)
    drawLineDDA_mLess1(250,250 ,400, 400);
    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1);
    // IMPORTANT: Use pixel coordinate system so x+1 means "one pixel step"
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA (|m|<=1) using GL_POINTS");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
