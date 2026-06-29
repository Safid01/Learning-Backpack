#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clears the screen. Removes old drawings. GL_COLOR_BUFFER_BIT → means clear colour buffer.Think of it like: Erase the board before drawing again.

    glPointSize(100.0f); // Sets point size to 10 pixels. Default size is very small (1 pixel). So this makes it visible.

    glBegin(GL_POINTS); // Start drawing a primitive. GL_POINTS means we are drawing points. OpenGL works like: Start → Define → End
        glColor3f(1.0f, 0.0f, 0.0f); // glColor3f() sets RGB colour using 3 float values (0.0–1.0): 1.0 = full intensity, 0.0 = none → (1,0,0)=Red, (0,1,0)=Green, (0,0,1)=Blue
        glVertex2f(125, 200); // glVertex2f() defines a 2D coordinate using 2 float values (x,y); (0,0) is the centre, so it draws the red point at the centre.
    glEnd(); // glEnd() ends the drawing block and must always be used after glBegin().

    glFlush();
}

void init() // This runs once before drawing starts.
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 250, 0, 250);
    // gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 400);
    glutInitWindowPosition(250, 150);

    glutCreateWindow("Point testing - OpenGL");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
