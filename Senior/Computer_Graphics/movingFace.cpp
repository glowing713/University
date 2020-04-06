#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>
#include <math.h>
#define Pi 3.1415


unsigned char gKey = 'u'; // n: 무표정, w: 윙크, u: 평소
float gX, gY;
float gR = 0.98, gG = 0.80, gB = 0.69;


void MyDisplay() {
    GLfloat Size[2], Angle;
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 얼굴, 머리
    glColor3f(gR, gG, gB);    // 살색
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
    
    glColor3f(gR, gG, gB);    // 살색
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
        glVertex3f(0.1*cos(Angle)+gX, 0.1*sin(Angle)+gY, 0.0);
    }
    glEnd();
    
    switch (gKey) {
        case 'u':   // 평소
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
            break;
        case 'w':   // 윙크
            // 왼쪽 눈
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(-0.6, 0.2, 0.0);
            glVertex3f(-0.2, 0.3, 0.0);
            glVertex3f(-0.6, 0.4, 0.0);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-0.6, 0.3, 0.0);
            glVertex3f(-0.2, 0.3, 0.0);
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
            break;
        case 'n':   // 무표정
            // 왼쪽 눈
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_LINES);
            glVertex3f(-0.6, 0.3, 0.0);
            glVertex3f(-0.2, 0.3, 0.0);
            glEnd();
            
            // 오른쪽 눈
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_LINES);
            glVertex3f(0.2, 0.3, 0.0);
            glVertex3f(0.6, 0.3, 0.0);
            glEnd();
        default:
            break;
    }
    
    switch (gKey) {
        case 'u':   // 평소
            // 입
            glColor3f(0.91, 0.59, 0.45);
            glBegin(GL_POLYGON);
            glVertex3f(-0.3, -0.6, 0.0);
            glVertex3f(0.3, -0.6, 0.0);
            glVertex3f(0.3, -0.4, 0.0);
            glVertex3f(-0.3, -0.4, 0.0);
            glEnd();
            break;
        case 'w':   // 윙크
            // 입
            glColor3f(0.91, 0.59, 0.45);
            glBegin(GL_LINE_STRIP);
            glVertex3f(-0.3, -0.4, 0.0);
            glVertex3f(0.0, -0.5, 0.0);
            glVertex3f(0.3, -0.4, 0.0);
            glEnd();
            break;
        case 'n':   // 무표정
            // 입
            glColor3f(0.91, 0.59, 0.45);
            glBegin(GL_LINES);
            glVertex3f(-0.4, -0.5, 0.0);
            glVertex3f(0.4, -0.5, 0.0);
            glEnd();
            break;
            
        default:
            break;
    }
    
    
    glutSwapBuffers();
}


void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
            
        case 'n':
        case 'w':
        case 'u':
            gKey = key; break;
            
        case 'D':
            gR = 1 - 0.76; gG = 1 - 0.55; gB = 1 - 0.36;
            glClearColor(0.76, 0.55, 0.36, 1.0);
            break;
        case 'J':
            gR = 1 - 0.87; gG = 1 - 0.38; gB = 1 - 0.29;
            glClearColor(0.87, 0.38, 0.29, 1.0);
            break;
        case 'P':
            gR = 1 - 0.85; gG = 1 - 0.72; gB = 1 - 0.77;
            glClearColor(0.85, 0.72, 0.77, 1.0);
            break;
        case 'B':
            gR = 1 - 0.98; gG = 1 - 0.80; gB = 1 - 0.69;
            glClearColor(0.98, 0.80, 0.69, 1.0);
            break;
    }
    glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
    // 코 움직이기
    switch (key) {
        case GLUT_KEY_LEFT:
            gX -= 0.1;  break;
        case GLUT_KEY_RIGHT:
            gX += 0.1;  break;
        case GLUT_KEY_DOWN:
            gY -= 0.1;  break;
        case GLUT_KEY_UP:
            gY += 0.1;  break;
        case GLUT_KEY_F5:
            gX = 0; gY = 0;
            glClearColor(1.0, 1.0, 1.0, 1.0);
            gR = 0.98; gG = 0.80; gB = 0.69;
            break;
    }
    glutPostRedisplay();
}

void MyReshape(int NewWidth, int NewHeight) {
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)800;
    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)800;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5 * WidthFactor, 1.5 * WidthFactor, -1.5 * HeightFactor, 1.5 * HeightFactor, -1.5, 1.5);
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(-1.5, 1.5, -1.5, 1.5, -1.5, 1.5);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(750, 750);
    glutInitWindowPosition(1000, 200);
    glutCreateWindow("n: 무표정, w: 윙크, u: 평소, B: 기본 살색, D: Deer색, J: Jelly Bean색, P: Pink Lavender색");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutSpecialFunc(MySpecial);
    glutMainLoop();
    return 0;
}
