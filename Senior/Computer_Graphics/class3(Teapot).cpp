#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

// 아직 조명이 없어서 부피감이 없어보임

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidTeapot(0.5);
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(1500, 500);
    glutCreateWindow("GLUT TEAPOT");
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
