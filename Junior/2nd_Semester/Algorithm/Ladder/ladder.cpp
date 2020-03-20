#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef struct coor{
    int x;
    int y;
}Coor;

int main(void) {
    ifstream ifs;
    ofstream ofs;
    ifs.open("ladder.inp");
    ofs.open("ladder.out");
    Coor c1;
    Coor ladPoint[60][10010]; // 사다리 좌표 저장 배열
    memset(ladPoint, -1, sizeof(ladPoint)); // 좌표가 없는 곳을 구별하기 위해 -1로 초기화
    int result[50] = {0,};
    int ladCnt = 0; // 사다리 개수 변수
    int a = 0, b = 0, c = 0, d = 0;
    
    ifs >> ladCnt;
    
    while(ifs >> a >> b >> c >> d){
        if(a == 0 && b == 0 && c == 0 && d == 0)    break;

        c1.x = c;
        c1.y = d;
        ladPoint[a][b] = c1;
        c1.x = a;
        c1.y = b;
        ladPoint[c][d] = c1;
    }
    
    for(int i = 0; i < ladCnt; ++i){
        int m = 0, j = 9999;
        int temp = i;
        while(j >= 0){
            while((ladPoint[i][j].y == -1) && (j >= 0)){
                --j;
            }
            if(j <= 0)  break;
            m = ladPoint[i][j].x;
            j = ladPoint[i][j].y - 1;
            i = m;
        }
        result[i] = temp;
        i = temp;
    }
    
    for(int i = 0; i < ladCnt; ++i){
        ofs << result[i] << " ";
    }
    
    
    ifs.close();
    ofs.close();
    
    return 0;
}
