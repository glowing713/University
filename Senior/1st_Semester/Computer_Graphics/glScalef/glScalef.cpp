/*-----------------------------------------------------------
 
 7th week (2020. 4. 27)
 
 (1) 현재 팔꿈치 아래(forearm)만 움직입니다. 팔 전체 회전 기능을 추가하세요. (P O R E)
 
     전역변수 1줄 추가, YourBody 함수에 10줄 추가, keyBoard 함수에 4줄 추가
 
 (2) 빨간 팔에 늘어나는 기능을 추가하겠습니다.
     '0' (large o 아니고 zero)누르면 점점 길어지고, '9' 누르면 점점 원상복귀하는 코드를 추가하세요.
 
 Keyboard
 u a s : face
 l k f d : leg 회전
 p o r e : lower arm 회전 (-90~90도로 제한)
 
 Special
 UP and DOWN : jump
 LEFT and RIGHT : moving X
 
 -------------------------------------------------------------*/

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>
#define WIN_WIDTH 1000  // window 4:3
#define WIN_HEIGHT 750

unsigned char gFace = 'u';   // u:usual  a:angry   s:smiling
GLfloat gY = 0.0;  // jump
GLfloat gX = 0.0;  // moving-X
GLfloat gBlueleg = 0.0; // 오른쪽다리 회전각도
GLfloat gBlackleg = 0.0; // 왼쪽다리 회전각도
GLfloat gRedforearm = 0.0, gBlackforearm = 0.0; // 팔꿈치 아래 회전각도
GLfloat gRedupperarm = 0.0, gBlackupperarm = 0.0;   // 팔 전체 회전각도
GLfloat gRedarmlength = 1.0; // 팔 길이 (0으로 초기화하면 시작할 때 팔 길이가 0으로 시작함)

void YourBackground();
void YourMat();
void YourFace();
void YourEyeMouth();
void YourBody();
void MyKeyboard(unsigned char key, int x, int y);
void MySpecial(int key, int x, int y);


void MyDisplay() {
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    YourBackground();
    YourMat();
    
    glPushMatrix();
    glTranslatef(gX, gY, 0.0);
    YourFace();
    YourEyeMouth();
    YourBody();
    glPopMatrix();
    
    glutSwapBuffers();
    
} // MyDisplay


void YourBackground(){
    
    glColor3f(0, 1, 1); // sky
    
    glBegin(GL_POLYGON);
    glVertex3f(-4, 0, -4);
    glVertex3f(4, 0, -4);
    glVertex3f(4, 3, -4);
    glVertex3f(-4, 3, -4);
    glEnd();
    
    glColor3f(0, 1, 0); // green
    
    glBegin(GL_POLYGON);
    glVertex3f(-4, -3, -4);
    glVertex3f(4, -3, -4);
    glVertex3f(4, 0, -4);
    glVertex3f(-4, 0, -4);
    glEnd();
    
}

void YourMat() {
    
    glColor3f(0xE4/255.0, 0xBE/255.0, 0xFE/255.0); // 연보라색
    glBegin(GL_POLYGON);
    glVertex3f(-1.5, -1.3, 0);
    glVertex3f(1.2, -1.3, 0);
    glVertex3f(1.5, -0.8, 0);
    glVertex3f(-1.2, -0.8, 0);
    glEnd();
    
} // YourMat


void YourFace(){
    
    glColor3f(251/255.0, 206/255.0, 177/255.0); // 살구색
    
    glPushMatrix(); // Push 와 Pop 사이의 기하변환은 이 안에서만 유효하다.
    glTranslatef(0.0, 1.0, 0.0);    // 얼굴 y좌표로 1.0 이동
    glutSolidSphere(0.5, 50, 50);
    glPopMatrix();
    
} // YourFace


