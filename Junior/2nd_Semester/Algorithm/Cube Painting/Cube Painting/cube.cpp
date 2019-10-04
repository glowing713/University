#include <iostream>
#include <fstream>

using namespace std;


int main(void) {
    ifstream ifs;
    ofstream ofs;
    ifs.open("cube.inp");
    ofs.open("cube.out");
    
    bool check = false;
    int cnt = 0, count = 0;
    char inp[12] = {0,};
    
    while(1){
        ++count;
        check = false;
        // 두 주사위의 12색 read
        for(int i = 0; i < 12; ++i){
            ifs >> inp[i];
        }
        
        // 입력파일의 마지막인지 체크(12문자가 모두 같으면 마지막 입력)
        for(int num = 1; num < 12; ++num){
            if(inp[0] != inp[num])  check = true;
        }
        // 배열 내에 하나라도 원소가 다르면 check가 true로 바뀌므로 여전히 false이면 반복문 끝낸다.
        // 마지막인지 여부를 확인한다.
        if(check == false){
            ++cnt;
            ofs << "TRUE" << endl;
            break;
        }
        
        if(((inp[0] == inp[6]) && (inp[5] == inp[11])) || ((inp[0] == inp[11]) && (inp[5] == inp[6]))){
            
            if(((inp[1] == inp[7]) && (inp[4] == inp[10])) || ((inp[1] == inp[10]) && (inp[4] == inp[7]))){
                
                if(((inp[2] == inp[8]) && (inp[3] == inp[9])) || ((inp[2] == inp[9]) && (inp[3] == inp[8]))){
                    ++cnt;
                    ofs << "TRUE" << endl;
                }else{
                    ++cnt;
                    ofs << "FALSE" << endl;
                }
                
            }else if(((inp[1] == inp[8]) && (inp[4] == inp[9])) || ((inp[1] == inp[9]) && (inp[4] == inp[8]))){
                
                if(((inp[2] == inp[7]) && (inp[3] == inp[10])) || ((inp[2] == inp[10]) && (inp[3] == inp[7]))){
                    ++cnt;
                    ofs << "TRUE" << endl;
                }else{
                    ++cnt;
                    ofs << "FALSE" << endl;
                }
                
            }else{
                ++cnt;
                ofs << "FALSE" << endl;
            }
            
        }else if(((inp[0] == inp[7]) && (inp[5] == inp[10])) || ((inp[0] == inp[10]) && (inp[5] == inp[7]))){
            
            if(((inp[1] == inp[6]) && (inp[4] == inp[11])) || ((inp[1] == inp[11]) && (inp[4] == inp[6]))){
                
                if(((inp[2] == inp[8]) && (inp[3] == inp[9])) || ((inp[2] == inp[9]) && (inp[3] == inp[8]))){
                    ++cnt;
                    ofs << "TRUE" << endl;
                }else{
                    ++cnt;
                    ofs << "FALSE" << endl;
                }
                
            }else if(((inp[1] == inp[8]) && (inp[4] == inp[9])) || ((inp[1] == inp[9]) && (inp[4] == inp[8]))){
                
                if(((inp[2] == inp[6]) && (inp[3] == inp[11])) || ((inp[2] == inp[11]) && (inp[3] == inp[6]))){
                    ++cnt;
                    ofs << "TRUE" << endl;
                }else{
                    ++cnt;
                    ofs << "FALSE" << endl;
                }
                
            }else{
                ++cnt;
                ofs << "FALSE" << endl;
            }
            
        }else if(((inp[0] == inp[8]) && (inp[5] == inp[9])) || ((inp[0] == inp[9]) && (inp[5] == inp[8]))){
            
            if(((inp[1] == inp[6]) && (inp[4] == inp[11])) || ((inp[1] == inp[11]) && (inp[4] == inp[6]))){
                
                if(((inp[2] == inp[7]) && (inp[3] == inp[10])) || ((inp[2] == inp[10]) && (inp[3] == inp[7]))){
                    ++cnt;
                    ofs << "TRUE" << endl;
                }else{
                    ++cnt;
                    ofs << "FALSE" << endl;
                }
                
            }else if(((inp[1] == inp[7]) && (inp[4] == inp[10])) || ((inp[1] == inp[10]) && (inp[4] == inp[7]))){
                
                if(((inp[2] == inp[6]) && (inp[3] == inp[11])) || ((inp[2] == inp[11]) && (inp[3] == inp[6]))){
                    ++cnt;
                    ofs << "TRUE" << endl;
                }else{
                    ++cnt;
                    ofs << "FALSE" << endl;
                }
                
            }else{
                ++cnt;
                ofs << "FALSE" << endl;
            }
            
        }else{
            ++cnt;
            ofs << "FALSE" << endl;
        }
        
    }
    
    
    if(cnt != count){
        cout << "횟수 오류" << endl;
        return -1;
    }
    
    ifs.close();
    ofs.close();
    return 0;
}
