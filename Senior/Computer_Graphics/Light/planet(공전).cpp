/*#####################################################################################
 - x축 기준 회전
 - gluPerspective의 각도 60도로 변경
 - 타이머 함수
 #####################################################################################*/


#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>

int window_width = 1200;
int window_height = 900;

const GLfloat red[] = { 0.8f, 0.0, 0.0, 1.0 };
const GLfloat blue[] = { 0.0, 0.2f, 1.0, 1.0 };
const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat polished[] = { 100.0 };
const GLfloat dull[] = { 0.0 };
const GLfloat light_pos[] = { 0.0, 0.0, 0.0, 1.0 };

GLfloat const_att = 1.0;
GLint gRadius = 0;

void MyDisplay () {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glShadeModel(GL_SMOOTH);
    
    glTranslatef(0.0, 0.0, -20.0);
    
    glPushMatrix();
        glTranslatef(5, 0, 0);
        glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, const_att);
        glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
        glDisable(GL_LIGHTING);
        glColor3d(1, 1, 0);
        glutSolidSphere(0.1, 10, 10);
        glEnable(GL_LIGHTING);
    glPopMatrix();
    
    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glutSolidSphere(2, 40, 40);
    
    glPushMatrix();
        glRotatef(gRadius, 1, 0, 0);
        glTranslatef(0.0, 8.0, 0.0);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
        glMaterialfv(GL_FRONT, GL_SPECULAR, white);
        glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glutSolidSphere(0.8, 40, 40);
    glPopMatrix();
    
    glutSwapBuffers();
    glFlush();
}


void MyReshape (int w, int h) {
    window_width = w;
    window_height = h;
    
    glViewport(0, 0, window_width, window_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(60.0, GLfloat(window_width)/GLfloat(window_height), 1.0, 50.0);
    glutPostRedisplay();
}


void MyInit() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    
    glEnable(GL_DEPTH_TEST);
}

void MyCycle(int value) {
    gRadius += 1;
    std::cout << gRadius << std::endl;
    glutPostRedisplay();
    glutTimerFunc(20, MyCycle, 1);
}

int main (int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("One Lighting Two Objects");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutTimerFunc(20, MyCycle, 1);
    
    glutMainLoop();
    return 0;
}
