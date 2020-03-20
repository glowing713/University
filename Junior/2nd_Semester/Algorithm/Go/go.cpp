#include <iostream>
#include <fstream>

using namespace std;


/*
 바둑판 내에 빈공간인 . 이 상하좌우로 움직이며 판의 가장자리나/돌이나/속성을 갖고있는 빈공간을 만나면
 거기서 멈추고 다음 위치(상하좌우 중 순서대로)로 이동한다.
 한 . 의 상하좌우에 돌이 존재한다면 모두 색이 같아야 B나 W 중 하나로 속성이 바뀐다. 서로 다르거나 주변의 빈공간 속성이 다르면 N을 띈다.
 배열의 처음부터 끝까지 한번 돌고나면 B인 것과 W인 것의 개수를 각각 센다.
 */



int main(void){
    ifstream ifs;
    ofstream ofs;
    ifs.open("go.inp");
    ofs.open("go.out");
    int k = 0;  // 격자의 차수
    int black = 0;
    int white = 0;
    int goField[20][20]; // 바둑판
    char temp;
    
    ifs >> k;
    
    // Exception 처리
    if(k < 3 || k > 19){
        cout << "k는 3이상 19이하의 정수입니다. 격자의 차수를 다시 입력하세요!" << endl;
        return -1;
    }
    
    // 숫자로 구성된 바둑판 만들기
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < k; ++j){
            ifs >> temp;
            
            if(temp == '.') goField[i][j] = -1; // 빈 공간인 경우 배열에 -1로 저장
            else if(temp == 'B'){
                goField[i][j] = 1;  // 흑돌인 경우 배열에 1로 저장
                --black;
            }else{
                goField[i][j] = 2;  // 백돌인 경우 배열에 2로 저장
                --white;
            }
        }
    }
    
    
    for(int start = 0, end = k-1; start <= end; ++start, --end){
        // 좌측 상단이 빈공간인 경우 따로 초기화
        if(goField[0][start] == -1){
            int col = start;
            int flag = 0;
            while(col <= end){
                if(goField[0][col] != -1){
                    flag = 1;
                    break;
                }
                ++col;
            }
            // 0번 행의 오른쪽에서 돌을 만났다면, 그 돌을 대입.
            if(flag == 1)   goField[0][start] = goField[0][col];
        }
        
        // 맨 왼쪽 열 세팅
        for(int i = 1; i < k; ++i){ // 행
            int col = start;
            int flag = 0;
            while(col <= end){
                if(goField[i][col] != -1){
                    flag = 1;
                    break;
                }
                ++col;
            }
            // 오른쪽에서 돌을 만났고, 그 돌이 내 바로 위 돌과 색이 같으면 대입.
            if(flag == 1)   if(goField[i][col] == goField[i-1][start])  goField[i][start] = goField[i][col];
        }
        
        // 우측 상단이 빈공간인 경우 따로 초기화
        if(goField[0][end] == -1){
            int col = end;
            int flag = 0;
            while(col >= start){
                if(goField[0][col] != -1){
                    flag = 1;
                    break;
                }
                --col;
            }
            // 0번 행의 오른쪽에서 돌을 만났다면, 그 돌과 일치.
            if(flag == 1)   goField[0][end] = goField[0][col];
        }
        
        // 맨 오른쪽 열 세팅
        for(int i = 1; i < k; ++i){
            int col = end;
            int flag = 0;
            while(col >= start){
                if(goField[i][col] != -1){
                    flag = 1;
                    break;
                }
                --col;
            }
            // 왼쪽에서 돌을 만났고, 그 돌이 내 바로 위 돌과 색이 같으면 대입.
            if(flag == 1)   if(goField[i][col] == goField[i-1][end])  goField[i][end] = goField[i][col];
        }
        
    }
    
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < k; ++j){
            if(goField[i][j] == 1){
                ++black;
            }else if(goField[i][j] == 2){
                ++white;
            }
        }
    }
    
    ofs << black << " " << white << endl;
    
    ifs.close();
    ofs.close();
    return 0;
}
