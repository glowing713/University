#ifndef point_h
#define point_h
#include <iostream>

using namespace std;

class Point{
private:
    float x, y, z;
public:
    Point();
    Point(float x, float y, float z);
    void setPos(float x, float y, float z);
    void getPos();
};

Point::Point(){
    x = 0.0;
    y = 0.0;
    z = 0.0;
    cout << "기본 생성자 실행(x = 0, y = 0, z = 0)" << endl;
}

Point::Point(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
    cout << "생성자 실행(x = " << x << ", y = " << y << ", z = " << z << ")" << endl;
}

void Point::setPos(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
    cout << "멤버함수 실행(x = " << x << ", y = " << y << ", z = " << z << ")" << endl;
}

void Point::getPos(){
    cout << "x좌표: " << x << endl << "y좌표: " << y << endl << "z좌표: " << z << endl;
}

#endif /* point_h */
