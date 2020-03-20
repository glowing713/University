#include <iostream>
#include <fstream>

using namespace std;

/*************************** 입력된 값의 약수 개수를 구하는 함수 ***************************/

int counter(int n){     // 정수를 입력받아 약수의 개수를 리턴한다.
    int cnt = 0; // 약수 개수 저장 변수.
    
    for(int i = 1; i * i <= n; ++i){    /* 36을 예로 들면 최대 약수가 6이다.
                                           약수의 개수를 제곱수 기준으로 반으로 나누어 구하겠다는 뜻. */
        if(n % i == 0){     // i가 약수이면 cnt 증가.
            ++cnt;
            if(i * i < n)   // 36의 약수 중에 3은 12와 짝인 것처럼 짝의 개수를 더해주는 것.
                ++cnt;
        }
        
    }
    return cnt;
}


/***************************** 되 나눔수 인지 확인하는 함수 *****************************/

bool check(int m){   // 정수를 입력받아 되 나눔수 인지 아닌지 boolean으로 알려준다.
    int div_cnt = counter(m);   // counter 함수를 통해 약수의 개수를 받아 저장.
    
    if(m % div_cnt == 0){   // 약수의 개수로 입력받은 정수를 나누어 나머지가 0이면 true 리턴, 0이 아니면 false.
        return true;
    }else
        return false;
}


/*********************************** 메인 함수 ***********************************/

int main(void){
    ifstream ifs;
    ofstream ofs;
    int num = 0, a = 0, b = 0, count = 0;  // 경우의 수 , 입력될 숫자 a와 b
    
    ifs.open("divisor.inp");
    ofs.open("divisor.out");
    
    ifs >> num;     // 총 케이스 수 read
    if(num < 0 || num > 50){    // 오류 체크
        cout << "케이스 수 오류" << endl;
        return -1;
    }
    
    for(int i = 0; i < num; ++i){   // 케이스 수만큼 반복
        ifs >> a >> b;  // a와 b read
        if(a < 1 || b < 1 || a > 1000000 || b > 1000000 || a > b || b-a > 1000){
            cout << "a, b 범위 오류" << endl;
            return -1;
        }
        
        for(int j = a; j <= b; ++j){    // a와 b사이에서 check 함수를 통해 되 나눔수만 골라서 count 증가.
            if(check(j) == true){   // 되 나눔수이면 증가.
                ++count;
            }
        }
        
        ofs << count << endl;
        count = 0;
    }
    
    ifs.close();
    ofs.close();
    
    return 0;
}
