#include <iostream>
#include <fstream>

using namespace std;

int dp[10][1000010];



int main(void){
    ifstream ifs;
    ofstream ofs;
    ifs.open("coinmove.inp");
    ofs.open("coinmove.out");
    int cycle = 0, P = 0, K = 0, S = 0;
    bool flag = false;
    
    ifs >> cycle;   // 2
    
    for(int temp = 0; temp < cycle; ++temp){ // 전체 2번 사이클
        flag = false;
        
        ifs >> P >> K >> S; // 10 7 100
        
        // dp 배열 0부터 S까지 1씩 증가하며 채운다. P의 배수인 자리에는 'X'.
        // -99는 'X'를 뜻한다.
        for(int i = 0; i <= S; ++i){
            if(i%P == 0 && i > 0){
                dp[0][i] = -99;
            }else{
                dp[0][i] = i;
            }
        }
        
        // 승리인 W는 1로, 패배인 L는 -1로 설정한다.
        for(int j = 0; j <= S; ++j){    // 열
            for(int i = 1; i <= K; ++i){    // 행
                // 맨 왼쪽 열(0번째순서)은 몇칸을 움직이든 바깥이므로 L로 설정
                if(j == 0){
                    dp[i][j] = -1;
                    continue;
                }
                // 열 번호보다 행 번호가 크면 L이다. ex) 1열의 경우 2~K칸 움직이면 범위를 벗어나므로 L이다.
                if(j-i < 0 || dp[0][j-i] == -99){
                    dp[i][j] = -1;
                    continue;
                // 나머지는 W로 일단 설정한다. 아래에서 조건을 만족하면 L로 변경될 것
                }else{
                    dp[i][j] = 1;
                }
                // 이전에 둔 수와 같을 수 없다.(2열 1행에서 한칸 왼쪽으로 갔을 때, 1행을 제외한 나머지만 확인한다.)
                // 하나라도 W인(이기는 수) 것이 있다면 나는 L이다.
                // 또는 그 열이 X라면 무조건 L이다.
                for(int t = 1; t <= K; ++t){    // 이동한 위치의 행
                    if(t == i)  continue;
                    if(dp[t][j-i] == 1)   dp[i][j] = -1;
                }
            }
        }
        
        for(int row = 1; row <= K; ++row){
            if(dp[row][S] == 1){
                ofs << S - row << endl;
                flag = true;
                break;
            }
        }

        if(flag == false)   ofs << -1 << endl;
        
    }
    
    ifs.close();
    ofs.close();
    return 0;
}
