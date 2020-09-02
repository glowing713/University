#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <GLUT/GLUT.h>

static int shoulderL = 10, elbowL = 50;   // 왼팔
static int shoulderR = -10, elbowR = -50;   // 오른팔

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glPushMatrix();     // 머리
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.0, 1.5, 0.0);
        glutWireSphere(1.0, 20, 20);
    glPopMatrix();
    
    
    glPushMatrix();     // 몸통
        glColor3f(237.0/255, 182.0/255, 163.0/255);
        glTranslatef(0.0, -1.5, 0.0);
        glScalef(3.0, 4.0, 1.0);
        glutWireCube(1.0);
    glPopMatrix();
    
    
    glPushMatrix();     // 왼팔
    
        glTranslatef(-1.5, 0.0, 0.0);
        glRotatef((GLfloat)shoulderL, 0.0, 0.0, 1.0);
        glTranslatef(-1.0, 0.0, 0.0);
        glPushMatrix();
            glColor3f(117.0/255, 13.0/255, 55.0/255);
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
        
        glTranslatef(-1.0, 0.0, 0.0);
        glRotatef((GLfloat)elbowL, 0.0, 0.0, 1.0);
        glTranslatef(-1.0, 0.0, 0.0);
        glPushMatrix();
            glColor3f(117.0/255, 13.0/255, 55.0/255);
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
    
    glPopMatrix();
    
    
    glPushMatrix();     // 오른팔
    
    glTranslatef(1.5, 0.0, 0.0);
        glRotatef((GLfloat)shoulderR, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glColor3f(1.0, 1.0, 1.0);
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
        
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat)elbowR, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glColor3f(1.0, 1.0, 1.0);
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0.0, 0.0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-4, 4, -3, 3, 1, 20);
    gluPerspective(100.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'P':
            shoulderR = (shoulderR + 5) % 360;
            break;
        case 'O':
            shoulderR = (shoulderR - 5) % 360;
            break;
        case 'p':
            elbowR = (elbowR + 5) % 360;
            break;
        case 'o':
            elbowR = (elbowR - 5) % 360;
            break;
        case 'R':
            shoulderL = (shoulderL + 5) % 360;
            break;
        case 'E':
            shoulderL = (shoulderL - 5) % 360;
            break;
        case 'r':
            elbowL = (elbowL + 5) % 360;
            break;
        case 'e':
            elbowL = (elbowL - 5) % 360;
            break;
        case 27:    // esc키
            exit(0);    break;
        default:
            break;
    }
    glutPostRedisplay();
}





int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot Arm");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
