#define MAX 4000
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// 색종이의 모든 좌표를 저장하는 구조체
typedef struct XY{
    int x1;
    int x2;
    int y1;
    int y2;
}XY;

int map[MAX][MAX] = {0};    // 결과를 표시할 좌표평면

int main(void){
    ifstream ifs;
    ofstream ofs;
    ifs.open("paper.inp");
    ofs.open("paper.out");
    
    XY coor_inp[2000] = {0,};  // 좌표를 입력받을 배열
    vector<int> x_coor, y_coor; // x와 y좌표를 중복된 것 없이 오름차순 정렬하기 위한 벡터
    int a, b, c, d; // 여러모로 사용할 임시 변수
    int paper_cnt = 0;  // 색종이 개수 저장
    int result[3] = {0,};   // 결과 저장 배열
    bool flag1 = true, flag2 = true;   // 색종이의 가림 여부 체크
    
    ifs >> paper_cnt;
    
    // (x, y, 너비, 높이)를 계산하여 (x1, y1, x2, y2)로 변환 저장
    for(int i = 0; i < paper_cnt; ++i){
        ifs >> a >> b >> c >> d;
        coor_inp[i].x1 = a;
        coor_inp[i].y1 = b;
        coor_inp[i].x2 = a + c;
        coor_inp[i].y2 = b + d;
    }
    
    // x와 y좌표를 중복되는 것 제거하고 정렬하기 위해 벡터에 삽입
    for(int j = 0; j < paper_cnt; ++j){
        x_coor.push_back(coor_inp[j].x1);
        x_coor.push_back(coor_inp[j].x2);
        y_coor.push_back(coor_inp[j].y1);
        y_coor.push_back(coor_inp[j].y2);
    }
    
    // 오름차순으로 벡터 정렬
    sort(x_coor.begin(), x_coor.end());
    sort(y_coor.begin(), y_coor.end());
    
    // <중복원소 제거>
    /* unique 함수는 정렬된 벡터의 시작과 끝 iterator를 인자로 주면 모든 수를 한번씩만 써서 정렬한
     sequence를 앞으로 오게하고 그 끝 iterator을 반환한다.
     넘겨받은 iterator부터 맨 끝까지 erase 함수로 지운다.*/
    x_coor.erase(unique(x_coor.begin(), x_coor.end()), x_coor.end());
    y_coor.erase(unique(y_coor.begin(), y_coor.end()), y_coor.end());
    
    
    /************ 4000*4000 좌표평면에 색종이 위치 표시 ************/
    // 1번 색종이는 자신의 면적에 1로 표시, n번 색종이는 자신의 면적에 n으로 표시
    for(int i = 0; i < paper_cnt; ++i){
        a = -1;
        b = -1;
        c = -1;
        d = -1;
        // 실제 좌표를 0,1,2,..(인덱스 번호와 동일)로 축소한다.
        for(int num1 = 0; num1 < x_coor.size(); ++num1){
            if(x_coor[num1] == coor_inp[i].x1)   a = (int)num1;
        }
        for(int num2 = 0; num2 < x_coor.size(); ++num2){
            if(x_coor[num2] == coor_inp[i].x2)   c = (int)num2;
        }
        for(int num3 = 0; num3 < y_coor.size(); ++num3){
            if(y_coor[num3] == coor_inp[i].y1)   b = (int)num3;
        }
        for(int num4 = 0; num4 < y_coor.size(); ++num4){
            if(y_coor[num4] == coor_inp[i].y2)   d = (int)num4;
        }
        
        if((a == -1) || (b == -1) || (c == -1) || (d == -1)){
            cout << "좌표 축소과정에 오류생김" << endl;
            return -1;
        }
        
        // i번 색종이는 자신의 면적에 i + 1으로 표시(1번 색종이가 i는 0이므로)
        for(int j = a; j < c; ++j){
            for(int k = b; k < d; ++k){
                map[j][k] = i + 1;
            }
        }

    }
    
    // 색종이의 겹침여부 체크
    // l+1이 현재 색종이 번호
    for(int l = 0; l < paper_cnt; ++l){
        flag1 = true;
        flag2 = true;
        a = -1;
        b = -1;
        c = -1;
        d = -1;
        // 색종이들의 수정된 좌표
        for(int num1 = 0; num1 < x_coor.size(); ++num1){
            if(x_coor[num1] == coor_inp[l].x1)   a = (int)num1;
        }
        for(int num2 = 0; num2 < x_coor.size(); ++num2){
            if(x_coor[num2] == coor_inp[l].x2)   c = (int)num2;
        }
        for(int num3 = 0; num3 < y_coor.size(); ++num3){
            if(y_coor[num3] == coor_inp[l].y1)   b = (int)num3;
        }
        for(int num4 = 0; num4 < y_coor.size(); ++num4){
            if(y_coor[num4] == coor_inp[l].y2)   d = (int)num4;
        }
        
        if((a == -1) || (b == -1) || (c == -1) || (d == -1)){
            cout << "좌표 축소과정에 오류생김" << endl;
            return -1;
        }
        
        for(int m = a; m < c; ++m){
            for(int n = b; n < d; ++n){
                // n번 색종이 내부에 n이 아닌 숫자만 존재하면 완전히 가림,
                // n이 아닌 숫자도 있으면 부분적으로 가림,
                // n만 존재하면 완전히 보임.
                if(map[m][n] != l + 1){
                    flag1 = false;   // 가린부분이 있다는 것.
                }
            }
        }
        
        if(flag1 == true){   // 완전히 보이는 상태
            result[2] += 1;
        }else{  // 전체나 부분적으로 가려진 상태
            for(int i = a; i < c; ++i){
                for(int j = b; j < d; ++j){
                    if(map[i][j] == l + 1){ // 가려진 상태이나 자신의 숫자가 존재하므로 부분적으로 가려졌다는 뜻.
                        flag2 = false;
                    }
                }
            }
            
            if(flag2 == false){ // 부분적으로 가려진 상태
                result[1] += 1;
            }else{
                result[0] += 1;
            }
        }
    }
    
    for(int i = 0; i < 3; ++i){
        ofs << result[i] << " ";
    }
    
    
    ifs.close();
    ofs.close();
    return 0;
}
