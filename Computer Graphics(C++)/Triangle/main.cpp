#include <windows.h>
#include <GL/glut.h>


void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-1, 1, -1, 1);

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // use of GL_TRIANGLES
    glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.0f, 1.0f);   // Blue
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.1f, 0.0f);
        glVertex2f(-0.4f, 0.3f);

        //Triangle (Mixed Colors)
        glColor3f(1.0f, 0.0f, 0.0f);   // Red
        glVertex2f(0.3f, -0.4f);

        glColor3f(0.0f, 1.0f, 0.0f);   // Green
        glVertex2f(0.9f, -0.4f);

        glColor3f(0.0f, 0.0f, 1.0f);   // Blue
        glVertex2f(0.6f, -0.9f);

    glEnd();
    // Use Of GL_LINE_LOOP
    glBegin(GL_LINE_LOOP);

        glColor3f(0.0f, 0.0f, 1.0f);

        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.0f, 0.25f);
        glVertex2f(0.5f, 0.25f);


    glEnd();


    // Use of polygons
    glBegin(GL_POLYGON);

        glVertex2f(-0.2f, 0.0f);
        glVertex2f( -0.1f, 0.2f);
        glVertex2f( .3f,  0.6f);
        glVertex2f(0.5f,  0.5f);
        glVertex2f(0.7f,  0.5f);

    glEnd();



    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(150, 50);
    glutCreateWindow("OpenGL Triangles");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
