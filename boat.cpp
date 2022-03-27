#include <windows.h>
#include <gl/glut.h>

float chartSize = 20;

void PaintBoat(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    //glLineWidth(3);

    // Doca vermelha
    glColor3ub(237.0f, 28.0f, 36.0f);
    glBegin(GL_QUADS);
    glVertex2i(-14, -8);
    glVertex2i(14, -8);
    glVertex2i(8, -16);
    glVertex2i(-8, -16);
    glEnd();

    // Vela cinza
    glColor3ub(195.0f, 195.0f, 195.0f);
    glBegin(GL_QUADS);
    glVertex2i(-10, -4);
    glVertex2i(-4, 12);
    glVertex2i(-3, 12);
    glVertex2i(8, -4);
    glEnd();

    // Mastro marrom
    glColor3ub(128.0f, 64.0f, 36.0f);
    glBegin(GL_QUADS);
    glVertex2i(-4, -8);
    glVertex2i(-4, 12);
    glVertex2i(-3, 12);
    glVertex2i(-3, -8);
    glEnd();

    // Bandeira azul
    glColor3ub(63.0f, 72.0f, 204.0f);
    glBegin(GL_QUADS);
    glVertex2i(-4, 12);
    glVertex2i(-4, 15);
    glVertex2i(3, 15);
    glVertex2i(3, 12);
    glEnd();

    // Executa os comandos OpenGL
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
    glutInitWindowSize(400, 350);
    glutInitWindowPosition(500, 200);
    glutCreateWindow("Boat");
    glutDisplayFunc(PaintBoat);
    glutReshapeFunc(ChangeViewPort);
    Init(255, 244, 208);
    glutMainLoop();
}