void YourEyeMouth() {
    
    if (gFace=='a') {  // angry
        
        glColor3f(0, 0, 0); // black
        
        glBegin(GL_LINES);
        glVertex3f(-0.3, 1.2, 0.0); // eye
        glVertex3f(-0.1, 1.0, 0.0);
        glVertex3f(0.1, 1.0, 0.0); // eye
        glVertex3f(0.3, 1.2, 0.0);
        glEnd();
        
        glBegin(GL_LINE_LOOP); // mouth
        glVertex3f(-0.1, 0.9, 0.0);
        glVertex3f(0.1, 0.9, 0.0);
        glVertex3f(0.1, 0.8, 0.0);
        glVertex3f(-0.1, 0.8, 0.0);
        glEnd();
    }
    else if (gFace == 's' ) { // smiling
        
        glColor3f(0, 0, 0); // black
        
        glBegin(GL_LINE_STRIP); // eye
        glVertex3f(-0.3, 1.1, 0.0);
        glVertex3f(-0.2, 1.15, 0.0);
        glVertex3f(-0.1, 1.1, 0.0);
        glEnd();
        glBegin(GL_LINE_STRIP);    // eye
        glVertex3f(0.1, 1.1, 0.0);
        glVertex3f(0.2, 1.15, 0.0);
        glVertex3f(0.3, 1.1, 0.0);
        glEnd();
        
        glColor3f(1, 0, 0); // red
        
        glBegin(GL_LINE_LOOP); // mouth
        glVertex3f(-0.1, 0.9, 0.0);
        glVertex3f(0.1, 0.9, 0.0);
        glVertex3f(0, 0.8, 0.0);
        glEnd();
    }
    else if (gFace == 'u' ) { // usual
        
        glColor3f(0, 0, 0); // black
        
        glBegin(GL_LINES);
        glVertex3f(-0.3, 1.1, 0.0); // eye
        glVertex3f(-0.1, 1.1, 0.0);
        glVertex3f(0.1, 1.1, 0.0); // eye
        glVertex3f(0.3, 1.1, 0.0);
        glVertex3f(-0.1, 0.9, 0.0); // mouth
        glVertex3f(0.1, 0.9, 0.0);
        glEnd();
    }
    
} // YourEyeMouth



void YourBody(){
    
    
    glColor3f(0, 0, 0); // black neck
    
    glBegin(GL_LINES);
    glVertex3f(0, 0.5, 0.0);
    glVertex3f(0, 0.3, 0.0);
    glEnd();
    
    
    
    glColor3f(0.5, 0.5, 0.5); // gray spine
    
    glBegin(GL_POLYGON);
    glVertex3f(-0.05, -0.3, 0.0);
    glVertex3f(0.05, -0.3, 0.0);
    glVertex3f(0.05, 0.3, 0.0);
    glVertex3f(-0.05, 0.3, 0.0);
    glEnd();
    
    
    
    glLineWidth(3); // line
    
    glColor3f(1, 0, 0); // red arm
    
    glPushMatrix(); // red arm 전체 시작
    glTranslatef(0.05, 0.3, 0.0);
    glRotatef(gRedupperarm, 0.0, 0.0, 1.0);
    glScalef(gRedarmlength, gRedarmlength, 1.0);
    glTranslatef(-0.05, -0.3, 0.0);
    
        glBegin(GL_LINES); // red upperarm 시작
        glVertex3f(0.05, 0.3, 0.0);
        glVertex3f(0.25, 0.1, 0.0);
        glEnd();    // red upperarm 끝
    
        glPushMatrix(); // red forearm 시작
        glTranslatef(0.25, 0.1, 0.0);
        glRotatef(gRedforearm, 0.0, 0.0, 1.0);
        glTranslatef(-0.25, -0.1, 0.0);
        glBegin(GL_LINES); // lower
        glVertex3f(0.25, 0.1, 0.0);
        glVertex3f(0.5, -0.2, 0.0);
        glEnd();
        glPopMatrix();  // red forearm 끝
    
    glPopMatrix();  // red arm 전체 끝
    
    
    glColor3f(0, 0, 0); // black arm
    
    glPushMatrix(); // black arm 전체 시작
    glTranslatef(-0.05, 0.3, 0.0);
    glRotatef(gBlackupperarm, 0.0, 0.0, 1.0);
    glTranslatef(0.05, -0.3, 0.0);
    
        glBegin(GL_LINES); //upper
        glVertex3f(-0.05, 0.3, 0.0);
        glVertex3f(-0.25, 0.1, 0.0);
        glEnd();
        glPushMatrix();
        glTranslatef(-0.25, 0.1, 0.0);
        glRotatef(gBlackforearm, 0.0, 0.0, 1.0);
        glTranslatef(0.25, -0.1, 0.0);
        glBegin(GL_LINES); //lower
        glVertex3f(-0.25, 0.1, 0.0);
        glVertex3f(-0.5, -0.2, 0.0);
        glEnd();
        glPopMatrix();
    
    glPopMatrix();  // black arm 전체 끝
    
    
    
    glColor3f(0, 0, 1); // blue leg
    
    glPushMatrix();
    // 그냥 회전만 시키면 다리가 원점을 중심으로 회전하므로 몸에서 분리됨.
    glTranslatef(0.05, -0.3, 0.0);  // (3) 다리를 원상복귀 ==> 복합변환
    glRotatef(gBlueleg, 0.0, 0.0, 1.0); // (2) 회전
    glTranslatef(-0.05, 0.3 , 0.0);  // (1) 다리가 원점에서 시작하도록 이동(원점에서 시작하면 원점과 다리 사이에 공간이 없게 회전한다)
    glBegin(GL_LINES);
    glVertex3f(0.05, -0.3, 0.0);
    glVertex3f(0.3, -1.0, 0.0);
    glEnd();
    glPopMatrix();
    
    
    glColor3f(0, 0, 0); // black leg
    
    glPushMatrix();
    glTranslatef(-0.05, -0.3, 0.0);
    glRotatef(gBlackleg, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.3, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-0.05, -0.3, 0.0);
    glVertex3f(-0.3, -1.0, 0.0);
    glEnd();
    glPopMatrix();
    
    glLineWidth(1);  // line
    
} // YourBody



