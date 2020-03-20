#include <fstream>
#include <iostream>

using namespace std;


int num = 0;
int board[9][9]={0,};   // 스도쿠의 숫자가 기록되어 있음.
char area[9][9];    // 스도쿠 내에서 같은 구역이면 같은 알파벳이 기록되어 있음.
bool flag;



int jigsaw();
bool check(int x, int y, int k);    // 넘겨받은 벡터내의 좌표는 board의 빈공간. 그 공간에 k가 들어갈수 있는지 여부를 알려준다.




int main(void){
    ifstream ifs;
    ofstream ofs;
    ifs.open("sudoku.inp");
    ofs.open("sudoku.out");
    
    int cycle = 0;
    int cnt = 1;
    
    ifs >> cycle;
    
    
    while(cycle--){
        // 입력파일의 스도쿠 판 읽어오기
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                ifs >> board[i][j];
            }
        }
        // 입력파일의 스도쿠 구역 읽어오기
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                ifs >> area[i][j];
            }
        }
        
        jigsaw();
        
        
        ofs << "Test Case No: " << cnt << endl;
        
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                ofs  <<  board[i][j];
            }
            ofs << endl;
        }
        ofs << endl;
        
        cnt++;
    }
    
    ifs.close();
    ofs.close();
    
    return 0;
}



int jigsaw(){
    for (int i = 0; i < 9; ++i){
           for (int j = 0; j < 9; ++j){
               if (board[i][j] == 0){
                   for (int z = 1; z <= 9; z++){
                       if (check(i, j, z) == 1){
                           board[i][j] = z;
                           jigsaw();
                           if (flag == true) return 0;
                           board[i][j] = 0;
                       }
                   }
                   return 0;
               }
           }
       }
       flag = true;
    
       return 0;
}


bool check(int x, int y, int k){
    char symbol = area[x][y];
 
    // 행 검사
    for (int j = 0; j < 9; j++){
        if (board[x][j] == k){
            return 0;
        }
    }
    // 열 검사
    for (int i = 0; i < 9; i++){
        if (board[i][y] == k){
            return 0;
        }
    }
    // 구간 검사
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(area[i][j] == symbol && board[i][j] == k)
                return 0;
        }
    }
 
    return 1;
}
