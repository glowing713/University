#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>


void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(1.0, 2.0, 1.0);
    glutWireTeapot(0.3);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Composite Transformation");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
