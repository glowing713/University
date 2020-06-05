/*-----------------------------------------------------------
 11th week
 
 (1) 매트를 바닥에 polygon으로 펼쳤는데, glOrtho로 하면 안보이는 이유?
     GL_POLYGON은 두께가 없으므로, 정사투영에서 정면에서 바라보면 아예 안보임. 원근으로 하면 보인다.
 (2) 꽃의 위치를 움직이면 전단할 때, 발끝 고정이 안되는 이유?
     전단 중심 Y값을 절대적인 위치로 두었기 때문에, 움직인 후에는 발끝 고정이 안됨.
     --> 꽃의 상대적인 위치로 전단 위아래 이동함수를 바꿔주면 된다.
 (3) glOrtho일 때, 잘 되던 motion이, 원근 넣으니까 마우스 위치랑 다르게 보이는 이유?
     원근을 넣었으므로 마우스 커서 위치와 z값이 다르기 때문에 미세하게 차이가 발생.
     maximus가 앞으로 올 때, 눈입이 위로 올라가는 것과 같은 이치.
     
 
 Keyboard
 u a s : face
 l k f d : leg 회전
 p o r e : forearm 회전 (-90~90도로 제한)
 P O R E : 전체 팔 회전 (-90~90도로 제한)
 0 9 : 팔 길이 조절
 
 Special
 UP and DOWN : jump
 LEFT and RIGHT : moving X
 F1 - F3, F4 - F6 : body/leg shear
 F9, F10 : moving-Z
 
 Motion
 Menu
 Timer(rain)
 
 -----------------------------------------------------------*/

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>
#define WIN_WIDTH 1000  // window 4:3
#define WIN_HEIGHT 750

unsigned char gFace = 'u';   // u:usual  a:angry   s:smiling
GLfloat gY = 0.0;  // jump
GLfloat gX = 0.0;  // moving-X
GLfloat gZ = 0.0;   // 앞뒤이동
GLfloat gBlueleg = 0.0; // 오른쪽다리 회전각도
GLfloat gBlackleg = 0.0; // 왼쪽다리 회전각도
GLfloat gRedforearm = 0.0, gBlackforearm = 0.0; // 팔꿈치 아래 회전각도
GLfloat gRedupperarm = 0.0, gBlackupperarm = 0.0;   // 팔 전체 회전각도
GLfloat gRedarmlength = 1.0; // 팔 길이 (0으로 초기화하면 시작할 때 팔 길이가 0으로 시작함)
GLfloat gShear = 0.0, gShearLeg = 0.0;
unsigned char gBackground = 'D';
GLint gTimeslot = 0;


GLfloat gPhoneX = -3.0;
GLfloat gPhoneY = -1.3;
GLint gNewWidth, gNewHeight;
GLfloat gWidthFactor, gHeightFactor;
GLint i = 0;

void MyInit();
void YourBackground();
void YourMat();
void YourFace();
void YourEyeMouth();
void YourBody();
void MyiPhone();
void YourUmbrella();
void MyKeyboard(unsigned char key, int x, int y);
void MySpecial(int key, int x, int y);
void MyMotion(GLint X, GLint Y);
void MyMainMenu(int entryID);
void MyTimer(int value);



void MyDisplay() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    gluLookAt(0, 0, 4.3, 0, 0, 0, 0, 1, 0);   // 무대 z값이 -4 ~ 4에서 0.3 ~ 8.3 범위로 변경 => 다른 건 다 원점에 있으므로 안보이고, sphere인 머리만 조금 보임
    
    glTranslatef(0, 0, -5);
    
    YourBackground();
    YourMat();
        
    
    // 여기서부터 막시무스
    glPushMatrix();
    glTranslatef(gX, gY, gZ);   // left, right, jump, 앞뒤 이동
    GLfloat Shear_arr[4][4] = {
        {1, 0, 0, 0},
        {gShear, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };
    
    glTranslatef(0.0, -1.0, 0.0);
    glMultMatrixf((float*)Shear_arr);
    glTranslatef(0.0, 1.0, 0.0);
    YourFace();
    YourEyeMouth();
    YourBody();
    YourUmbrella();
    glPopMatrix();
    // 여기까지 막시무스
    
    
    // 여기서부터 아이폰
    glPushMatrix();
    glTranslatef(0, gPhoneY-1.5, 0.0);
    glMultMatrixf((float*)Shear_arr);
    glTranslatef(0, -gPhoneY+1.5, 0.0);
    MyiPhone();
    glPopMatrix();
    // 여기까지 아이폰
    
    glutSwapBuffers();
    
} // MyDisplay


void YourUmbrella() {
    if (gBackground == 'R') {
        gBlackforearm = -50.0;
        gBlackupperarm = -20.0;
        
        glPushMatrix();
            glColor3f(1.0, 1.0, 1.0);
        
            glTranslatef(-0.7, 1.5, 0);
            glRotatef(-90, 1, 0, 0);
            glScalef(1.3, 0.5, 1);
            glutSolidCone(1.0, 1.0, 12, 12);
        glPopMatrix();
        
        glBegin(GL_LINES);
        glVertex3f(-0.7, 0.3, 0);
        glVertex3f(-0.7, 1.7, 0);
        glEnd();
    }
}



