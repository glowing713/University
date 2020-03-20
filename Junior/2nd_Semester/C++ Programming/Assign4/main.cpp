#include <iostream>

using namespace std;

int main(void) {
    int n = 0;
    
    cout << "입력할 사람 수를 정하세요: ";
    cin >> n;
    cin.ignore();
    
    string *name = new string[n];
    
    for(int i = 0; i < n; ++i){
        cout << "이름: ";
        getline(cin, name[i], '\n');
        
    }
    
    for(int i = n-1; i >= 0; --i){
        for(int j = 0; j < i; ++j){
            if(name[j] > name[j+1]) name[j+1].swap(name[j]);
        }
    }
    
    cout << "***사전순으로 배열***" << endl;
    
    for(int i = 0; i < n; ++i){
        cout << name[i] << endl;
    }
    
    return 0;
}
