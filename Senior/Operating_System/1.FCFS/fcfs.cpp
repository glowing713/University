#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


typedef struct _PROCESS {
    int pid;
    long arrTime;
    long bstTime;
    long wtgTime;
}PROCESS;


PROCESS fcfsArr[60];
PROCESS inpPCS; // 입력데이터의 프로세스 정보를 저장하기 위한 구조체 변수
int pcsCnt = 0;   // 입력으로 들어오는 프로세스 개수



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
    
    int k = 0;
    long bstSum = 0;
    fcfsArr[0].wtgTime = 0;
    
    for (int i = 1; i < pcsCnt; ++i) {
        
        PROCESS *nowPcs = &fcfsArr[i];
        
        for (int j = k; j < i; ++j) {
            PROCESS *tempPcs = &fcfsArr[j];
            bstSum += tempPcs->bstTime;
        }
        
        if (bstSum + fcfsArr[k].arrTime > nowPcs->arrTime) {
            nowPcs->wtgTime = bstSum + fcfsArr[k].arrTime - nowPcs->arrTime;
        } else {
            k = i;
            nowPcs->wtgTime = 0;
        }
        
        bstSum = 0;
    }
    
}



int main() {
    ifstream ifs;
    ofstream ofs;
    ifs.open("fcfs.inp");
    ofs.open("fcfs.out");
    
    long wtgSum = 0; // waiting time의 총합
    
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
    
//    for (int i = 0; i < pcsCnt; ++i) {
//        cout << "(" << fcfsArr[i].pid << ", " << fcfsArr[i].arrTime << ", " << fcfsArr[i].bstTime << ", " << fcfsArr[i].wtgTime << ")" << endl;
//    }
    
    // waiting time의 총합 구하기
    for (int i = 0; i < pcsCnt; ++i) {
        wtgSum += fcfsArr[i].wtgTime;
    }
    
    ofs << wtgSum << endl;
    
    ifs.close();
    ofs.close();
    
    return 0;
}
