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

    // number of steps = the larger of |dx| , |dy>   (works for any slope, including vertical)
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
    if (dx >= dy)                          // gentle slope, |m| <= 1
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
    else                                    // steep slope, |m| > 1
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

// Rectangle built purely out of 4 Bresenham lines (used for platform / pillars / flag border)
void rectBresenham(int x1, int y1, int x2, int y2)
{
    bresenhamLine(x1, y1, x2, y1);
    bresenhamLine(x2, y1, x2, y2);
    bresenhamLine(x2, y2, x1, y2);
    bresenhamLine(x1, y2, x1, y1);
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

// Solid-looking circle: just runs Midpoint Circle for every radius from 1..r (still Midpoint Circle only)
void filledCircle(int xc, int yc, int r)
{
    for (int rr = 1; rr <= r; rr++)
        midpointCircle(xc, yc, rr);
}

// ---------------------------------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0f);

    // ================= PART A: Bangladesh Flag =================
    glColor3f(0.0f, 0.4f, 0.0f);
    rectBresenham(420, 350, 600, 430);           // flag border/frame -> Bresenham

    glColor3f(1.0f, 0.0f, 0.0f);
    filledCircle(485, 390, 25);                  // red sun, left of center -> Midpoint Circle

    glColor3f(0.4f, 0.2f, 0.0f);
    ddaLine(420, 150, 420, 430, true);            // flagpole -> DDA (prints first 5 points)

    // ================= PART B: Shaheed Minar =================
    glColor3f(0.45f, 0.45f, 0.45f);
    rectBresenham(100, 50, 320, 70);              // base platform -> Bresenham

    int pillarX[5]  = {105, 150, 195, 240, 285};
    int pillarTop[5] = {130, 160, 220, 160, 130}; // middle pillar tallest
    for (int i = 0; i < 5; i++)
        rectBresenham(pillarX[i], 70, pillarX[i] + 15, pillarTop[i]);  // pillar edges -> Bresenham

    glColor3f(0.3f, 0.3f, 0.3f);
    for (int i = 0; i < 5; i++)                                       // decorative cross-lines -> DDA
        ddaLine((float)pillarX[i], 70 + (pillarTop[i] - 70) / 2.0f,
                (float)(pillarX[i] + 15), 70 + (pillarTop[i] - 70) / 2.0f);

    glColor3f(0.45f, 0.45f, 0.45f);
    midpointCircle(195 + 7, 220, 45, true);       // top arch above tallest pillar -> Midpoint Circle

    // ================= PART C: Extra elements (2 chosen) =================
    // Extra 1: Sun rays around the flag's sun -> DDA
    glColor3f(1.0f, 0.55f, 0.0f);
    for (int a = 0; a < 360; a += 45)
    {
        float rad = a * 3.14159f / 180.0f;
        float sx = 485 + 28 * cos(rad), sy = 390 + 28 * sin(rad);
        float ex = 485 + 42 * cos(rad), ey = 390 + 42 * sin(rad);
        ddaLine(sx, sy, ex, ey);
    }

    // Extra 2: Stars in the sky (line-only) -> Bresenham
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

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    // Pixel coordinate system so integer steps in the algorithms map 1:1 to screen pixels
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
