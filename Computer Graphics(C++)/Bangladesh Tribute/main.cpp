// Assignment 2 - Part 1: Bangladesh Tribute Scene
// Rule: Only DDA Line, Bresenham Line, and Midpoint Circle are used to plot points.
// No OpenGL built-in shape functions (GL_QUADS/GL_TRIANGLES/etc.) are used anywhere -
// every pixel is plotted individually with glVertex2i inside GL_POINTS, exactly like
// the DDA example that was taught in class.

#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdio>

// ---------------------------------------------------------------------------
// DDA LINE ALGORITHM
// ---------------------------------------------------------------------------
void ddaLine(float x1, float y1, float x2, float y2, bool printPoints = false)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = (fabs(dx) > fabs(dy)) ? (int)fabs(dx) : (int)fabs(dy);
    if (steps == 0) steps = 1;

    float xInc = dx / steps;
    float yInc = dy / steps;
    float x = x1, y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(x, y);
        if (printPoints && i < 5)
            printf("DDA Line  -> Point %d: (%.2f, %.2f)\n", i + 1, x, y);
        x += xInc;
        y += yInc;
    }
    glEnd();
}

// ---------------------------------------------------------------------------
// BRESENHAM LINE ALGORITHM (integer, handles all slopes/octants)
// ---------------------------------------------------------------------------
void bresenhamLine(int x1, int y1, int x2, int y2, bool printPoints = false)
{
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
    int x = x1, y = y1;
    int count = 0;

    glBegin(GL_POINTS);
    if (dx >= dy)
    {
        int p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++)
        {
            glVertex2i(x, y);
            if (printPoints && count < 5) { printf("Bresenham Line -> Point %d: (%d, %d)\n", count + 1, x, y); count++; }
            if (p >= 0) { y += sy; p -= 2 * dx; }
            x += sx;
            p += 2 * dy;
        }
    }
    else
    {
        int p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++)
        {
            glVertex2i(x, y);
            if (printPoints && count < 5) { printf("Bresenham Line -> Point %d: (%d, %d)\n", count + 1, x, y); count++; }
            if (p >= 0) { x += sx; p -= 2 * dy; }
            y += sy;
            p += 2 * dx;
        }
    }
    glEnd();
}

// Outline rectangle, 4 Bresenham lines
void rectBresenham(int x1, int y1, int x2, int y2)
{
    bresenhamLine(x1, y1, x2, y1);
    bresenhamLine(x2, y1, x2, y2);
    bresenhamLine(x2, y2, x1, y2);
    bresenhamLine(x1, y2, x1, y1);
}

// Solid-filled rectangle: scanline of horizontal Bresenham lines (still pure Bresenham, no glRect/GL_QUADS)
void fillRectBresenham(int x1, int y1, int x2, int y2)
{
    for (int y = y1; y <= y2; y++)
        bresenhamLine(x1, y, x2, y);
}