void MyiPhone() {
    glTranslatef(gPhoneX + 2.75, gPhoneY + 1.8, 0); // 커서를 phone의 중심으로
    
    glColor3f(1.0, 1.0, 1.0);
                 
        glBegin(GL_POLYGON);
            glVertex3f(-3.0, -2.3, 0.0);
            glVertex3f(-2.5, -2.3, 0.0);
            glVertex3f(-2.5, -1.3, 0.0);
            glVertex3f(-3.0, -1.3, 0.0);
        glEnd();
        
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_POLYGON);
            glVertex3f(-2.95, -2.25, 0.0);
            glVertex3f(-2.55, -2.25, 0.0);
            glVertex3f(-2.55, -1.35, 0.0);
            glVertex3f(-2.95, -1.35, 0.0);
        glEnd();
        
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
            glVertex3f(-2.85, -1.4, 0.0);
            glVertex3f(-2.65, -1.4, 0.0);
            glVertex3f(-2.65, -1.35, 0.0);
            glVertex3f(-2.85, -1.35, 0.0);
        glEnd();
    
    glPushMatrix(); // 다리 두 개 묶음
        GLfloat Shear_arr[4][4] = {
            {1, 0, 0, 0},
            {gShearLeg, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };
        glTranslatef(-3.0, -2.3, 0.0);
        glMultMatrixf((float*)Shear_arr);
        glTranslatef(3.0, 2.3, 0.0);
    
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(-2.85, -2.3, 0.0);
            glVertex3f(-2.95, -2.8, 0.0);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(-2.65, -2.3, 0.0);
            glVertex3f(-2.55, -2.8, 0.0);
        glEnd();
    
    glPopMatrix();
}


void YourBackground(){
    /*
     파란하늘/푸른초원 z값은 원래 -4.

     무대(gluPerspective)의 z범위는 -1~-9

     그런데 MyDisplay함수에서 모든 등장하는객체들을 전체적으로 z축으로 -5만큼 Ttranslate.

     따라서 파란하늘/푸른초원 z값은 최종 -9 (무대 뒤쪽 경계선에 위치)

     Z버퍼 켠 후 -4대신 -3.9를 넣음으로써 -8.9가 되었고 따라서 경계선에 있다가 무대 안으로 살짝 이동하였습니다.
     */
    
    if (gBackground == 'D')
        glColor3f(0, 1, 1); // sky
    else
        glColor3f(0.2, 0.2, 0.2);   // blackgrey
    
    glBegin(GL_POLYGON);
        glVertex3f(-10, 0, -3.9);
        glVertex3f(10, 0, -3.9);
        glVertex3f(10, 8, -3.9);
        glVertex3f(-10, 8, -3.9);
    glEnd();
    
    if (gBackground == 'D')
        glColor3f(0, 1, 0); // green
    else
        glColor3f(0, 0.3, 0);   // blackgreen
    
    glBegin(GL_POLYGON);
        glVertex3f(-10, -8, -3.9);
        glVertex3f(10, -8, -3.9);
        glVertex3f(10, 0, -3.9);
        glVertex3f(-10, 0, -3.9);
    glEnd();
    
    if (gBackground == 'R') {
        glColor3f(0.9, 0.9, 0.9);   // 비 색
        
        if (gTimeslot % 3 == 0) {
            glBegin(GL_LINES);
                glVertex3f(-3, 2, 0);   glVertex3f(-3, 1.8, 0);
                glVertex3f(3.3, 2.8, 0);    glVertex3f(3.3, 2.6, 0);
            glEnd();
        }else if (gTimeslot % 3 == 1) {
            glBegin(GL_LINES);
                glVertex3f(0, 2.7, 0);  glVertex3f(0, 2.5, 0);
            glEnd();
        }else {
            glBegin(GL_LINES);
                glVertex3f(-1, 1.7, 0); glVertex3f(-1, 1.5, 0);
                glVertex3f(2.9, 1.8, 0);    glVertex3f(2.9, 1.6, 0);
            glEnd();
        }
    }

}

void YourMat() {
    
    if (gBackground == 'D')
        glColor3f(0xE4/255.0, 0xBE/255.0, 0xFE/255.0); // 연보라색
    else
        glColor3f(0.3, 0, 0.3);    // blackpurple
//    glBegin(GL_POLYGON);
//        glVertex3f(-1.5, -1.3, 0);
//        glVertex3f(1.2, -1.3, 0);
//        glVertex3f(1.5, -0.8, 0);
//        glVertex3f(-1.2, -0.8, 0);
//    glEnd();
    glBegin(GL_POLYGON);    // 두께가 없고 면만 있어서 정면에서 보면 안보인다.
        glVertex3f(-1.5, -1, 1.5);  // 바닥에 펼쳐진 정사각형
        glVertex3f(1.5, -1, 1.5);
        glVertex3f(1.5, -1, -1.5);
        glVertex3f(-1.5, -1, -1.5);
    glEnd();
    
} // YourMat


