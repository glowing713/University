#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>



//GLboolean IsSphere = true;
GLchar gWhat = 's';
GLboolean gSmall = true;
GLboolean gIsWire = true;


void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.5, 0.5);
    if (gWhat == 's' && gSmall == true) {
        if (gIsWire == true)
            glutWireSphere(0.5, 30, 30);
        else
            glutSolidSphere(0.5, 30, 30);
    }else if (gWhat == 's' && gSmall == false) {
        if (gIsWire == true)
            glutWireSphere(0.7, 30, 30);
        else
            glutSolidSphere(0.7, 30, 30);
    }else if (gWhat == 't' && gSmall == true) {
        if (gIsWire == true)
            glutWireTorus(0.1, 0.3, 40, 20);
        else
            glutSolidTorus(0.1, 0.3, 40, 20);
    }else if (gWhat == 't' && gSmall == false) {
        if (gIsWire == true)
            glutWireTorus(0.2, 0.5, 40, 20);
        else
            glutSolidTorus(0.2, 0.5, 40, 20);
    }else if (gWhat == 'p' && gSmall == true) {
        if (gIsWire == true)
            glutWireTeapot(0.5);
        else
            glutSolidTeapot(0.5);
    }else if (gWhat == 'p' && gSmall == false) {
        if (gIsWire == true)
            glutWireTeapot(0.7);
        else
            glutSolidTeapot(0.7);
    }
    glFlush();
}


void MyMainMenu(int entryID) {
    if (entryID == 1)
        gWhat = 's';
    else if(entryID == 2)
        gWhat = 't';
    else if(entryID == 3)
        gWhat = 'p';
    else if(entryID == 4)
        exit(0);
    glutPostRedisplay();
}

void MySizeMenu(int entryID) {
    if (entryID == 1)    gSmall = true;
    else if (entryID == 2)  gSmall = false;
    glutPostRedisplay();
}

void MyStyleMenu(int entryID) {
    if (entryID == 1)   gIsWire = true;
    else if (entryID == 2)  gIsWire = false;
    glutPostRedisplay();
}


void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    
    GLint MySizeID = glutCreateMenu(MySizeMenu);
    glutAddMenuEntry("Small", 1);
    glutAddMenuEntry("Large", 2);
    
    GLint MyStyleID = glutCreateMenu(MyStyleMenu);
    glutAddMenuEntry("Wire", 1);
    glutAddMenuEntry("Solid", 2);
    
    glutCreateMenu(MyMainMenu);
    glutAddMenuEntry("Draw Sphere", 1);
    glutAddMenuEntry("Draw Torus", 2);
    glutAddMenuEntry("Draw Teapot", 3);
    glutAddSubMenu("Size", MySizeID);
    glutAddSubMenu("Style", MyStyleID);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Menu Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
