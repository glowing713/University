#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ifstream ifs;
    ofstream ofs;
    ifs.open("pandora.inp");
    ofs.open("pandora.out");
    int T = 0;
    int ppre = 0, pre = 0, re = 0;  // 0은 위, 1은 왼쪽, 2는 아래쪽, 3은 오른쪽
    int x = 1, y = 1;
    string s = " ";
    
    ifs >> T;
    
    for(int i = 0; i < T; ++i){
        ifs >> s;
        s.push_back(s[0]);
        s.push_back(s[1]);
        s.push_back(s[2]);
        
        for(int j = 0; j < s.size(); ++j){
            if(s[j] == 'L'){
                ppre = pre;
                pre = re;
                re = (re + 1) % 4;
            }else if(s[j] == 'R'){
                ppre = pre;
                pre = re;
                re = (re + 3) % 4;
            }
            
            // y축을 기준으로 monotone인 경우 -1 한다.
            if((ppre == 3) && (pre == 2) && (re == 1))  x = 0;
            if((ppre == 1) && (pre == 0) && (re == 3))  x = 0;
            
            // x축을 기준으로 monotone인 경우 -1 한다.
            if((ppre == 2) && (pre == 1) && (re == 0))  y = 0;
            if((ppre == 0) && (pre == 3) && (re == 2))  y = 0;
        }
        
        ofs << x + y << endl;
        x = 1;
        y = 1;
        s = " ";
    }
    
    
    ifs.close();
    ofs.close();
    return 0;
}
