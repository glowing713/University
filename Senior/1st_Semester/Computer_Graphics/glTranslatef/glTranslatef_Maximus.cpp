/*-----------------------------------------------------------
 6th week (2020. 4. 20)
 
 1) 회전시키려면 어떤 기하변환 함수가 필요할까?
 ==> glRotatef(각도, 3차원벡터) -> glRotatef(30, 0, 0, 1) : z축을 기준으로 반시계 방향으로 30도 회전
 2) 막시무스의 다리는 어느 축을 기준으로 회전하고 있었나?
 ==> z축 기준(평면에서 회전함)
 3) blue leg만 회전시키고 다른 부분에 영향을 안주려면 어떤 함수를 호출해야 하나?
 ==> glPushMatrix(), glPopMatrix()
 4) 회전시키니까 다리가 몸체에서 분리된다. 이유가 무엇인가?
 ==> 원점을 기준으로 회전하기 떄문에, 다리가 원점이 아닌 다른 지점에서 돌고 싶어도, 원점 기준으로 크게 돈다.
 5) 정확히 고관절을 중심으로 회전하려면 어떻게 하면 될까?
 ==> (움직임의 순서) 1.다리를 원점으로 이동, 2.회전, 3.원상복귀
 (코딩 순서) push, 3. 원상복귀, 2. 회전, 1. 다리를 원점으로 이동, 다리(begin-end), pop
 
 
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
GLfloat gRedarm = 0.0, gBlackarm = 0.0;

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
    
    
    glBegin(GL_LINES); // upper
    glVertex3f(0.05, 0.3, 0.0);
    glVertex3f(0.25, 0.1, 0.0);
    glEnd();
    
    glPushMatrix();
    glTranslatef(0.25, 0.1, 0.0);
    glRotatef(gRedarm, 0.0, 0.0, 1.0);
    glTranslatef(-0.25, -0.1, 0.0);
    glBegin(GL_LINES); // lower
    glVertex3f(0.25, 0.1, 0.0);
    glVertex3f(0.5, -0.2, 0.0);
    glEnd();
    glPopMatrix();
    
    
    glColor3f(0, 0, 0); // black arm
    
    glBegin(GL_LINES); //upper
    glVertex3f(-0.05, 0.3, 0.0);
    glVertex3f(-0.25, 0.1, 0.0);
    glEnd();
    glPushMatrix();
    glTranslatef(-0.25, 0.1, 0.0);
    glRotatef(gBlackarm, 0.0, 0.0, 1.0);
    glTranslatef(0.25, -0.1, 0.0);
    glBegin(GL_LINES); //lower
    glVertex3f(-0.25, 0.1, 0.0);
    glVertex3f(-0.5, -0.2, 0.0);
    glEnd();
    glPopMatrix();
    
    
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
            
        case 'p':   if (gRedarm < 90) gRedarm += 8; break;
        case 'o':   if (gRedarm > -90) gRedarm -= 8; break;
            
        case 'r':   if (gBlackarm < 90) gBlackarm += 8; break;
        case 'e':   if (gBlackarm > -90) gBlackarm -= 8; break;
            
            
    }
    
    glutPostRedisplay();
    
} // MyKeyboard

void MySpecial(int key, int x, int y) {
    
    switch (key) {
            
        case GLUT_KEY_UP:   gY = 1; gFace = 's';
            gRedarm = 30; gBlackarm = -30; gBlueleg = -19.5; gBlackleg = 19.5;
            break;
            
        case GLUT_KEY_DOWN:   gY = 0;   gFace = 'u';
            gRedarm = 0; gBlackarm = 0; gBlueleg = 0; gBlackleg = 0;
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

