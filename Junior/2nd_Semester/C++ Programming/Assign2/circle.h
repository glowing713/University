#ifndef circle_h
#define circle_h
#include <iostream>

using namespace std;

class Circle{
private:
    float radius, x, y;
public:
    Circle();
    Circle(float r);
    Circle(float x, float y);
    Circle(float r, float x, float y);
    ~Circle();
    void setRadius(float r);
    void getRadius();
    void setCenterPoint(float x, float y);
    void getCenterPoint();
};

Circle::Circle(){
    radius = 0;
    x = 0;
    y = 0;
    cout << "매개변수 없는 생성자 실행" << endl;
}

Circle::Circle(float r){
    radius = r;
    cout << "매개변수 하나인 생성자 실행(반지름 초기화)" << endl;
}

Circle::Circle(float x, float y){
    this->x = x;
    this->y = y;
    cout << "매개변수 두개인 생성자 실행(중점 x, y좌표 초기화)" << endl;
}

Circle::Circle(float r, float x, float y){
    radius = r;
    this->x = x;
    this->y = y;
    cout << "매개변수 세개인 생성자 실행(반지름, 중점 x, y좌표 초기화)" << endl;
}

void Circle::setRadius(float r){
    radius = r;
    cout << "멤버함수로 반지름 초기화" << endl;
}

void Circle::getRadius(){
    cout << "반지름의 길이: " << radius << endl;
}

void Circle::setCenterPoint(float x, float y){
    this->x = x;
    this->y = y;
    cout << "멤버함수로 중점좌표 초기화" << endl;
}

void Circle::getCenterPoint(){
    cout << "중점 좌표: (" << x << ", " << y << ")" << endl;
}

Circle::~Circle(){
    cout << "소멸자 실행" << endl;
}

#endif /* circle_h */
