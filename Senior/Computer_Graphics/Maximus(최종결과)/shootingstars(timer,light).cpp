#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>
#include <cstdlib>
#define WIN_WIDTH 1200
#define WIN_HEIGHT 900


GLint gNewWidth, gNewHeight;
GLfloat gWidthFactor, gHeightFactor;
GLboolean gAvailShoot = false;
GLint gStarTimer = 0;

GLfloat gStar_color[ ] = { 1.0, 1.0, 0.0, 1.0 }; // 조명 하의 별 색
const GLfloat gLight_pos[] = { 0.0, 0.0, 0.0, 1.0 };    // 광원 위치

void MyDisplay();
void MakeSignature();
void MakeShootingStars();
void MyStarTimer(int value);
void MyShootingMenu(int entryID);
void MakeMenu();
void MyReshape(int NewWidth, int NewHeight);


void MyDisplay() {
    
    GLint ran_StarX, ran_StarY;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslatef(0, 0, -7); // z축 범위 내로 이동
    glPushMatrix();
        glDisable(GL_LIGHTING);
        glTranslatef(-3.0, 3.0, 0.0);
        glLightfv(GL_LIGHT0, GL_POSITION, gLight_pos);
        glutSolidSphere(0.2, 30, 30);  // 달 그리기
        glEnable(GL_LIGHTING);
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    
    // 랜덤으로 별 생성
    for (int i = 0; i < 60; ++i) {
        ran_StarX = rand() % gNewWidth;
        ran_StarY = rand() % gNewHeight;
        
        std::cout << ran_StarX << ", " << ran_StarY << std::endl;
        
        glPushMatrix();
            gStar_color[0] = (double)rand()/RAND_MAX;   gStar_color[1] = (double)rand()/RAND_MAX;   gStar_color[2] = (double)rand()/RAND_MAX;
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gStar_color);    // 조명 하의 얼굴색 넣는 함수
            glTranslatef((double)ran_StarX/gNewWidth * 8*gWidthFactor - 4*gWidthFactor, (double)ran_StarY/gNewHeight * 6*gHeightFactor - 3*gHeightFactor, 0);
            glShadeModel(GL_SMOOTH);
            glutSolidCube(0.05);
        glPopMatrix();
    }

    // My Signature (alphabet s)
    gStar_color[0] = 1.0;   gStar_color[1] = 1.0;   gStar_color[2] = 0.0;
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gStar_color);    // 조명 하의 얼굴색 넣는 함수
    MakeSignature();
    
    // Shooting Stars
    if (gAvailShoot) {
        MakeShootingStars();
    }
    
    glutSwapBuffers();
    
} // MyDisplay




int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Shooting stars");
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    MakeMenu();
    
    glutMainLoop();
    return 0;
}





void MyReshape(int NewWidth, int NewHeight) {
    
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / WIN_WIDTH;
    GLfloat HeightFactor = (GLfloat)NewHeight / WIN_HEIGHT;
    
    gWidthFactor = WidthFactor;
    gHeightFactor = HeightFactor;
    gNewWidth = NewWidth;
    gNewHeight = NewHeight;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-4 * WidthFactor, 4 * WidthFactor, -3 * HeightFactor, 3 * HeightFactor, -4, 4);
    gluPerspective(60, (GLsizei)NewWidth / (GLsizei)NewHeight, 1, 9);
} // MyReshape



void MakeSignature() {
    glPushMatrix();
        glTranslatef(1.0, 0.8, 0.0);
        glutSolidSphere(0.04, 20, 20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 1.5, 0.0);
        glutSolidSphere(0.04, 20, 20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.0, 1.0, 0.0);
        glutSolidSphere(0.04, 20, 20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.0, 0.5, 0.0);
        glutSolidSphere(0.04, 20, 20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        glutSolidSphere(0.04, 20, 20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.0, -0.5, 0.0);
        glutSolidSphere(0.04, 20, 20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.0, -1.0, 0.0);
        glutSolidSphere(0.04, 20, 20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, -1.5, 0.0);
        glutSolidSphere(0.04, 20, 20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.0, -0.8, 0.0);
        glutSolidSphere(0.04, 20, 20);
    glPopMatrix();
}



void MyStarTimer(int value) {
    if (!gAvailShoot)   return;
    
    gStarTimer = (gStarTimer + 1) % 100;
    
    glutPostRedisplay();
    glutTimerFunc(700 , MyStarTimer, 1);
}



void MyShootingMenu(int entryID) {
    if (entryID == 1) {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        gAvailShoot = true;
        glutTimerFunc(700, MyStarTimer, 1);
    }else if (entryID == 2) {
        glClearColor(0.2, 0.2, 0.2, 1.0);
        gAvailShoot = false;
    }
    glutPostRedisplay();
}


void MakeShootingStars() {
    glColor3f(1.0, 1.0, 1.0);   // 흰 색 별똥별
    glLineWidth(1.0);
    
    if (gStarTimer % 5 == 1) {
        glBegin(GL_LINES);
            glVertex3f(1.0, 2.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
            glVertex3f(0.0, -2.0, 0.0); glVertex3f(-1.0, -3.0, 0.0);
        glEnd();
    }else if (gStarTimer % 5 == 2) {
        glBegin(GL_LINES);
            glVertex3f(-1.0, 3.0, 0.0); glVertex3f(-4.0, 0.0, 0.0);
            glVertex3f(2.7, -1.0, 0.0); glVertex3f(0.0, -3.7, 0.0);
        glEnd();
    }else if (gStarTimer % 5 == 3) {
        glBegin(GL_LINES);
            glVertex3f(-0.5, 1.0, 0.0); glVertex3f(-3.5, -2.0, 0.0);
            glVertex3f(1.7, -0.3, 0.0); glVertex3f(-0.3, -2.3, 0.0);
        glEnd();
    }else if (gStarTimer % 5 == 4) {
        glBegin(GL_LINES);
            glVertex3f(3.0, 3.0, 0.0); glVertex3f(-2.0, -2.0, 0.0);
            glVertex3f(1.8, -1.6, 0.0); glVertex3f(-2.2, -4.4, 0.0);
        glEnd();
    }else {
        glBegin(GL_LINES);
        glVertex3f(3.0, 1.0, 0.0); glVertex3f(0.0, -2.0, 0.0);
        glVertex3f(0.6, 0.3, 0.0); glVertex3f(-4.4, -4.7, 0.0);
        glEnd();
    }
}


void MakeMenu() {
    glutCreateMenu(MyShootingMenu);
    glutAddMenuEntry("✨Shooting Stars✨", 1);
    glutAddMenuEntry("🔧Clear🔧", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
