#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/****************************************************** 구조체 선언 ******************************************************/
typedef struct frame_size{
    int pnum;
    int cnt;
}SIZE; // 입력파일의 프로세스 번호, 페이지 번호 저장 구조체

typedef struct frame{
    int index;
    int pnum;
    int cnt;
    int valid = 0;
}FRAME; // frame 벡터에 저장할 때 사용할 구조체


/*************************************************** 페이지 교체 함수 선언 ***************************************************/
void FIFO(vector<FRAME> f1, int inp_a, int inp_b, int turn);

void LRU(vector<SIZE>::iterator inp_itr, vector<SIZE> input_list, vector<FRAME> f1, int inp_a, int inp_b, int leng);

void OPT(vector<SIZE>::iterator inp_itr, vector<SIZE> input_list, vector<FRAME> f1, int inp_a, int inp_b, int leng);


/*************************************************** Main 함수 선언 ***************************************************/
int main(void){
    int frame_Leng = 0, index = 0, inp_a = 0, inp_b = 0, fault = 0, temp = 1; // 프레임 갯수, FRAME.index, INPUT.pnum, INPUT.cnt, fault 횟수, 교체순서 기억할 임시변수
    SIZE input_struct;
    FRAME frame_struct;
    vector<SIZE> input_list;    // 입력파일 데이터 저장
    vector<SIZE> size_vector;
    vector<FRAME> frame_vector;
    vector<SIZE>::iterator inp_itr, itr1;   // input_list 벡터 iterator, size 벡터 iterator
    vector<FRAME>::iterator itr2;   // frame 벡터 iterator
    ifstream ifs;   // 입력 스트림
    ofstream ofs;   // 출력 스트림
    ifs.open("page.inp");
    ofs.open("page.out", ios::app);
    
    /*------------------------------------> Input FILE READ <------------------------------------*/
    ifs >> frame_Leng;
    
    while(inp_a != -1 && inp_b != -1){      // 입력파일 읽어와서 구조체형으로 벡터에 저장
        ifs >> inp_a >> inp_b;
        input_struct = {inp_a, inp_b};
        input_list.push_back(input_struct);
    }
    
    
    /*------------------------------------> FIFO, LRU, OPT로 세 번 수행 <------------------------------------*/
    for(int i = 0; i < 3; i++){
        index = 0;
        fault = 0;  // 페이지 fault 횟수 초기화
        temp = 1;   // 페이지 교체 순서 초기화
        /*------------------------------------> 첫 줄 READ <------------------------------------*/
        inp_a = input_list[0].pnum;
        inp_b = input_list[0].cnt;
        input_struct = {inp_a, 1};  // size_vector(11, 1)
        frame_struct = {index, inp_a, inp_b};   // frame_vector(0, 11, 1)
        size_vector.push_back(input_struct);    // size 벡터에 push
        frame_vector.push_back(frame_struct);   // frame 벡터에 push
        
        /*-------------------------------------> 참조열 -1 -1을 읽으면 종료 <-------------------------------------*/
        for(inp_itr = input_list.begin()+1; inp_itr != input_list.end()-1; inp_itr++){
            
            bool flag = false; // 읽어온 프로세스가 size 벡터에 존재하는지 여부 표시
            inp_a = inp_itr->pnum;
            inp_b = inp_itr->cnt;
            
            /*-----------------------------> size 벡터에 읽어온 프로세스가 존재하는 경우 <-----------------------------*/
            for(itr1 = size_vector.begin(); itr1 != size_vector.end(); itr1++){
                if(itr1->pnum == inp_a){
                    flag = true;   // size 벡터에 읽어온 프로세스가 존재하면 true로 변경
                    if(itr1->cnt < frame_Leng){ // frame 공간이 남은 경우
                        index++;
                        itr1->cnt++;
                        frame_struct = {index, inp_a, inp_b};
                        frame_vector.push_back(frame_struct);
                    }else{  // frame 공간이 꽉찬 경우
                        /*-----------------------------> Frame에 페이지가 존재하는지 검사 <-----------------------------*/
                        bool exist = false;
                        for(itr2 = frame_vector.begin(); itr2 != frame_vector.end(); itr2++){   // 페이지가 존재하면 true 플래그
                            if(itr2->pnum == inp_a && itr2->cnt == inp_b){
                                exist = true;
                            }
                        }
                        if(exist == false){     // 여전히 false 플래그이면 페이지 fault이므로 교체 수행
                            if(i == 0){
                                FIFO(frame_vector, inp_a, inp_b, temp);
                            }else if(i == 1){
                                LRU(inp_itr, input_list, frame_vector, inp_a, inp_b, frame_Leng);
                            }else{
                                OPT(inp_itr, input_list, frame_vector, inp_a, inp_b, frame_Leng);
                            }
                            fault++;
                            temp = (temp % frame_Leng) + 1;     // 입력받은 페이지들 중 교체해야하는 순서을 기록
                            for(itr2 = frame_vector.begin(); itr2 != frame_vector.end(); itr2++){
                                itr2->valid = 0;
                            }
                        }
                    }   // frame 공간이 꽉차있으나 페이지가 존재하면 교체를 수행하지 않는다.
                }
            }
            
            /*-----------------------> size 벡터에 읽어온 프로세스가 없는 경우(flag가 여전히 false 인 케이스) <-----------------------*/
            if(flag == false){
                fault++;
                index++;
                input_struct = {inp_a, 1};
                frame_struct = {index, inp_a, inp_b};
                size_vector.push_back(input_struct);
                frame_vector.push_back(frame_struct);
            }
            
        }
        if(i == 0){
            ofs << "FIFO: " << fault << endl;
        }else if(i == 1){
            ofs << "LRU: " << fault << endl;
            LRU(inp_itr, input_list, frame_vector, inp_a, inp_b, frame_Leng);
        }else{
            ofs << "OPT: " << fault << endl;
            OPT(inp_itr, input_list, frame_vector, inp_a, inp_b, frame_Leng);
        }
        for(itr2 = frame_vector.begin(); itr2 != frame_vector.end(); itr2++){
            ofs << itr2->index << " " << itr2->pnum << " " << itr2->cnt << endl;
        }
    }
    
    ifs.close();
    ofs.close();
    return 0;
}


