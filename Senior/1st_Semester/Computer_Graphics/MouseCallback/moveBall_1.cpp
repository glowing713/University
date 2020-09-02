/*------------------------------------------------
위치 옮기는 보라색 공
 
(1) 여기코딩 1~5를 완성하세요.
(2) 화면 크기가 바뀌어도 공 모양이 넙적/홀쭉해지지 않도록 glOrtho 수정하세요~
(3) 2장 reshape할 때 화면크기 옆으로 늘려도 회색네모는 정중앙에 위치하는데
    보라색공은 화면크기 옆으로 늘려도 위치변경 안하는 이유를 두 줄 정도로 서술하세요.
(4) glOrtho 무대크기를 Maximus의 무대크기와 동일하게 만드세요.( -4 ~ 4, -3 ~ 3, -4 ~ 4)
    물론 보라색 공은 여전히 마우스모션에 따라 위치를 잘 바꿔야 함!
(5) 화면 크기가 바뀌어도 보라색 공이 위치를 잘 바꾸게 하려면 어디를 고쳐야 하는가?

---------------------------------------------------*/

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

#define WIN_WIDTH 500
#define WIN_HEIGHT 500
GLfloat gX = 0.5, gY = 0.5; // 여기 코딩(1): 전역변수 선언

void MyDisplay( ) {
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glColor3f (0.9, 0.5, 0.9);
   glTranslatef(gX, gY, 0.0);   // 여기 코딩(2): 한 줄
   glutSolidSphere(0.1, 100, 100);

   glutSwapBuffers();
   
}

//
//여기 코딩(3): 콜백함수 작성
//
void MyMotion(GLint X, GLint Y) {   // 픽셀 단위이므로 정수 (가운데는 250, 250), 마우스는 Z값 없음
    gX = (GLfloat)X / WIN_WIDTH;
    gY = (GLfloat)(WIN_HEIGHT-Y) / WIN_HEIGHT;  // 스크린에서 점의 위치는 반전
    glutPostRedisplay();
}


void MyReshape(int NewWidth, int NewHeight) {
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / WIN_WIDTH;
    GLfloat HeightFactor = (GLfloat)NewHeight / WIN_HEIGHT;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1 * WidthFactor, 0, 1 * HeightFactor, -1, 1);    // 화면 늘어나도 모델을 보존하기 위해 factor 곱
    // 2장 reshape 예제에서는 -1 ~ 1 ==> -3 ~ 3 바뀌어도 원점은 그대로 정중앙
    // 따라서 모양도 변하지 않고 위치도 항상 정중앙
    // 이 프로그램에서는 0 ~ 1 ==> 0 ~ 2 가 되면
    // 0.5 위치에 있던 공은 화면의 중간에서 화면의 1/4 지점위치가 됨. 따라서 그대로 있게 된다.
}


int main(int argc, char** argv) {
    glutInit(&argc,argv);
    // 여기 코딩(4):  한 줄
    glutInitDisplayMode(GLUT_DOUBLE);   // 더블버퍼이므로 반드시 작성 (GLUT_RGB는 디폴트)
    
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(200, 150);
    glutCreateWindow("위치 옮기는 보라색 공");
    glClearColor (0.7, 0.9, 0.9, 0.5);

    // 여기 코딩(5): 콜백함수 세 개 호출
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutMotionFunc(MyMotion);
    

    glutMainLoop( );
    return 0;
}
