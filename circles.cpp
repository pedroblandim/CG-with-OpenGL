#include <windows.h>
#include <gl/glut.h>
#define _USE_MATH_DEFINES // use PI
#include <math.h>

float chartSize = 10;

void PaintCircle(float radius, float x0 = 0, float y0 = 0, float step = 1)
{   
    glBegin(GL_POLYGON);

    for (float i = 0; i < 360; i += step) {
        double rad =  M_PI * i / 180;

        float x = radius * cos(rad) + x0;
        float y = radius * sin(rad) + y0;
        
        glVertex2f(x, y);
    }

    glEnd();
}

void PaintBoat(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    float max_radius = 7;

    glColor3ub(0.0f, 0.0f, 51.0f);
    PaintCircle(max_radius);

    glColor3ub(0.0f, 0.0f, 153.0f);
    PaintCircle(max_radius / 4 * 3);

    glColor3ub(0.0f, 0.0f, 51.0f);
    PaintCircle(max_radius / 4 * 2);

    glColor3ub(255.0f, 255.0f, 255.0f);
    PaintCircle(max_radius / 4);

    // execute OpenGL
    glFlush();
}

void Init(float r, float g, float b)
{
    // defines background color
    glClearColor(r / 255.0f, g / 255, b / 255, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
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

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(410, 380);
    glutInitWindowPosition(500, 200);
    glutCreateWindow("Circles");
    glutDisplayFunc(PaintBoat);
    glutReshapeFunc(ChangeViewPort);
    Init(255, 255, 255);
    glutMainLoop();
}