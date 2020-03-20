#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

void MakeStar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.4, 0.0);
    glVertex3f(0.0, -0.3, 0.0);
    glVertex3f(-0.2, -0.2, 0.0);
    glVertex3f(-0.3, 0.0, 0.0);
    glVertex3f(-0.4, -0.2, 0.0);
    glVertex3f(-0.6, -0.3, 0.0);
    glVertex3f(-0.4, -0.4, 0.0);
    glVertex3f(-0.5, -0.6, 0.0);
    glVertex3f(-0.3, -0.5, 0.0);
    glVertex3f(-0.1, -0.6, 0.0);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 0.2, 0.0);
    glVertex3f(0.6, 0.3, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
    glVertex3f(0.3, 0.6, 0.0);
    glVertex3f(0.2, 0.4, 0.0);
    glVertex3f(0.0, 0.3, 0.0);
    glVertex3f(0.2, 0.2, 0.0);
    glVertex3f(0.1, 0.0, 0.0);
    glVertex3f(0.3, 0.1, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("과제#1 - 별 그리기");
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glutDisplayFunc(MakeStar);
    glutMainLoop();
    return 0;
}
