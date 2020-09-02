#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <math.h>
#define Pi 3.1415

void MyDisplay() {
    GLfloat Size[2], Angle;
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 얼굴, 머리
    glColor3f(0.98, 0.80, 0.69);    // 살색
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glEnd();
    
    glColor3f(0.30, 0.18, 0.02);    // 갈색
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, 0.6, 0.0);
    glVertex3f(1.0, 0.6, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glEnd();
    
    glColor3f(0.98, 0.80, 0.69);    // 살색
    glBegin(GL_POLYGON);
    glVertex3f(-0.8, -1.0, 0.0);
    glVertex3f(0.8, -1.0, 0.0);
    glVertex3f(0.8, 0.7, 0.0);
    glVertex3f(-0.8, 0.7, 0.0);
    glEnd();
    
    glColor3f(0.30, 0.18, 0.02);    // 갈색
    glLineWidth(30.0);
    glGetFloatv(GL_POINT_SIZE_RANGE, Size);
    glPointSize(Size[0] * 10);
    glBegin(GL_LINE_LOOP);
    for (Angle = 0.0; Angle <= 2*Pi; Angle += Pi/180.0) {
        glVertex3f(0.1*cos(Angle), 0.1*sin(Angle), 0.0);
    }
    glEnd();
    
    // 왼쪽 눈
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.6, 0.2, 0.0);
    glVertex3f(-0.2, 0.2, 0.0);
    glVertex3f(-0.2, 0.4, 0.0);
    glVertex3f(-0.6, 0.4, 0.0);
    glEnd();
    glColor3f(0.20, 0.38, 0.45);
    glBegin(GL_POLYGON);
    glVertex3f(-0.4, 0.2, 0.0);
    glVertex3f(-0.2, 0.2, 0.0);
    glVertex3f(-0.2, 0.4, 0.0);
    glVertex3f(-0.4, 0.4, 0.0);
    glEnd();
    
    // 오른쪽 눈
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.2, 0.2, 0.0);
    glVertex3f(0.6, 0.2, 0.0);
    glVertex3f(0.6, 0.4, 0.0);
    glVertex3f(0.2, 0.4, 0.0);
    glEnd();
    glColor3f(0.20, 0.38, 0.45);
    glBegin(GL_POLYGON);
    glVertex3f(0.2, 0.2, 0.0);
    glVertex3f(0.4, 0.2, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
    glVertex3f(0.2, 0.4, 0.0);
    glEnd();
    
    // 입
    glColor3f(0.91, 0.59, 0.45);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -0.6, 0.0);
    glVertex3f(0.3, -0.6, 0.0);
    glVertex3f(0.3, -0.4, 0.0);
    glVertex3f(-0.3, -0.4, 0.0);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Minecraft__Steve");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
