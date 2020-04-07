#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


typedef struct PROCESS {
    int pid;
    long arrTime;
    long bstTime;
    long cplTime;
    long wtgTime;
}PROCESS;


PROCESS fcfsArr[60];
PROCESS inpPCS;
int pcsCnt = 0;   // 입력으로 들어오는 프로세스 개수
long timeEdge = 0;   // cpu 스케줄링 하면서 현재 시간을 기록
long wtgSum = 0; // waiting time의 총합



bool Compare(PROCESS p1, PROCESS p2) {
    if (p1.arrTime < p2.arrTime) {
        return true;
    }else if (p1.arrTime == p2.arrTime) {
        return p1.pid < p2.pid;
    }else {
        return false;
    }
}


void FCFSscheduling() {
    // 첫 번째 프로세스의 완료시간과 waiting time 설정
    fcfsArr[0].cplTime = fcfsArr[0].arrTime + fcfsArr[0].bstTime;
    fcfsArr[0].wtgTime = 0;
    timeEdge = fcfsArr[0].cplTime;
    
    
    // 두 번째 프로세스부터 처리시작
    for (int i = 1; i < pcsCnt; ++i) {
        
        PROCESS* nowProcess = &fcfsArr[i];
        
        //        if (nowProcess->arrTime < timeEdge) {
        //            nowProcess->cplTime = timeEdge + nowProcess->bstTime;
        //            nowProcess->wtgTime = timeEdge - nowProcess->arrTime;
        //            timeEdge = nowProcess->cplTime;
        //        } else if (nowProcess->arrTime == timeEdge) {
        //            nowProcess->cplTime = nowProcess->arrTime + nowProcess->bstTime;
        //            nowProcess->wtgTime = 0;
        //            timeEdge = nowProcess->cplTime;
        //        } else {
        //            nowProcess->cplTime = nowProcess->arrTime + nowProcess->bstTime;
        //            nowProcess->wtgTime = 0;
        //            timeEdge = nowProcess->cplTime;
        //        }
        if (nowProcess->arrTime < timeEdge) {
            nowProcess->cplTime = timeEdge + nowProcess->bstTime;
            nowProcess->wtgTime = timeEdge - nowProcess->arrTime;
            timeEdge = nowProcess->cplTime;
        } else {
            nowProcess->cplTime = nowProcess->arrTime + nowProcess->bstTime;
            nowProcess->wtgTime = 0;
            timeEdge = nowProcess->cplTime;
        }
        
    }
}



int main() {
    ifstream ifs;
    ofstream ofs;
    ifs.open("fcfs.inp");
    ofs.open("fcfs.out");
    
    ifs >> pcsCnt;
    
    // 프로세스 정보 PROCESS형 배열에 입력
    for (int i = 0; i < pcsCnt; ++i) {
        ifs >> inpPCS.pid >> inpPCS.arrTime >> inpPCS.bstTime;
        fcfsArr[i] = inpPCS;
    }
    
    /******** 도착시간이 빠른 것부터 느린 것으로 정렬,
     동일한 도착시간은 pid가 작은 것 부터 큰 것으로 정렬 ********/
    sort(fcfsArr, fcfsArr + pcsCnt, Compare);
    
    FCFSscheduling();
    
    // waiting time의 총합 구하기
    for (int i = 0; i < pcsCnt; ++i) {
        wtgSum += fcfsArr[i].wtgTime;
    }
    
    ofs << wtgSum << endl;
    
    ifs.close();
    ofs.close();
    
    return 0;
}
