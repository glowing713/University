#include <iostream>

using namespace std;

/***********************  자판기 클래스  ***********************/

/* 화면에 메뉴판이 출력되는 것으로 프로그램이 시작됩니다.
   금액을 투입하면 현재 투입한 총 액수가 화면에 나옵니다.
   구매하려는 음료의 번호를 누를 때, 금액이 충분하면 선택한 음료가 나왔다는 문구와 함께
   현재 남은 잔액이 표시됩니다. 여기서 잔돈을 거슬러 받을수도, 이어서 금액 투입과 구매를 재개할 수 있습니다.
   구매 전이든, 구매 후든 언제든 잔돈을 거슬러 받고 자판기 사용을 중지할 수 있습니다. */

class Vending{
    
// 음료의 종류와 가격은 외부에서 변경할 수 없다.
// 손님도 돈을 투입만 할수있고 임의로 수정할 수 없다.
private:
    string m_drink[6] = {"코카콜라", "스프라이트", "핫식스", "포카리스웨트", "코코팜", "밀키스"};
    int m_price[6] = {1000, 900, 1100, 800, 700, 800};
    int m_count[6] = {10, 10, 10, 10, 10, 10};
    int m_money = 0;
    
public:
    void showMenu();    // 메뉴판 출력 함수
    void inputMoney();   // 투입한 금액 누적
    bool checkAvail(int num);  // 투입한 금액으로 음료를 살 수 있는지 체크
    bool checkCount(int num);  // 남은 잔고가 존재하는지 확인
    void printDrink(int num);  // 선택한 음료 전달
    void returnChange();    // 잔돈 반환 함수
};
/***********************************************************/


// 메뉴판(음료 6가지) 출력
void Vending::showMenu(){
    cout << "-----------------------  <메뉴판>  -----------------------" << endl;
    for(int i = 0; i < 6; ++i){
        if(i == 0 || i == 3)    cout << "  ";
        cout << i+1 << "번: " << m_drink[i] << " " << m_price[i] << "원 ";
        if((i+1) % 3 == 0)  cout << endl;
    }
    cout << "--------------------------------------------------------\n" << endl;
}

// 투입할 금액을 입력받고 총 투입한 금액을 보여준다.
void Vending::inputMoney(){
    int input = 0;
    cout << "투입할 금액: ";
    cin >> input;
    this->m_money += input;
    cout << "총 " << m_money << "원" << endl;
}

// 음료를 선택했을 때, 지금까지 투입한 금액으로 구매 가능한지 아닌지를 체크
bool Vending::checkAvail(int num){
    if(m_price[num-1] <= m_money){
        m_money -= m_price[num-1];
        return true;
    }else   return false;
}

bool Vending::checkCount(int num){
    if(m_count[num-1] == 0){
        return false;
    }else{
        m_count[num-1] -= 1;
        return true;
    }
}

void Vending::printDrink(int num){
    cout << "선택하신 " << m_drink[num-1] << " 나왔습니다." << endl;
    cout << "현재 남은 금액: " << m_money << "원" << endl;
}

void Vending::returnChange(){
    cout << m_money << "원 반환됩니다." << endl;
    m_money = 0;
}


int main(void){
    int drink_num = 0;  // 손님이 구매하려는 음료 번호 저장 변수
    string change = " ", keep = " ";
    Vending v1;
    
    v1.showMenu();  // 메뉴판 출력
    
    // 잔돈 반환을 신청하기 전까지 투입과 판매를 무한 반복
    do{
        
        do{
            
            v1.inputMoney();   // 금액 투입
            cout << "구매하려는 음료 번호를 입력하세요(0번은 잔돈 반환): ";
            cin >> drink_num;
            
            // 음료 선택하려다 그냥 안하고싶을때...
            if(drink_num == 0){
                v1.returnChange();
                return 0;
            }
            
            /* 지금까지 투입한 금액으로 선택한 음료 구매 가능하고, 남은 수량이 존재하면 금액 차감하고 음료 전달. */
            if(v1.checkAvail(drink_num)){
                if(v1.checkCount(drink_num)){
                    v1.printDrink(drink_num);
                }else{
                    cout << "남은 수량이 없습니다." << endl;
                }
            }else{
                cout << "금액이 부족합니다..!" << endl;
            }
            
            cout << "잔돈 반환?(yes/no) ";
            cin >> keep;
            if(keep == "yes") v1.returnChange();  // yes한 경우 잔돈 반환
            
        }while(keep == "no");
        
        
        if(keep == "yes")   break;  // 돈을 투입하다 중간에 잔돈 반환한 경우 반복문 탈출
        
        
        cout << "잔돈 반환?(yes/no) ";
        cin >> change;
        if(change == "yes") v1.returnChange();  // yes한 경우 잔돈 반환
        
    }while(change == "no");
    
    
    return 0;
}
