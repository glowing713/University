#include <iostream>
#include <fstream>

using namespace std;

int dp[210][210][210] = {0,};


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int count(int x, int y, int z);

void fillDp();



int main(void) {
    ifstream ifs;
    ofstream ofs;
    ifs.open("/Users/leesunhwan/Downloads/Coding/Xcode/University/Junior/2nd_Semester/Algorithm/Cube/Cube/cube.inp.txt");
    ofs.open("/Users/leesunhwan/Downloads/Coding/Xcode/University/Junior/2nd_Semester/Algorithm/Cube/Cube/cube.out.txt");
    int cycle = 0, a = 0, b = 0, c = 0;
    
    ifs >> cycle;
    
    for(int num = 0; num < cycle; ++num){
        int max = 0;
        
        ifs >> a >> b >> c;
        
        if(a > b){
            if(a > c) max = a;
            else max = c;
        }else max = b;
        
        fillDp();
        
        ofs << dp[a][b][c] << endl;
    }
    
    
    
    ifs.close();
    ofs.close();
    
    return 0;
}


int count(int x, int y, int z){
    
    if(x > y) swap(&x, &y);
    if(x > z) swap(&x, &z);
    if(y > z) swap(&y, &z);
    
    return dp[x][y][z];
}

void fillDp(){
    for(int i = 1; i <= 200; ++i){
        for(int j = 1; j <= 200; ++j){
            for(int k = 1; k <= 200; ++k){
                int minx = 99999, miny = 99999, minz = 99999;
                // 세 변의 길이가 같은 경우 1가지로 카운드한다.
                if(i == j && j == k){
                    dp[i][j][k] = 1;
                    continue;
                }
                
                // 세 변 중 하나라도 길이가 1이면 부피가 1인 정육면체 i*j*k개로 채울 수 있다.
                if(i==1 || j==1 || k==1){
                    dp[i][j][k] = i*j*k;
                    continue;
                }
                
                // 세 변이 모두 길이가 2 이상이고, 세 변이 모두 같지는 않은 경우(2,2,4/3,6,2 등과 같은)
                // i변을 나누는 경우, j변을 나누는 경우, z변을 나누는 경우 중 최소값을 dp에 저장할거다.
                for(int x = 1; x <= i/2; ++x){
                    int temp = count(x, j, k) + count(i-x, j, k);
                    if(temp < minx) minx = temp;
                }
                for(int y = 1; y <= j/2; ++y){
                    int temp = count(i, y, k) + count(i, j-y, k);
                    if(temp < miny) miny = temp;
                }
                for(int z = 1; z <= k/2; ++z){
                    int temp = count(i, j, z) + count(i, j, k-z);
                    if(temp < minz) minz = temp;
                }
                
                if(minx < miny){
                    if(minz < minx){
                        dp[i][j][k] = minz;
                        //cout << dp[i][j][k] << ", ";
                    }else{
                        dp[i][j][k] = minz;
                        //cout << dp[i][j][k] << ", ";
                    }
                }else{
                    dp[i][j][k] = miny;
                    //cout << dp[i][j][k] << ", ";
                }
            }
        }
    }
}
