#include <iostream>

using namespace std;

class Power{
    int kick, punch;
public:
    Power(int kick=0, int punch=0){
        this->kick = kick;
        this->punch = punch;
    }
    void show();
    
    Power& operator++ (){
        this->kick++;
        this->punch++;
        return *this;
    }
};

void Power::show(){
    cout << "kick = " << this->kick << ", " << "punch = " << punch << endl;
}


int main(){
    Power a(3,5);
    a.show();
    (++(++(++a))).show();
    a.show();
}