/*************************************************** 페이지 교체 알고리즘 ***************************************************/

/*-----------------------> FIFO 알고리즘 <-----------------------*/
void FIFO(vector<FRAME> f1, int inp_a, int inp_b, int turn){
    int i = 1;
    vector<FRAME>::iterator itr;
    for(itr = f1.begin(); itr != f1.end(); itr++){  // 벡터 내부에 교체하려는 프로세스와 일치하는 것 탐색
        if(itr->pnum == inp_a){
            if( i == turn){     // 입력받은 프로세스 번호와 동일한 프로세스 내에서 교체해야 하는 페이지 순서를 지키게 한다.
                itr->cnt = inp_b;
            }
            i++;
        }
    }
}



/*-----------------------> LRU 알고리즘 <-----------------------*/
void LRU(vector<SIZE>::iterator inp_itr, vector<SIZE> input_list, vector<FRAME> f1, int inp_a, int inp_b, int leng){
    vector<SIZE>::iterator itr;
    vector<FRAME>::iterator itr1;
    
    for(itr = inp_itr-1; itr != input_list.begin(); itr--){
        for(itr1 = f1.begin(); itr1 != f1.end(); itr1++){
            if(itr1->pnum == inp_a){
                if(itr->cnt == itr1->cnt){
                    itr1->valid = 1;
                    leng--;
                }
            }
        }
        if(leng == 1){
            for(itr1 = f1.begin(); itr1 != f1.end(); itr1++){
                if(itr1->valid != 1) itr1->cnt = inp_b;
            }
            break;
        }
    }
}



/*-----------------------> OPT 알고리즘 <-----------------------*/
void OPT(vector<SIZE>::iterator inp_itr, vector<SIZE> input_list, vector<FRAME> f1, int inp_a, int inp_b, int leng){
    vector<SIZE>::iterator itr;
    vector<FRAME>::iterator itr1;
    
    for(itr = inp_itr+1; itr != input_list.end(); itr++){
        for(itr1 = f1.begin(); itr1 != f1.end(); itr1++){
            if(itr1->pnum == inp_a){
                int a = itr1->cnt;
                if(itr->cnt == a){
                    itr1->valid = 1;
                    leng--;
                }
            }
        }
        if(leng == 1){
            for(itr1 = f1.begin(); itr1 != f1.end(); itr1++){
                if(itr1->valid != 1) itr1->cnt = inp_b;
            }
            break;
        }
    }
}
