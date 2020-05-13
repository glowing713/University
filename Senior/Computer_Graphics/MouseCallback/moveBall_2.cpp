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

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
GLfloat gX = 0.0, gY = 0.0;
// (5) 전역변수 추가
GLfloat gWidthFactor, gHeightFactor;
GLint gNewWidth, gNewHeight;

void MyDisplay( ) {
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glColor3f (0.9, 0.5, 0.9);
   glTranslatef(gX, gY, 0.0);
   glutSolidSphere(0.5, 100, 100);

   glutSwapBuffers();
   
}

void MyMotion(GLint X, GLint Y) {   // (4) X: 0~8로 만든 다음, -4만큼 이동, Y: 0~6 만든 다음 -3 만큼 이동
    gX = (GLfloat)X / gNewWidth * 8*gWidthFactor - 4*gWidthFactor;  // (5)
    gY = (GLfloat)(gNewHeight-Y) / gNewHeight * 6*gHeightFactor - 3*gHeightFactor;  // (5)
    glutPostRedisplay();
}


void MyReshape(int NewWidth, int NewHeight) {
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / WIN_WIDTH;
    GLfloat HeightFactor = (GLfloat)NewHeight / WIN_HEIGHT;
    // (5)
    gWidthFactor = WidthFactor;
    gHeightFactor = HeightFactor;
    gNewWidth = NewWidth;
    gNewHeight = NewHeight;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4 * WidthFactor, 4 * WidthFactor, -3 * HeightFactor, 3 * HeightFactor, -4, 4);
}


int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);   // 더블버퍼이므로 반드시 작성 (GLUT_RGB는 디폴트)
    
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(200, 150);
    glutCreateWindow("위치 옮기는 보라색 공");
    glClearColor (0.7, 0.9, 0.9, 0.5);

    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutMotionFunc(MyMotion);
    

    glutMainLoop( );
    return 0;
}
