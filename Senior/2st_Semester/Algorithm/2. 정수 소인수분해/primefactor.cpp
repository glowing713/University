#include <iostream>
#include <fstream>
#define MAX 100010

using namespace std;

// eratos[i] 가 소수이면,eratos[i] == -1, 아니면 eratos[i] == 0
int eratos[MAX] = {0, };
// 배열의 인덱스에 해당하는 숫자들의 소인수 합
int number_Sum[MAX] = {0, };

// eratos[i] 가 소수이면,eratos[i] == -1, 아니면 eratos[i] == 0
void fillEratos();
// 배열의 인덱스에 해당하는 숫자들의 소인수 합을 배열에 채운다!
void fillNumberSum();


int main() {
    ifstream ifs;
    ofstream ofs;
    ifs.open("primefactor.inp");
    ofs.open("primefactor.out");
    
    
    int cycle = 0;  // Count of test
    
    ifs >> cycle;
    
    
    // 에라토스테네스의 체를 이용해서 2~100000 사이의 소수를 찾는다.
    fillEratos();
    // 2~100000 사이의 모든 수의 소인수 총합을 배열 인덱스 수에 해당하는 위치에 구한다.
    fillNumberSum();
    
    while (cycle--) {
        int number = 0;
        
        ifs >> number;
        
        if (eratos[number] == 0) {
            ofs << "Prime Number\n";
        }else {
            ofs << number_Sum[number] << endl;
        }
    }
    
    
    ifs.close();
    ofs.close();
    
    return 0;
}



// eratos[i] 가 소수이면,eratos[i] == 0, 아니면 eratos[i] == -1
void fillEratos() {
    for (int i = 2; i * i <= 100000; ++i) {
        if (eratos[i] == -1) {
            continue;
        }else {
            // 소수의 배수들은 -1로 체크(소수가 아니라는 뜻)
            for (int j = i + i; j <= 100000; j += i) {
                eratos[j] = -1;
            }
        }
    }
}


// 배열의 인덱스에 해당하는 숫자들의 소인수 합을 배열에 채운다!
void fillNumberSum() {
    for (int i = 2; i <= 100000; ++i) {
        
        if (eratos[i] == 0){
            // 소수는 자기 자신이 총합
            number_Sum[i] = i;

            // 그 다음, 그 소수의 배수들에 합을 구할거야. 8은 2로 나누면 4이니깐, 4의 총합과 2를 더하는거지.
            for (int j = i + i; j <= 100000; j += i) {
                if (j % i == 0) {
                    number_Sum[j] = number_Sum[j / i] + i;
                }
            }
        }
        
    }
}
