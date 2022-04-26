#include <windows.h>
#include <gl/glut.h>

constexpr float chartSize = 10;
constexpr float squareSideLength = 7;

float deltaY = 0;

void Init(float r, float g, float b)
{
    // defines background color
    glClearColor(r / 255, g / 255, b / 255, 1.0f);
}

// callback function called when viewport changes
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

void HandleKeyboard(unsigned char key, int x, int y) {
    // x and y: mouse position
    if (key == 27) {
        exit(0);
    }
    else if (key == 32) {
        deltaY = 0.5f;
    }
    else {
        deltaY = 0;
    }

    glutPostRedisplay();
}

void PaintSquare(float x0, float y0, float l)
{
    glBegin(GL_QUADS);

    glVertex2f(x0 - l / 2, y0 + l / 2);
    glVertex2f(x0 + l / 2, y0 + l / 2);
    glVertex2f(x0 + l / 2, y0 - l / 2);
    glVertex2f(x0 - l / 2, y0 - l / 2);

    glEnd();
}

void Render()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3ub(255, 0, 0);

    glTranslatef(0, deltaY, 0);
    PaintSquare(0, 0, squareSideLength);

    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(410, 380);
    glutInitWindowPosition(500, 200);
    glutCreateWindow("Square up");
    
    glutDisplayFunc(Render);
    glutReshapeFunc(ChangeViewPort);
    glutKeyboardFunc(HandleKeyboard);
    
    Init(255, 255, 255);
    
    glutMainLoop();
}