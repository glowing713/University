#include <iostream>
#include <fstream>

using namespace std;

/* Coin in a line 문제와 유사하다. DP를 활용, memoize한다.
   점화식은 dp[i][j].first = max(cards[i] + dp[i+1][j].second, cards[j] + dp[i][j-1])
          dp[i][j].second = dp[i+1][j].first or dp[i][j-1] 로 결정된다.
   dp[i][j].first가 첫번째 주자의 점수, dp[i][j].second가 두번째 주자의 점수이다. */


typedef struct Score{
    int first;
    int second;
}SCORE;


// DP 배열을 확인하기 위한 출력 함수
void printArr(SCORE dp[1000][1000], int size){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            cout << "(" << dp[i][j].first << "," << dp[i][j].second << ") ";
        }
        cout << endl;
    }
}



int main(void) {
    ifstream ifs;
    ofstream ofs;
    ifs.open("card.inp");
    ofs.open("card.out");
    int testcase = 0, cardnum = 0;
    int score = 0;
    int cards[1000] = {0,};
    SCORE dp[1000][1000] = {0,};
    
    ifs >> testcase;
    
    while(testcase--){
        ifs >> cardnum;
        
        for(int i = 0; i < cardnum; ++i){
            ifs >> cards[i];
        }
        
        // 대각선은 자기 자신 그대로 채운다
        for(int i = 0; i < cardnum; ++i){
            dp[i][i] = {cards[i], 0};
        }
        
        // 숫자 두개로 비교하는 건 비교해서 바로 넣는다
        for(int i = 0; i < cardnum - 1; ++i){
            cards[i] < cards[i+1] ? dp[i][i+1] = {cards[i+1], cards[i]} : dp[i][i+1] = {cards[i], cards[i+1]};
        }
        
        // 나머지도 채운다
        for(int k = 2; k < cardnum; ++k){
            for(int i = 0; i < cardnum-k; ++i){
                int j = i+k;
                if(cards[i]+dp[i+1][j].second < cards[j]+dp[i][j-1].second){
                    dp[i][j].first = cards[j]+dp[i][j-1].second;
                    dp[i][j].second = dp[i][j-1].first;
                }else{
                    dp[i][j].first = cards[i]+dp[i+1][j].second;
                    dp[i][j].second = dp[i+1][j].first;
                }
            }
        }
        
        ofs << dp[0][cardnum-1].first << endl;
    }
    
    
    ifs.close();
    ofs.close();
    
    return 0;
}
