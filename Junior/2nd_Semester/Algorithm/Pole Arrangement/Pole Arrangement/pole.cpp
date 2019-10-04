#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ifstream ifs;
    ofstream ofs;
    ifs.open("pole.inp");
    ofs.open("pole.out");
    int T = 0;
    int a = 0, b = 0, c = 0;
    long pole[30][30][30] = {0,};
    
    pole[1][1][1] = 1;
    
    for(int n = 2; n <= 20; ++n){
        for(int l = 1; l <= n; ++l){
            for(int r = 1; r <= n; ++r){
                pole[n][l][r] = pole[n-1][l-1][r] + pole[n-1][l][r-1] + (pole[n-1][l][r] * (n-2));
            }
        }
    }
    
    
    ifs >> T;   // test case cnt
    
    for(int i = 0; i < T; ++i){
        ifs >> a >> b >> c;
        
        ofs << pole[a][b][c] << endl;
    }
    
    
    ifs.close();
    ofs.close();
    return 0;
}
