#include <windows.h>
#include <gl/glut.h>
#define _USE_MATH_DEFINES // use PI
#include <math.h>

float chartSize = 10;
float max_radius = 7;
float initial_angle = 0;

void PaintCircle(float radius, float x0 = 0, float y0 = 0, float initial_angle = 0, float step = 1)
{
    glBegin(GL_POLYGON);

    for (float i = initial_angle; i < 360 + initial_angle; i += step) {

        float color = 255.0f * (i - initial_angle) / 360.0f;

        glColor3ub(color, color*2, color*3);

        double rad = M_PI * i / 180;

        float x = radius * cos(rad) + x0;
        float y = radius * sin(rad) + y0;

        glVertex2f(x, y);
    }

    glEnd();
    glFlush();
}

void Render(void)
{
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);

    PaintCircle(max_radius, 0, 0, initial_angle--);

    glutSwapBuffers();
}

void Animate(int timer)
{
    glutPostRedisplay();
    glutTimerFunc(10, Animate, 0);
}


void Init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
    
    glutCreateWindow("Rotating circles");
    
    glutReshapeFunc(ChangeViewPort);
    glutDisplayFunc(Render);
    glutTimerFunc(100, Animate, 0);

    Init();
    
    glutMainLoop();
}