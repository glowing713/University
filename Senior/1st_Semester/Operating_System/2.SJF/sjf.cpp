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


PROCESS sjfArr[60];
PROCESS inpPCS; // 입력데이터의 프로세스 정보를 저장하기 위한 구조체 변수
int pcsCnt = 0;   // 입력으로 들어오는 프로세스 개수
long bstSum = 0;


bool BT_Compare(PROCESS p1, PROCESS p2) {
    if (p1.bstTime < p2.bstTime) {
        return true;
    }else if (p1.bstTime == p2.bstTime) {
        return p1.pid < p2.pid;
    }else {
        return false;
    }
}


bool Compare(PROCESS p1, PROCESS p2) {
    if (p1.arrTime < p2.arrTime) {
        return true;
    }else if (p1.arrTime == p2.arrTime) {
        return p1.pid < p2.pid;
    }else {
        return false;
    }
}


void SJFscheduling() {
    
    int k = 0;
    int srt_end = 0;
    sjfArr[0].wtgTime = 0;
    
    for (int i = 1; i < pcsCnt; ++i) {
        
        PROCESS *nowPcs = &sjfArr[i];
        
        for (int j = k; j < i; ++j) {
            PROCESS *tempPcs = &sjfArr[j];
            bstSum += tempPcs->bstTime;
        }
        
        if (bstSum + sjfArr[k].arrTime >= nowPcs->arrTime) {
            
            for (srt_end = i; srt_end < pcsCnt; ++srt_end) {
                if(sjfArr[srt_end].arrTime > bstSum + sjfArr[k].arrTime)
                    break;
            }
            
            sort(sjfArr + i, sjfArr + srt_end, BT_Compare);   // 레디큐에 들어온 모든 프로세스를 실행시간 순으로 오름차순 정렬
            
            sjfArr[i].wtgTime = bstSum + sjfArr[k].arrTime - sjfArr[i].arrTime; // 실행시간이 가장 작은 프로세스의 대기시간 처리
            
            sort(sjfArr + i + 1, sjfArr + pcsCnt, Compare); // 처리한 프로세스 다음 것부터 다시 도착시간 순으로 정렬
            
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
    ifs.open("sjf.inp");
    ofs.open("sjf.out");
    
    long wtgSum = 0; // waiting time의 총합
    
    ifs >> pcsCnt;
    
    // 프로세스 정보 PROCESS형 배열에 입력
    for (int i = 0; i < pcsCnt; ++i) {
        ifs >> inpPCS.pid >> inpPCS.arrTime >> inpPCS.bstTime;
        sjfArr[i] = inpPCS;
    }
    
    
    /******** 도착시간이 빠른 것부터 느린 것으로 정렬,
     동일한 도착시간은 pid가 작은 것 부터 큰 것으로 정렬 ********/
    sort(sjfArr, sjfArr + pcsCnt, Compare);
    
    SJFscheduling();
    
    for (int i = 0; i < pcsCnt; ++i) {
        cout << "(" << sjfArr[i].pid << ", " << sjfArr[i].arrTime << ", " << sjfArr[i].bstTime << ", " << sjfArr[i].wtgTime << ")" << endl;
    }
    
    // waiting time의 총합 구하기
    for (int i = 0; i < pcsCnt; ++i) {
        wtgSum += sjfArr[i].wtgTime;
    }
    
    ofs << wtgSum << endl;
    
    ifs.close();
    ofs.close();
    
    return 0;
}
