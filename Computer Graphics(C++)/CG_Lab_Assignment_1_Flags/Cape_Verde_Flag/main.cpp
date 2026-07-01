
#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265359f;

void setColor(float r, float g, float b)
{
    glColor3f(r, g, b);
}

void drawRectangle(float x1, float y1, float x2, float y2)
{
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

void drawPolygon(const float pts[][2], int n)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
        glVertex2f(pts[i][0], pts[i][1]);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int segments = 100)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++)
    {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();
}

void drawFilledStar(int points, float cx, float cy, float outerR, float innerR, float rotationDeg)
{
    float vx[40], vy[40];
    int n = points * 2;

    for (int i = 0; i < n; i++)
    {
        float r = (i % 2 == 0) ? outerR : innerR;
        float angle = (rotationDeg + i * (180.0f / points)) * PI / 180.0f;
        vx[i] = cx + r * cos(angle);
        vy[i] = cy + r * sin(angle);
    }

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        glVertex2f(cx, cy);
        glVertex2f(vx[i], vy[i]);
        glVertex2f(vx[j], vy[j]);
    }
    glEnd();
}

void drawPentagram(float cx, float cy, float r)
{
    float px[5], py[5];
    for (int i = 0; i < 5; i++)
    {
        float angle = (90 + i * 72) * PI / 180.0f;
        px[i] = cx + r * cos(angle);
        py[i] = cy + r * sin(angle);
    }

    int order[6] = {0, 2, 4, 1, 3, 0};
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 6; i++)
        glVertex2f(px[order[i]], py[order[i]]);
    glEnd();
    glLineWidth(1);
}

void drawShield(float left, float top, float w, float h)
{
    float right = left + w;
    float bottom = top - h;
    float midY = bottom + h * 0.33f;
    const float pts[7][2] = {
        {left, top},
        {right, top},
        {right, midY},
        {left + w * 0.75f, bottom + h * 0.05f},
        {left + w * 0.50f, bottom},
        {left + w * 0.25f, bottom + h * 0.05f},
        {left, midY}
    };
    drawPolygon(pts, 7);
}

void drawMapleLeaf(float cx, float cy, float s)
{
    const float pts[17][2] = {
        {cx,           cy + 150*s},
        {cx - 25*s,    cy + 80*s},
        {cx - 80*s,    cy + 110*s},
        {cx - 60*s,    cy + 45*s},
        {cx - 125*s,   cy + 45*s},
        {cx - 70*s,    cy + 5*s},
        {cx - 95*s,    cy - 70*s},
        {cx - 25*s,    cy - 35*s},
        {cx - 20*s,    cy - 130*s},
        {cx + 20*s,    cy - 130*s},
        {cx + 25*s,    cy - 35*s},
        {cx + 95*s,    cy - 70*s},
        {cx + 70*s,    cy + 5*s},
        {cx + 125*s,   cy + 45*s},
        {cx + 60*s,    cy + 45*s},
        {cx + 80*s,    cy + 110*s},
        {cx + 25*s,    cy + 80*s}
    };

    // Manual triangulation around a center point to avoid broken concave polygon fill.
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 17; i++)
    {
        int j = (i + 1) % 17;
        glVertex2f(cx, cy + 10*s);
        glVertex2f(pts[i][0], pts[i][1]);
        glVertex2f(pts[j][0], pts[j][1]);
    }
    glEnd();
}

void drawUnionJack(float x, float y, float w, float h)
{
    setColor(0.0f, 0.0f, 0.45f);
    drawRectangle(x, y, x + w, y + h);

    setColor(1.0f, 1.0f, 1.0f);
    glLineWidth(26);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x + w, y);
        glVertex2f(x, y + h);
    glEnd();

    drawRectangle(x + w*0.41f, y, x + w*0.59f, y + h);
    drawRectangle(x, y + h*0.41f, x + w, y + h*0.59f);

    setColor(0.8f, 0.0f, 0.0f);
    glLineWidth(12);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x + w, y);
        glVertex2f(x, y + h);
    glEnd();

    drawRectangle(x + w*0.455f, y, x + w*0.545f, y + h);
    drawRectangle(x, y + h*0.455f, x + w, y + h*0.545f);
    glLineWidth(1);
}


void drawFlag()
{
    setColor(0.0f, 0.25f, 0.65f);
    drawRectangle(0, 0, 900, 600);

    setColor(1.0f, 1.0f, 1.0f);
    drawRectangle(0, 225, 900, 265);
    drawRectangle(0, 315, 900, 355);

    setColor(0.8f, 0.0f, 0.0f);
    drawRectangle(0, 265, 900, 315);

    setColor(1.0f, 0.85f, 0.0f);
    float cx = 260, cy = 300, r = 105;
    for (int i = 0; i < 10; i++)
    {
        float angle = (90 + i * 36) * PI / 180.0f;
        float sx = cx + r * cos(angle);
        float sy = cy + r * sin(angle);
        drawFilledStar(5, sx, sy, 18, 7.5f, 90);
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawFlag();
    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 900, 0, 600);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cape Verde Flag - CG Lab Assignment 1");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
