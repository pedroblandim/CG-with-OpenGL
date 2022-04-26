#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

constexpr float chartSize = 100;
constexpr float squareSize = 50;
float squareStep = 10;
float px = squareSize / 2;

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
    glClear(GL_COLOR_BUFFER_BIT);

    if (fabs(px) + (squareSize / 2) >= chartSize) {
        squareStep = -squareStep;
    }

    px += squareStep;

    PaintSquare(px, 0, squareSize); // drawing the point

    glFlush();
}

void Render(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    MoveSquare();

    glutSwapBuffers();
}

void Animate(int timer)
{
    glutPostRedisplay();
    glutTimerFunc(100, Animate, 0);
}

void ChangeViewPort(GLsizei w, GLsizei h)
{
    // avoid divison by 0
    if (h == 0) h = 1;

    // set viewport dimension
    glViewport(0, 0, w, h);

    // init coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // sets coordinate system size
    if (w <= h) {
        gluOrtho2D(-chartSize, chartSize, -chartSize * h / w, chartSize * h / w);
    }
    else {
        gluOrtho2D(-chartSize * w / h, chartSize * w / h, -chartSize, chartSize);
    }
}

void Init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(410, 410);
    glutInitWindowPosition(500, 200);

    glutCreateWindow("Move square");

    glutReshapeFunc(ChangeViewPort);
    glutDisplayFunc(Render);
    glutTimerFunc(100, Animate, 0);

    Init();

    glutMainLoop();
}