// ---------------------------------------------------------------------------
// MIDPOINT CIRCLE ALGORITHM (8-way symmetry)
// ---------------------------------------------------------------------------
void plotCirclePoints(int xc, int yc, int x, int y)
{
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

void midpointCircle(int xc, int yc, int r, bool printPoints = false)
{
    int x = 0, y = r;
    int p = 1 - r;
    int count = 0;

    glBegin(GL_POINTS);
    plotCirclePoints(xc, yc, x, y);
    while (x < y)
    {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        plotCirclePoints(xc, yc, x, y);
        if (printPoints && count < 5) { printf("Midpoint Circle -> Point %d: (%d, %d)\n", count + 1, xc + x, yc + y); count++; }
    }
    glEnd();
}

// Solid disc: runs Midpoint Circle for every radius 1..r -> looks fully filled, still Midpoint Circle only
void filledCircle(int xc, int yc, int r, bool printPoints = false)
{
    for (int rr = 1; rr <= r; rr++)
        midpointCircle(xc, yc, rr, printPoints && rr == r);   // only print sample points from the outermost pass
}

// Upper half-circle "dome" made only from Midpoint-Circle-generated points -> used for bird wings
void upperArc(int cx, int cy, int r)
{
    int x = 0, y = r;
    int p = 1 - r;
    glBegin(GL_POINTS);
    glVertex2i(cx, cy + y);
    while (x < y)
    {
        x++;
        if (p < 0) p += 2 * x + 1;
        else { y--; p += 2 * (x - y) + 1; }
        glVertex2i(cx + x, cy + y);
        glVertex2i(cx - x, cy + y);
        if (y >= x)
        {
            glVertex2i(cx + y, cy + x);
            glVertex2i(cx - y, cy + x);
        }
    }
    glEnd();
}

// Flower = small filled circle (head) + straight stem (DDA)
void drawFlower(int cx, int headY, int groundY)
{
    glColor3f(1.0f, 0.4f, 0.7f);
    filledCircle(cx, headY, 4);                 // flower head -> Midpoint Circle
    glColor3f(0.1f, 0.5f, 0.1f);
    ddaLine((float)cx, (float)groundY, (float)cx, (float)(headY - 4));  // stem -> DDA
}

// ---------------------------------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0f);

    // ================= PART A: Bangladesh Flag =================
    glColor3f(0.0f, 0.5f, 0.0f);
    fillRectBresenham(420, 350, 600, 430);        // flag background, solid green -> Bresenham scanlines
    glColor3f(0.0f, 0.25f, 0.0f);
    rectBresenham(420, 350, 600, 430);             // crisp border on top -> Bresenham

    glColor3f(1.0f, 0.0f, 0.0f);
    filledCircle(485, 390, 25);                    // red sun, solid -> Midpoint Circle

    glColor3f(0.4f, 0.2f, 0.0f);
    ddaLine(420, 150, 420, 430, true);              // flagpole -> DDA (prints first 5 points)

    // ================= PART B: Shaheed Minar =================
    glColor3f(0.45f, 0.45f, 0.45f);
    rectBresenham(100, 50, 320, 70);                // base platform -> Bresenham

    int pillarX[5]   = {105, 150, 195, 240, 285};
    int pillarTop[5] = {130, 160, 220, 160, 130};
    for (int i = 0; i < 5; i++)
        rectBresenham(pillarX[i], 70, pillarX[i] + 15, pillarTop[i]);   // pillar edges -> Bresenham

    glColor3f(0.3f, 0.3f, 0.3f);
    for (int i = 0; i < 5; i++)                                        // decorative cross-lines -> DDA
        ddaLine((float)pillarX[i], 70 + (pillarTop[i] - 70) / 2.0f,
                (float)(pillarX[i] + 15), 70 + (pillarTop[i] - 70) / 2.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    filledCircle(210, 220, 20, true);               // arch, centered over the whole minar (base spans 100-320), solid red -> Midpoint Circle

    // ================= PART C: Extra elements (all six) =================

    // 1) Sun rays around the flag's sun -> DDA
    glColor3f(1.0f, 0.55f, 0.0f);
    for (int a = 0; a < 360; a += 45)
    {
        float rad = a * 3.14159f / 180.0f;
        float sx = 485 + 28 * cos(rad), sy = 390 + 28 * sin(rad);
        float ex = 485 + 42 * cos(rad), ey = 390 + 42 * sin(rad);
        ddaLine(sx, sy, ex, ey);
    }

    // 2) Stars in the sky -> Bresenham
    glColor3f(1.0f, 0.85f, 0.0f);
    int starX[3] = {60, 350, 600};
    int starY[3] = {460, 460, 460};
    for (int i = 0; i < 3; i++)
    {
        int sx = starX[i], sy = starY[i];
        bresenhamLine(sx - 6, sy, sx + 6, sy);
        bresenhamLine(sx, sy - 6, sx, sy + 6);
        bresenhamLine(sx - 4, sy - 4, sx + 4, sy + 4);
        bresenhamLine(sx - 4, sy + 4, sx + 4, sy - 4);
    }

    // 3) Road / footpath in front of the Shaheed Minar -> Bresenham
    glColor3f(0.35f, 0.35f, 0.35f);
    bresenhamLine(70, 30, 350, 30);                 // top edge of road
    bresenhamLine(70, 15, 350, 15);                 // bottom edge of road
    for (int x = 80; x <= 340; x += 20)             // dashed centre ticks
        bresenhamLine(x, 21, x + 8, 21);

    // 4) Flowers along the roadside -> Circle (head) + DDA (stem)
    int flowerX[5] = {95, 145, 195, 245, 295};
    for (int i = 0; i < 5; i++)
        drawFlower(flowerX[i], 40, 31);

    // 5) Clouds, overlapping circles -> Midpoint Circle
    glColor3f(0.85f, 0.85f, 0.85f);
    midpointCircle(160, 400, 14);
    midpointCircle(180, 408, 18);
    midpointCircle(205, 400, 12);

    midpointCircle(560, 410, 12);
    midpointCircle(580, 400, 16);

    // 6) Birds, two small arcs made from circle points -> Midpoint Circle
    glColor3f(0.0f, 0.0f, 0.0f);
    upperArc(355, 445, 7);
    upperArc(370, 445, 7);

    upperArc(400, 425, 6);
    upperArc(413, 425, 6);

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(150, 50);
    glutCreateWindow("Bangladesh Tribute Scene - DDA / Bresenham / Midpoint Circle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
