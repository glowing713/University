#ifndef calc_h
#define calc_h

#include "operator.h"

class Display{
public:
    void inputType(){
        cout << "::계산 타입을 선택하세요::\n1. 정수 계산\t2. 실수 계산\n입력: ";
    }
    void inputMes(){
        cout << "계산식을 입력하세요(+,-,*,/ 지원): ";
    }
    void resultMes(){
        cout << "결과: ";
    }
};

class NumPad : public Display, public Add, public Sub, public Mul, public Div{
protected:
    int type;
    int ia, ib;
    double da, db;
    char oper;
public:
    void formula();
    void calculate();
};

// 맨 처음 실행하는 화면(식을 입력받는다.)
void NumPad::formula(){
    inputType();  // 입력할 수가 정수인지 실수인지
    cin >> type;
    inputMes(); // 입력할 때 메시지
    
    if(type == 1){
        cin >> ia >> oper >> ib;
    }else if(type == 2){
        cin >> da >> oper >> db;
    }else{
        cout << "계산 타입은 정수(1)나 실수(2)만 가능합니다!!" << endl;
    }
}

void NumPad::calculate(){
    resultMes(); // 계산결과 출력 메시지
    
    switch (oper) {
        case '+' :
        if(type == 1) cout << addOper(ia, ib) << endl; else cout << addOper(da, db) << endl;
        break;
        
        case '-' :
        if(type == 1) cout << subOper(ia, ib) << endl; else cout << subOper(da, db) << endl;
        break;

        case '*' :
        if(type == 1) cout << mulOper(ia, ib) << endl; else cout << mulOper(da, db) << endl;
        break;

        case '/' :
        if(type == 1) cout << divOper(ia, ib) << endl; else cout << divOper(da, db) << endl;
        break;
        
        default :
        cout << "계산과정 오류 발생!" << endl;
        break;
    }
}

#endif /* calc_h */
