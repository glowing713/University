#include <iostream>

using namespace std;

class Cashier{
    
protected:
    string menu[5] = {"Cappucino", "Espresso", "Hot Chocolate", "Caffe Latte", "Milk Shake"};
    int price[5] = {4900, 3000, 3800, 4000, 4300};
public:
    // 가격이 포함된 메뉴판 제공
    void showMenu(){
        cout << "Welcome to Starbucks!" << endl;
        for(int i = 0; i < 5; ++i){
            cout << i+1 << ". " << menu[i] << "(" << price[i] << "원)" << endl;
        }
    }
    
};

class Barrister:protected Cashier{
    void makeCoffee(int drinknum){
        cout << "주문하신 " <<
    }
};

class Client:Cashier{
    // 고객에게 돈을 받고 거스름돈 제공
    void order(int drinknum, int getmoney){
        if(price[drinknum-1] > getmoney){
            cout << "돈이 부족합니다. " << price[drinknum-1] - getmoney << "원 만큼 더 주세요." << endl;
        }
        
        cout << "거스름돈 " << getmoney - price[drinknum-1] << "원 입니다." << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
