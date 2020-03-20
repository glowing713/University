#ifndef operator_h
#define operator_h

#include <iostream>
using namespace std;

class Add{
    public:
    int addOper(int a, int b){return a+b;}
    double addOper(double a, double b){return a+b;}
};

class Sub{
    public:
    int subOper(int a, int b){return a-b;}
    double subOper(double a, double b){return a-b;}
};

class Mul{
    public:
    int mulOper(int a, int b){return a*b;}
    double mulOper(double a, double b){return a*b;}
};

class Div{
    public:
    int divOper(int a, int b){return a/b;}
    double divOper(double a, double b){return a/b;}
};

#endif /* operator_h */
