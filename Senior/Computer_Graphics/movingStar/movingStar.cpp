#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

GLfloat Delta = 0.0;
GLboolean gIsRight = true;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -0.4 + Delta, 0.0);
    glVertex3f(0.0, -0.3 + Delta, 0.0);
    glVertex3f(-0.2, -0.2 + Delta, 0.0);
    glVertex3f(-0.3, 0.0 + Delta, 0.0);
    glVertex3f(-0.4, -0.2 + Delta, 0.0);
    glVertex3f(-0.6, -0.3 + Delta, 0.0);
    glVertex3f(-0.4, -0.4 + Delta, 0.0);
    glVertex3f(-0.5, -0.6 + Delta, 0.0);
    glVertex3f(-0.3, -0.5 + Delta, 0.0);
    glVertex3f(-0.1, -0.6 + Delta, 0.0);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 0.1 - Delta, 0.0);
    glVertex3f(0.7, 0.2 - Delta, 0.0);
    glVertex3f(0.4, 0.3 - Delta, 0.0);
    glVertex3f(0.3, 0.6 - Delta, 0.0);
    glVertex3f(0.2, 0.3 - Delta, 0.0);
    glVertex3f(-0.1, 0.2 - Delta, 0.0);
    glVertex3f(0.2, 0.1 - Delta, 0.0);
    glVertex3f(0.1, -0.2 - Delta, 0.0);
    glVertex3f(0.3, 0.0 - Delta, 0.0);
    glVertex3f(0.5, -0.2 - Delta, 0.0);
    glEnd();
    glutSwapBuffers();
}


void MyTimer(int Value) {
    if (gIsRight == true) {
        Delta = Delta + 0.05;
        if (Delta > 2.5)
            gIsRight = false;
    }else {
        Delta = Delta - 0.05;
        if (Delta < -2.5)
            gIsRight = true;
    }
    
    glutPostRedisplay();
    glutTimerFunc(1, MyTimer, 1);
}


void MyInit() {
    glClearColor(0.51, 0.59, 0.53, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Timer Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutTimerFunc(1, MyTimer, 1);
    
    glutMainLoop();
    return 0;
}
