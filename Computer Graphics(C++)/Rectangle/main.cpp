#include <GL/glut.h>


void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-1, 1, -1, 1);

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw shapes using quads
    glBegin(GL_QUADS);

        // Quad 1 (Red)
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f,  0.1f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.2f,  0.1f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.2f,  0.7f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.8f,  0.7f);

        // Quad 2 (Green Mixed)
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.7f, -0.6f);
        glVertex2f(-0.1f, -0.6f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.1f,  0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f,  0.0f);


    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Quads");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
