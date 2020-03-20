#include "monster.h"

int main(){
    int n = 0, monnum = 0;;
    cout << "생성하려는 몬스터의 개체 수를 입력하세요(5 이상): ";
    cin >> n;
    monnum = n;
    Monster *monster = new Monster[n];
    
    // 입력한 수만큼 몬스터 생성
    for(int i = 0; i < n; ++i){
        monster[i].Spawn();
    }
    
    for(int i = 0; i < n; ++i){
        double damage = monster[i].Attack();
        double gethp = monster[(i+2)%n].HP();   // 공격 당하는 몬스터의 hp
        
        if(gethp > damage){
            printf("몬스터 %d이(가) 몬스터 %d에게 %.2lf의 피해를 입혔습니다.\n", i+1, (i+2)%n+1, damage);
            monster[(i+2)%n].setHP(monster[i]); // i+1번째 몬스터의 공격력으로 i+3번째 몬스터 공격, hp 감소
        }else{
            printf("몬스터 %d이(가) 몬스터 %d에게 %.2lf의 피해를 입혔습니다.\n", i+1, (i+2)%n+1, damage);
            printf("몬스터 %d이(가) 소멸했습니다.\n", (i+2)%n+1);
            monnum--;
            cout << "현재 생존하는 몬스터 수: " << monnum << "마리" << endl;
            if(monnum < 5){
                monster[(i+2)%n].Spawn();
                monnum++;
                cout << "현재 생존하는 몬스터 수: " << monnum << "마리" << endl;
            }
        }
    }
    
    delete [] monster;
    return 0;
}