void MyKeyboard(unsigned char key, int x, int y) {
    
    switch (key) {
            
        case 'Q':
        case 'q':    exit(0);  break;
            
        case 'a':
        case 's':
        case 'u':   gFace = key;   break;     // face
            
        case 'l':   gBlueleg += 10; break;
        case 'k':   gBlueleg -= 10; break;
            
        case 'f':   gBlackleg += 10; break;
        case 'd':   gBlackleg -= 10; break;
            
        case 'p':   if (gRedforearm < 90) gRedforearm += 8; break;
        case 'o':   if (gRedforearm > -90) gRedforearm -= 8; break;
            
        case 'r':   if (gBlackforearm < 90) gBlackforearm += 8; break;
        case 'e':   if (gBlackforearm > -90) gBlackforearm -= 8; break;
            
        case 'P':   if (gRedupperarm < 90) gRedupperarm += 8; break;
        case 'O':   if (gRedupperarm > -90) gRedupperarm -= 8; break;
            
        case 'R':   if (gBlackupperarm < 90) gBlackupperarm += 8; break;
        case 'E':   if (gBlackupperarm > -90) gBlackupperarm -= 8; break;
            
        case '0':   gRedarmlength *= 1.1;   break;
        case '9':   if (gRedarmlength > 1)  gRedarmlength /= 1.1;   break;
    }
    
    glutPostRedisplay();
    
} // MyKeyboard

void MySpecial(int key, int x, int y) {
    
    switch (key) {
            
        case GLUT_KEY_UP:   gY = 1; gFace = 's';
            gRedforearm = 30; gBlackforearm = -30; gBlueleg = -19.5; gBlackleg = 19.5;
            break;
            
        case GLUT_KEY_DOWN:   gY = 0;   gFace = 'u';
            gRedforearm = 0; gBlackforearm = 0; gBlueleg = 0; gBlackleg = 0;
            break;
            
        case GLUT_KEY_LEFT:
            if (gY == 0) {
                gX -= 0.1;
                if (gX < -1.5 || gX > 0.5)  gFace = 'a';
                else    gFace = 'u';
            }
            break;
        case GLUT_KEY_RIGHT:
            if (gY == 0) {
                gX += 0.1;
                if (gX < -1.5 || gX > 0.5)   gFace = 'a';
                else    gFace = 'u';
            }
            break;
    }
    
    glutPostRedisplay();
    
} // MySpecial



void MyReshape(int NewWidth, int NewHeight) {
    
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)WIN_WIDTH;
    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)WIN_HEIGHT;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0 * WidthFactor, 4.0 * WidthFactor, -3.0 * HeightFactor, 3.0 * HeightFactor, -4.0, 4.0);
    
} // MyReshape


void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    // menu callback
    
} // MyInit


int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(150, 0);
    glutCreateWindow("Maximus");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutSpecialFunc(MySpecial);
    
    glutMainLoop();
    return 0;
}

