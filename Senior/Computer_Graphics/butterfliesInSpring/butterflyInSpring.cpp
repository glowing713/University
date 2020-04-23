/*------------------------------------------
 미완성본입니다.
 수정할 부분은 다음과 같습니다.
 (1) 모델색 지정하는 함수가 안보이는 이유는? glColor3f 안보인다. 왜일까?
 (2) 클릭할 때 MyDisplay함수가 두 번씩 call되는 이유를 말하고,
     한번씩만 call되도록 수정하세요.
 (3) glOrtho함수를 주석처리하였을 때, 똑같은 실행이 되려면 어디를 고쳐야 할까요?
 (4) glClear 빼버리면?
 (5) 누적인데 더블버퍼 사용하면?
 (6) 한 번 클릭할 때, 클릭한 주변에 세 개씩 snow가 생기도록 바뀌보세요.
 (7) 겨울 말고 봄으로 컨셉 전환 (화면 타이틀도 어울리게 수정)
---------------------------------------------*/
#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <stdio.h>
 
int gCount = 0; //마우스 클릭한 개수 (snow 개수)
float gSnowX, gSnowY;



void MyDisplay() {
        
    printf("d \n");
    
    if (gCount == 0) {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    if(gCount > 0) {
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_LINE_LOOP);
            glVertex3f(gSnowX-0.02, gSnowY, 0);
            glVertex3f(gSnowX-0.02, gSnowY-0.04, 0);
            glVertex3f(gSnowX+0.02, gSnowY, 0);
            glVertex3f(gSnowX+0.02, gSnowY-0.04, 0);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glVertex3f(gSnowX-0.06, gSnowY-0.08, 0);
            glVertex3f(gSnowX-0.06, gSnowY-0.12, 0);
            glVertex3f(gSnowX-0.02, gSnowY-0.08, 0);
            glVertex3f(gSnowX-0.02, gSnowY-0.12, 0);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glVertex3f(gSnowX+0.02, gSnowY-0.08, 0);
            glVertex3f(gSnowX+0.02, gSnowY-0.12, 0);
            glVertex3f(gSnowX+0.06, gSnowY-0.08, 0);
            glVertex3f(gSnowX+0.06, gSnowY-0.12, 0);
        glEnd();
        
    }
    
//    glFlush();
    glutSwapBuffers();
}
 


void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    
    if(Button==GLUT_LEFT_BUTTON && State==GLUT_DOWN) {
        
        gSnowX = (2*X/800.0)-1;
        gSnowY = (2*(800-Y)/800.0)-1;
        gCount++;
        printf("count: %d (%d, %d) (%g, %g) \n", gCount, X, Y, gSnowX, gSnowY);
        glutPostRedisplay();
    }
    
 }



void MyInit() {
    glClearColor (0.86, 0.69, 0.74, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}



int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(450, 0);
    glutCreateWindow("봄에는 역시 나비가 날아야..");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick);
    glutMainLoop();
    return 0;
}
