#include <windows.h>
#include <gl/glut.h>

void PaintHouse(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    // coord axis
    glLineWidth(3);
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2i(-250, 0);
    glVertex2i(250, 0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(0, -250);
    glVertex2i(0, 250);
    glEnd();


    // yellow wall
    glColor3f(255.0f, 178.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(-8, 3);
    glVertex2i(8, 3);
    glVertex2i(8, -8);
    glVertex2i(-8, -8);
    glEnd();

    glColor3f(205.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2i(-8, 3);
    glVertex2i(0, 8);
    glVertex2i(8, 3);
    glEnd();

    glColor3f(0.0f, 178.0f, 127.0f);
    glBegin(GL_QUADS);
    glVertex2i(3, -1);
    glVertex2i(7, -1);
    glVertex2i(7, -4);
    glVertex2i(3, -4);
    glEnd();

    glColor3f(0.0f, 0.0f, 5.0f);
    glBegin(GL_QUADS);
    glVertex2i(-6, -4);
    glVertex2i(-3, -4);
    glVertex2i(-3, -8);
    glVertex2i(-6, -8);
    glEnd();

    // execute OpenGL commands
    glFlush();
}

void Inicializa(void)
{
    // defines background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void ReshapeWindow(GLsizei w, GLsizei h)
{
     // avoid divison by 0
    if (h == 0) h = 1;

    // set viewport dimension
    glViewport(0, 0, w, h);

    // init coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // sets coordinate system size
    gluOrtho2D(-10.0f, 10.0f, -10.0f, 10.0f);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 350);
    glutInitWindowPosition(500, 200);
    glutCreateWindow("House");
    glutDisplayFunc(PaintHouse);
    glutReshapeFunc(ReshapeWindow);
    Inicializa();
    glutMainLoop();
}