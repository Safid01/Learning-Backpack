
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


void drawPalmFrond(float x1, float y1, float x2, float y2, float x3, float y3)
{
    drawTriangle(x1, y1, x2, y2, x3, y3);
}

void drawFlagCloth(float x, float y, float dir)
{
    // Blue upper half.
    setColor(0.0f, 0.15f, 0.7f);
    const float bluePts[4][2] = {{x, y}, {x + dir*34, y + 12}, {x + dir*34, y + 30}, {x, y + 18}};
    drawPolygon(bluePts, 4);

    // Red lower half.
    setColor(0.8f, 0.0f, 0.0f);
    const float redPts[4][2] = {{x, y - 18}, {x + dir*34, y - 6}, {x + dir*34, y + 12}, {x, y}};
    drawPolygon(redPts, 4);
}

void drawCannon(float cx, float cy, float dir)
{
    setColor(0.25f, 0.2f, 0.2f);
    drawRectangle(cx - 25, cy - 6, cx + 15, cy + 6);
    drawCircle(cx - 18, cy - 10, 7);
    drawCircle(cx + 6, cy - 10, 7);
    drawTriangle(cx + 15, cy + 6, cx + 35*dir, cy + 14, cx + 15, cy - 6);
}

void drawFlag()
{
    setColor(0.0f, 0.1f, 0.65f);
    drawRectangle(0, 300, 900, 600);
    setColor(0.8f, 0.0f, 0.0f);
    drawRectangle(0, 0, 900, 300);

    // White panel.
    setColor(1.0f, 1.0f, 1.0f);
    drawRectangle(310, 185, 590, 415);

    // Green ground mound.
    setColor(0.0f, 0.55f, 0.2f);
    const float hill[5][2] = {{360,225},{540,225},{520,255},{450,275},{380,255}};
    drawPolygon(hill, 5);

    // Cannons and drums.
    drawCannon(385, 246, -1);
    drawCannon(515, 246, 1);
    setColor(0.55f, 0.30f, 0.10f);
    drawRectangle(420, 232, 438, 254);
    drawRectangle(462, 232, 480, 254);
    setColor(0.85f, 0.65f, 0.20f);
    drawRectangle(420, 254, 438, 258);
    drawRectangle(462, 254, 480, 258);

    // Flag poles.
    setColor(0.55f, 0.35f, 0.15f);
    drawRectangle(408, 248, 412, 338);
    drawRectangle(488, 248, 492, 338);
    drawRectangle(430, 248, 434, 350);
    drawRectangle(466, 248, 470, 350);

    // Flag cloths.
    drawFlagCloth(412, 322, -1);
    drawFlagCloth(488, 322, 1);
    drawFlagCloth(434, 335, -1);
    drawFlagCloth(466, 335, 1);

    // Palm tree trunk.
    setColor(0.55f, 0.35f, 0.15f);
    drawRectangle(444, 250, 456, 360);

    // Palm fronds.
    setColor(0.0f, 0.45f, 0.0f);
    drawPalmFrond(450, 360, 390, 382, 430, 342);
    drawPalmFrond(450, 360, 510, 382, 470, 342);
    drawPalmFrond(450, 360, 385, 350, 430, 332);
    drawPalmFrond(450, 360, 515, 350, 470, 332);
    drawPalmFrond(450, 360, 410, 405, 446, 350);
    drawPalmFrond(450, 360, 490, 405, 454, 350);

    // Cap at top of palm.
    setColor(1.0f, 0.85f, 0.0f);
    drawRectangle(442, 360, 458, 372);

    // Decorative cannonballs / trophies.
    setColor(1.0f, 0.8f, 0.0f);
    drawCircle(405, 232, 5);
    drawCircle(495, 232, 5);
    drawCircle(425, 226, 5);
    drawCircle(475, 226, 5);

    // White ribbon banner.
    setColor(0.95f, 0.95f, 0.95f);
    const float ribbon[6][2] = {{395,212},{505,212},{520,220},{505,228},{395,228},{380,220}};
    drawPolygon(ribbon, 6);
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
    glutCreateWindow("Haiti Flag - CG Lab Assignment 1");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
