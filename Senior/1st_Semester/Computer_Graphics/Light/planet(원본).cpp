/*#####################################################################################
 (1) 중간 동그라미를 그리는 네 줄이 없으면 어떻게 되나?
     실제 조명과는 연관이 없다.
     동그라미 없어도 조명 효과는 잘 유지된다.
     광원의 위치가 눈에 안보여서 불편해서 서비스 차원에서 추가로 동그라미를 그리는 것.
 (2) 중간 동그라미를 그릴 때 조명을 꺼주지 않으면?
     조명을 끄면 glColor3f 함수가 잘 작동되어서 동그라미가 잘 보임.
     조명을 끄지 않으면, 정확히 광원위치에 있는 동그라미는 눈에 잘 안보임.
 #####################################################################################*/


#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>

int window_width = 640;
int window_height = 480;

const GLfloat red[] = { 0.8f, 0.0, 0.0, 1.0 };
const GLfloat blue[] = { 0.0, 0.2f, 1.0, 1.0 };
const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat polished[] = { 100.0 };
const GLfloat dull[] = { 0.0 };
const GLfloat light_pos[] = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat light_pos1[] = { 0.0, 0.0, 0.0, 1.0 };

GLfloat move_y = 0.0;
GLfloat move_z = 0.0;
GLfloat const_att = 1.0;

void MyDisplay () {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glShadeModel(GL_SMOOTH);

     glTranslatef(0.0, 0.0, -20.0);
    // Light1
     glPushMatrix();
          glTranslatef(-5, 3, 0);
          glTranslatef(0.0, move_y, move_z);
          glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, const_att);
          glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
          glDisable(GL_LIGHTING);
    glColor3d(0.0, 1.0, 1.0);
          glutSolidSphere(0.1, 10, 10);
          glEnable(GL_LIGHTING);
     glPopMatrix();
    // Light2
    glPushMatrix();
         glTranslatef(-1, -4, 0);
         glTranslatef(0.0, move_y, move_z);
         glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, const_att);
         glLightfv(GL_LIGHT1, GL_POSITION, light_pos1);
         glDisable(GL_LIGHTING);
         glColor3d(1, 1, 0);
         glutSolidSphere(0.1, 10, 10);
         glEnable(GL_LIGHTING);
    glPopMatrix();
    

//     glTranslatef(-5.0, 0.0, 0.0);
//     glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
//     glMaterialfv(GL_FRONT, GL_SPECULAR, white);
//     glMaterialfv(GL_FRONT, GL_SHININESS, polished);
//     glutSolidSphere(3.0, 40, 40);

     glTranslatef(5.0, 0.0, 0.0);
     glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
     glMaterialfv(GL_FRONT, GL_SPECULAR, white);
     glMaterialfv(GL_FRONT, GL_SHININESS, polished);
     glutSolidSphere(3.0, 40, 40);

     glutSwapBuffers();
     glFlush();
}

void Mouse_Movement (int x, int y) {
     move_z = (10.0 * x) / window_width;
     move_y = 5.0 - (10.0 * y) / window_height;

     glutPostRedisplay();
}

void MyReshape (int w, int h) {
     window_width = w;
     window_height = h;

     glViewport(0, 0, window_width, window_height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     gluPerspective(35.0, GLfloat(window_width)/GLfloat(window_height), 1.0, 50.0);
     glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
     if (key == GLUT_KEY_LEFT) {
          const_att *= 0.9f;
     } else if(key == GLUT_KEY_RIGHT) {
          const_att /= 0.9f;
     }

     glutPostRedisplay();
}

void MyInit() {
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
     glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    
     glEnable(GL_LIGHT1);
     glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
     glLightfv(GL_LIGHT1, GL_SPECULAR, white);

     glEnable(GL_DEPTH_TEST);
}

int main (int argc, char **argv) {
     glutInit(&argc, argv);
     glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
     glutInitWindowSize(window_width, window_height);
     glutCreateWindow("One Lighting Two Objects");
     MyInit();
     glutDisplayFunc(MyDisplay);
     glutMotionFunc(Mouse_Movement);
     glutReshapeFunc(MyReshape);
     glutSpecialFunc(MySpecial);

     glutMainLoop();
     return 0;
}