void YourFace(){
    
    if (gBackground == 'D')
        glColor3f(251/255.0, 206/255.0, 177/255.0); // 살구색
    else
        glColor3f(0.6, 0.4, 0.4);
    
    glPushMatrix(); // Push 와 Pop 사이의 기하변환은 이 안에서만 유효하다.
    glTranslatef(0.0, 1.0, 0.0);    // 얼굴 y좌표로 1.0 이동
    glutSolidSphere(0.5, 50, 50);
    glPopMatrix();
    
} // YourFace


void YourEyeMouth() {
    
    glPushMatrix();
//    glTranslatef(0, 0, 0.5);    // 눈코입을 앞으로 당길수록(Z축) "원근이 적용되었기 때문에", 눈코입이 위로 올라가는 듯한 효과가 나타난다.
    
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
    
    glPopMatrix();
    
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
    
    
    glPushMatrix(); // 다리 두 개 묶음
    GLfloat Shear_arr[4][4] = {
        {1, 0, 0, 0},
        {gShearLeg, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    glTranslatef(0.0, -0.3, 0.0);
    glMultMatrixf((float*)Shear_arr);
    glTranslatef(0.0, 0.3, 0.0);
    
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
    
    glPopMatrix();  // 두 다리 끝
    
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
            
        case GLUT_KEY_F1:   gShear = -0.5;  gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48;    break;
        case GLUT_KEY_F2:   gShear = 0.0;  gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0;    break;
        case GLUT_KEY_F3:   gShear = 0.5;  gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48;    break;
            
        case GLUT_KEY_F4:   gShearLeg = 0.5;  gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48;    break;
        case GLUT_KEY_F5:   gShearLeg = 0.0;  gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0;    break;
        case GLUT_KEY_F6:   gShearLeg = -0.5;  gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48;    break;
            
        case GLUT_KEY_F9:  if (gZ <= 3) gZ += 0.1;  break;
        case GLUT_KEY_F10:  if (gZ >= -3) gZ -= 0.1;  break;
    }
    
    glutPostRedisplay();
    
} // MySpecial


void MyMotion(GLint X, GLint Y) {
    gPhoneX = (GLfloat)X / gNewWidth * 8*gWidthFactor - 4*gWidthFactor;  // (5)
    gPhoneY = (GLfloat)(gNewHeight-Y) / gNewHeight * 6*gHeightFactor - 3*gHeightFactor;  // (5)
    glutPostRedisplay();
}



void MyReshape(int NewWidth, int NewHeight) {
    printf("newwidth: %d newheight: %d\n", NewWidth, NewHeight);
    
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / WIN_WIDTH;
    GLfloat HeightFactor = (GLfloat)NewHeight / WIN_HEIGHT;
    
    printf("widthfactor: %lf heightfactor: %lf\n", WidthFactor, HeightFactor);
    
    gWidthFactor = WidthFactor;
    gHeightFactor = HeightFactor;
    gNewWidth = NewWidth;
    gNewHeight = NewHeight;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-4 * WidthFactor, 4 * WidthFactor, -3 * HeightFactor, 3 * HeightFactor, 1, 9);
    gluPerspective(65, (GLfloat)NewWidth/(GLfloat)NewHeight, 1, 9); // 원근 투영 z: -1 ~ -9
} // MyReshape

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
//    glEnable(GL_DEPTH_TEST);    // 깊이 추가(Z), 이걸 추가해야 z-buffer가 적용된다.
    
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddMenuEntry("Day", 1);
    glutAddMenuEntry("Night", 2);
    glutAddMenuEntry("Rain", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MyMainMenu(int entryID) {
    if (entryID == 1) {
        glClearColor(1, 1, 1, 1);   gBackground = 'D';
    }else if (entryID == 2) {
        glClearColor(0, 0, 0, 0);   gBackground = 'N';
    }else if (entryID == 3) {
        glClearColor(0, 0, 0, 0);   gBackground = 'R';  glutTimerFunc(400, MyTimer, 1);
    }
    glutPostRedisplay();
}

void MyTimer(int value) {
    if (gBackground == 'R') {
        gTimeslot = (gTimeslot + 1) % 100;  // 0~99 반복
        
        glutPostRedisplay();
        glutTimerFunc(400, MyTimer, 1); // 중간에 메뉴가 day나 night로 바뀌면 타이머 종료
    }
}



int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(200, 150);
    glutCreateWindow("Maximus");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutMotionFunc(MyMotion);
    glutKeyboardFunc(MyKeyboard);
    glutSpecialFunc(MySpecial);
    
    glutMainLoop();
    return 0;
}

