#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 100, 0, 100);
    //gluOrtho2D(-1, 1, -1, 1);  // left, right , bottom , top
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);


        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(50.0f,50.0f);
        glVertex2f(50,80);

        glVertex2f(50,50);
        glVertex2f(80,50);

        // Line 1 (Blue)
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        // Line 2 (Red)
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.6f, -0.6f);
         //Line 3 (Green)
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.6f, -0.8f);
        glVertex2f(0.6f, 0.8f);

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(150, 50);
    glutCreateWindow("OpenGL Lines");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
