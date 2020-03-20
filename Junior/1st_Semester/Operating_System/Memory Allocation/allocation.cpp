#define MAX 1000
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

/******************************* 메모리 내부에 삽입할 프로세스 정보 *******************************/
struct Proc{
    int start;  // 요청시각
    int pid;    // 프로세스 번호
    int size;   // 크기
    Proc(int start, int pid, int size):start(start), pid(pid), size(size){}
};


/*********************************** 사용자 정의 함수 목록 ***********************************/
void pOut(list<Proc> P, int index);     // 메모리에서 파라미터의 인덱스번호와 일치하는 프로세스 종료
void pIn(list<Proc> P, int size, int index, int time1, int time2, int time3);           // 메모리 잔량보다 작거나 같으면 삽입, 아니면 대기 큐에 삽입
void que_Out(list<Proc> P, list<Proc> W);     // 대기 큐에 삽입(enqueue)
void que_Insert(list<Proc> P, list<Proc> W);     // 대기 큐에서 현재 잔여 메모리 크기보다 작은 대기 프로세스 탐색 및 삽입(dequeue)



int main(void){
    /*************************************** 파일 입출력 실행 ***************************************/
    ifstream ifs;
    ofstream ofs;
    ifs.open("allocation.inp");
    ofs.open("allocation.out");
    /***************************************** 변수 선언 *****************************************/
    int cycle = 0;  // 입력파일 첫 줄의 반복문 돌릴 횟수 저장할 변수
    int input[MAX][4]={0};  // 입력파일의 (요청시각, 실행시간, 크기, 종료시각) 저장할 배열
    int output[MAX][3]={0};     // first, best, worst fit 기법에 따른 결과 각각 저장
    list<Proc> pList;   // 메모리 내부 구현 리스트
    list<Proc> waitQue;     // 대기 큐
    /**************************************** FILE READ ****************************************/
    ifs >> cycle;   // 파일 첫 줄 read
    for(int x = 0; x < cycle; x++){
        for(int y = 0; y < 3; y++){
            ifs >> input[x][y];    // input[][] 배열 읽어오기
        }
        input[x][3] = input[x][0] + input[x][1];    // input[][4]에 요청시각과 실행시간을 더해서 종료시각 저장
    }
    
    /**************************************** Allocation ****************************************/
    for(int i = 0; i < cycle; i++){         // PID 0부터 n-1까지 반복
        for(int j = 0; j < cycle; j++){         // 종료시각 사이클
            if(input[i][0] <= input[j][3]){         // P[i]의 요청시각보다 작거나 같은 종료시각이 있는지 탐색
                pOut(pList, input[j][0]);   // 그 프로세스 반환
                que_Insert(pList, waitQue);      // 대기큐에서 삽입 가능한 프로세스 탐색 및 삽입
            }
        }
        if(i != cycle){
            pIn(pList, input[i][2], i, output[i][0], output[i][1], output[i][2]);
        }else{
            break;
        }
        if(i == cycle){
            break;
        }
    }
    
    /*************************************** 파일 입출력 종료 ***************************************/
    ifs.close();
    ofs.close();
    return 0;
}


void pOut(list<Proc> P, int index){
    list<Proc>::iterator itr, itr_front, itr_back;
    
    for(itr=P.begin();itr!=P.end();itr++){
        if(itr->pid == index){
            itr->pid = -1;
            itr_front = ++itr;
            --itr;
            itr_back = --itr;
            ++itr;
        }
    }
    if(itr_back->pid == -1 && itr_front->pid == -1){
        itr_back->size += (itr->size + itr_front->size);
        P.erase(itr);
        P.erase(itr_front);
    }else if(itr_back->pid == -1 && itr->pid == -1){
        itr_back->size += itr->size;
        P.erase(itr);
    }else if(itr->pid == -1 && itr_front->pid == -1){
        itr->size += itr_front->size;
        P.erase(itr_front);
    }
}


void pIn(list<Proc> P, int size, int index, int time1, int time2, int time3){
    list<Proc>::iterator itr, itr_back, itr_front;
    
    for(itr=P.begin();itr!=P.end();itr++){
        if(itr->pid == -1 && size <= itr->size){
            Proc p1(itr->start, index, size);
            Proc p2(itr_back->start+itr_back->size, -1, itr->size-size);
            itr_back = --itr;
            P.insert(itr_back, p1);
            P.erase(itr);
            P.insert(itr, p2);
            time1 = itr_back->start;
            break;
        }
    }
}
