#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <math.h>
#include <cstdio>
#define WIN_WIDTH 1000  // window 4:3
#define WIN_HEIGHT 750
#define Pi 3.1415


GLfloat gSecTheta = 0, gMinTheta = 0, gHrTheta = 0;

void MyDisplay();
void MyReshape(int newWidth, int newHeight);
void MyTimer(int value);


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Clock");
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    glutReshapeFunc(MyReshape);
    glutDisplayFunc(MyDisplay);
    glutTimerFunc(20, MyTimer, 1);
    
    glutMainLoop();
    return 0;
}



void MyDisplay() {
    GLfloat Size[2], Angle;
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    /*************** CLOCK 1 ***************/
    glPushMatrix();
    glColor3f(136.0/255, 80.0/255, 83.0/255);    // 갈색
    glLineWidth(20.0);
    glGetFloatv(GL_POINT_SIZE_RANGE, Size);
    glPointSize(Size[0] * 10);
    glPushMatrix();
    glTranslatef(3.0, 2.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (Angle = 0.0; Angle <= 2*Pi; Angle += Pi/180.0) {
        glVertex3f(0.7*cos(Angle), 0.7*sin(Angle), 0.0);
    }
    glEnd();
    glPopMatrix();
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);    // 우측 상단 시계 중심좌표 (3.0, 2.0, 0.0)
    glVertex3f(3.0, 2.0+0.05, 0.0);
    glVertex3f(3.0-0.05, 2-0.05, 0.0);
    glVertex3f(3.0+0.05, 2.0-0.05, 0.0);
    glEnd();
    
    // 시침
    glColor3f(254.0/255, 95.0/255, 85.0/255);   // orange red
    glLineWidth(5);
    glTranslatef(3.0, 2.0, 0.0);
    glRotatef(gMinTheta, 0.0, 0.0, 1.0);
    glTranslatef(-3.0, -2.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(3.0, 2.0, 0.0);
    glVertex3f(3.0, 2.3, 0.0);
    glEnd();
    glPopMatrix();
    
    // 분침
    glColor3f(119.0/255, 125.0/255, 167.0/255);   // rhythm
    glLineWidth(3);
    glPushMatrix();
    glTranslatef(3.0, 2.0, 0.0);
    glRotatef(gMinTheta, 0.0, 0.0, 1.0);
    glTranslatef(-3.0, -2.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(3.0, 2.0, 0.0);
    glVertex3f(3.0, 2.5, 0.0);
    glEnd();
    glPopMatrix();
    
    // 초침
    glColor3f(148.0/255, 201.0/255, 169.0/255);   // eton blue
    glLineWidth(2);
    glPushMatrix();
    glTranslatef(3.0, 2.0, 0.0);
    glRotatef(gSecTheta, 0.0, 0.0, 1.0);
    glTranslatef(-3.0, -2.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(3.0, 2.0, 0.0);
    glVertex3f(3.0, 2.4, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
    
    /*************** CLOCK 2 ***************/
    glPushMatrix();
    glColor3f(221.0/255, 196.0/255, 221.0/255);    // 시계판
    glBegin(GL_POLYGON);
    glVertex3f(-3.6, 1.3, 0.0);
    glVertex3f(-2.2, 1.3, 0.0);
    glVertex3f(-2.2, 2.7, 0.0);
    glVertex3f(-3.6, 2.7, 0.0);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);    // 테두리
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-3.6, 1.3, 0.0);
    glVertex3f(-2.2, 1.3, 0.0);
    glVertex3f(-2.2, 2.7, 0.0);
    glVertex3f(-3.6, 2.7, 0.0);
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);    // 좌측 상단 시계 중심좌표 (-2.9, 2.0, 0.0)
    glVertex3f(-2.9, 2.0+0.05, 0.0);
    glVertex3f(-2.9-0.05, 2-0.05, 0.0);
    glVertex3f(-2.9+0.05, 2.0-0.05, 0.0);
    glEnd();
    
    // 시침
    glColor3f(169.0/255, 151.0/255, 223.0/255);
    glLineWidth(10);
    glTranslatef(-2.9, 2.0, 0.0);
    glRotatef(gMinTheta, 0.0, 0.0, 1.0);
    glTranslatef(2.9, -2.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-2.9, 2.0, 0.0);
    glVertex3f(-2.9, 2.4, 0.0);
    glEnd();
    glPopMatrix();
    
    // 분침
    glColor3f(79.0/255, 81.0/255, 125.0/255);
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(-2.9, 2.0, 0.0);
    glRotatef(gMinTheta, 0.0, 0.0, 1.0);
    glTranslatef(2.9, -2.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-2.9, 2.0, 0.0);
    glVertex3f(-2.9, 2.6, 0.0);
    glEnd();
    glPopMatrix();
    
    // 초침
    glColor3f(26.0/255, 58.0/255, 58.0/255);
    glLineWidth(4);
    glPushMatrix();
    glTranslatef(-2.9, 2.0, 0.0);
    glRotatef(gSecTheta, 0.0, 0.0, 1.0);
    glTranslatef(2.9, -2.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-2.9, 2.0, 0.0);
    glVertex3f(-2.9, 2.5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
    
    /*************** CLOCK 3 ***************/
    GLUquadricObj *sphere = gluNewQuadric();
    
    glPushMatrix();
    glColor3f(42.0/255, 50.0/255, 75.0/255);
    glTranslatef(0.0, -1.5, 0.0);
    gluSphere(sphere, 1.4, 50, 50);
    gluQuadricDrawStyle(sphere, GLU_FILL);
    glEnd();
    glPopMatrix();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);    // 중앙 하단 시계 중심좌표 (0.0, -1.5, 0.0)
    glVertex3f(0.0-0.07, -1.5+0.07, 0.0);
    glVertex3f(0.0-0.07, -1.5-0.07, 0.0);
    glVertex3f(0.0+0.07, -1.5-0.07, 0.0);
    glVertex3f(0.0+0.07, -1.5+0.07, 0.0);
    glEnd();
    
    // 시침
    glColor3f(118.0/255, 123.0/255, 145.0/255);
    glLineWidth(10);
    glTranslatef(0.0, -1.5, 0.0);
    glRotatef(gMinTheta, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.5, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -1.5, 0.0);
    glVertex3f(0.0, -0.7, 0.0);
    glEnd();
    glPopMatrix();
    
    // 분침
    glColor3f(199.0/255, 204.0/255, 219.0/255);
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(0.0, -1.5, 0.0);
    glRotatef(gMinTheta, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.5, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -1.5, 0.0);
    glVertex3f(0.0, -0.4, 0.0);
    glEnd();
    glPopMatrix();
    
    // 초침
    glColor3f(225.0/255, 229.0/255, 238.0/255);
    glLineWidth(4);
    glPushMatrix();
    glTranslatef(0.0, -1.5, 0.0);
    glRotatef(gSecTheta, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.5, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -1.5, 0.0);
    glVertex3f(0.0, -0.5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
    glutSwapBuffers();
}


void MyReshape(int newWidth, int newHeight) {
    glViewport(0, 0, newWidth, newHeight);
    GLfloat widthFactor = (GLfloat)newWidth / (GLfloat)WIN_WIDTH;
    GLfloat heightFactor = (GLfloat)newHeight / (GLfloat)WIN_HEIGHT;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0 * widthFactor, 4.0 * widthFactor, -3.0 * heightFactor, 3.0 * heightFactor, -4.0, 4.0);
}


void MyTimer(int value) {
    gSecTheta -= 360/60;    // 초침, 시계방향
    gMinTheta -= (GLfloat)(360/60)/60;
    gHrTheta -= 30.0/3600;
    
    glutPostRedisplay();
    glutTimerFunc(1000, MyTimer, 1);
}
