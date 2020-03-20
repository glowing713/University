#ifndef monster_h
#define monster_h

#include <iostream>
#include <stdlib.h>
using namespace std;

class Monster{
private:
    double hp, attack, defense, x, y;
public:
    Monster();
    void setHP(Monster &m);
    void setAttack(double a);   // 랜덤함수 사용 가능
    void setDefense();  // hp + attack
    void getMonsterInfo();  // 몬스터 정보 출력
    double HP();    // 몬스터의 HP 반환
    double Attack();  // 몬스터가 가진 공격력 반환
    void Spawn();   // 몬스터 인스턴스의 현재 값을 모두 리셋하고 위치도 바꾸는 함수. 이 함수는 Hp, Attack, Defence, x, y를 모두 랜덤으로 처리할 것
    ~Monster();
};

// hp 설정(공격받은 몬스터의 공격력을 차감)
void Monster::setHP(Monster &m){
    hp -= m.Attack();
}

// 공격력 설정
void Monster::setAttack(double a){
    attack = (rand()%100 + 1) * 0.01f;
}

// 방어력 설정
void Monster::setDefense(){
    defense = hp + attack;
}

// 생성된 몬스터 정보 출력
void Monster::getMonsterInfo(){
    cout << "***몬스터 생성***" << endl;
    cout << "HP: " << hp << endl << "공격력: " << attack << endl << "방어력: " << defense << endl;
    printf("위치: (%.3lf, %.3lf)\n\n", x, y);
}

// 공격력 반환
double Monster::Attack(){
    return attack;
}

// hp 반환
double Monster::HP(){
    return hp;
}

// 몬스터 능력치 랜덤 생성
void Monster::Spawn(){
    hp = (rand()%10000 + 1) * 0.01f;
    attack = (rand()%10000 + 1) * 0.01f;
    defense = (rand()%10000 + 1) * 0.01f;
    x = (rand()%100000 + 1) * 0.001f;
    y = (rand()%100000 + 1) * 0.001f;
    getMonsterInfo();   // 정보 출력
}

Monster::Monster(){
    cout << "기본 생성자 실행" << endl;
}

Monster::~Monster(){
    cout << "소멸자 실행" << endl;
}

#endif /* monster_h */
