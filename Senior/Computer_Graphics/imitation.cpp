#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

/*
(1) 수업자료 1장 11페이지 네모그리기 소스에서 시작
(2) 무대 범위는 x,y,z축 모두 -2~2
(3) GL primitive 사용하지 말 것 (비긴/엔드 사용하지 말라는 의미입니다)
(4) teapot 두 개는 glut 모델링, 중간에 노란 sphere는 glu 모델링으로
(5) 화면에 나오는 teapot/sphere 크기 및 색상도 똑같이 해보세요.
(6) 더블버퍼 사용
(7) 창의 타이틀도 똑같이
 */

GLUquadricObj *sphere = gluNewQuadric();

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.2, 1.0);
    glutSolidTeapot(1.1);
    glColor3f(1.0, 1.0, 0.0);
    gluSphere(sphere, 0.8, 50, 50);
    gluQuadricDrawStyle(sphere, GLU_FILL);
    glColor3f(1.0, 0.2, 0.2);
    glutWireTeapot(0.55);
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("GLU 및 GLUT 사용해보기");
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glOrtho(-2.0, 2.0, -2.0, 2.0, 2.0, -2.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
