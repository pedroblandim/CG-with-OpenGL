#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

constexpr float chartSize = 100;
constexpr float squareStep = 10;
constexpr float squareSize = 50;

// this creates delay between two actions
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void PaintSquare(float x0, float y0, float l)
{
    glColor3ub(153, 51, 153);

    glBegin(GL_QUADS);

    glVertex2f(x0 - l / 2, y0 + l / 2);
    glVertex2f(x0 + l / 2, y0 + l / 2);
    glVertex2f(x0 + l / 2, y0 - l / 2);
    glVertex2f(x0 - l / 2, y0 - l / 2);

    glEnd();
}

void MoveSquare()
{
    int deltaX = squareStep;
    float px = squareSize / 2;

    while (1) {
        glClear(GL_COLOR_BUFFER_BIT);

        px += deltaX;

        if (fabs(px) + (squareSize / 2) > chartSize) {
            deltaX = -deltaX;
        }

        PaintSquare(px, 0, squareSize); // drawing the point

        glFlush();
        delay(50);
    }
}

void Render(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    MoveSquare();
    
    glutSwapBuffers();
}

void Init(float r, float g, float b)
{
    // defines background color
    glClearColor(r / 255, g / 255, b / 255, 1.0f);

    gluOrtho2D(-chartSize, chartSize, -chartSize, chartSize);
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(410, 380);
    glutInitWindowPosition(500, 200);
    
    glutCreateWindow("Move square");

    glutDisplayFunc(Render);

    Init(255, 255, 255);

    glutMainLoop();
}