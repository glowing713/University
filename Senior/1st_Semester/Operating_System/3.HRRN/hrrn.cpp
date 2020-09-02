#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


typedef struct _PROCESS {
    int pid;
    long arrTime;
    long bstTime;
    double priority;
    long wtgTime;
}PROCESS;


PROCESS hrrnArr[60];
PROCESS inpPCS; // 입력데이터의 프로세스 정보를 저장하기 위한 구조체 변수
int pcsCnt = 0;   // 입력으로 들어오는 프로세스 개수
long bstSum = 0;


bool PRIORITY_Compare(PROCESS p1, PROCESS p2) {
    if (p1.priority > p2.priority) {
        return true;
    }else if (p1.priority == p2.priority) {
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


void hrrnscheduling() {
    
    int k = 0;
    int srt_end = 0;
    hrrnArr[0].wtgTime = 0;
    
    for (int i = 1; i < pcsCnt; ++i) {
        
        PROCESS *nowPcs = &hrrnArr[i];
        
        for (int j = k; j < i; ++j) {
            PROCESS *tempPcs = &hrrnArr[j];
            bstSum += tempPcs->bstTime;
        }
        
        if (bstSum + hrrnArr[k].arrTime >= nowPcs->arrTime) {
            
            for (srt_end = i; srt_end < pcsCnt; ++srt_end) {
                if(hrrnArr[srt_end].arrTime > bstSum + hrrnArr[k].arrTime)
                    break;
            }
            
            for (int l = i; l < srt_end; ++l) {
                long tempWT = bstSum + hrrnArr[k].arrTime - hrrnArr[l].arrTime;
                long tempBT = hrrnArr[l].bstTime;
                hrrnArr[l].priority = (double)(tempWT + tempBT)/tempBT; // 우선순위 계산
            }
            
            sort(hrrnArr + i, hrrnArr + srt_end, PRIORITY_Compare);   // 레디큐에 들어온 모든 프로세스를 우선순위 순으로 오름차순 정렬
            
            hrrnArr[i].wtgTime = bstSum + hrrnArr[k].arrTime - hrrnArr[i].arrTime; // 우선순위가 가장 높은 프로세스의 대기시간 처리
            
            sort(hrrnArr + i + 1, hrrnArr + pcsCnt, Compare); // 처리한 프로세스 다음 것부터 다시 도착시간 순으로 정렬
            
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
    ifs.open("hrrn.inp");
    ofs.open("hrrn.out");
    
    long wtgSum = 0; // waiting time의 총합
    
    ifs >> pcsCnt;
    
    // 프로세스 정보 PROCESS형 배열에 입력
    for (int i = 0; i < pcsCnt; ++i) {
        ifs >> inpPCS.pid >> inpPCS.arrTime >> inpPCS.bstTime;
        hrrnArr[i] = inpPCS;
    }
    
    
    /******** 도착시간이 빠른 것부터 느린 것으로 정렬,
     동일한 도착시간은 pid가 작은 것 부터 큰 것으로 정렬 ********/
    sort(hrrnArr, hrrnArr + pcsCnt, Compare);
    
    hrrnscheduling();
    
    for (int i = 0; i < pcsCnt; ++i) {
        cout << "(" << hrrnArr[i].pid << ", " << hrrnArr[i].arrTime << ", " << hrrnArr[i].bstTime << ", " << hrrnArr[i].wtgTime << ")" << endl;
    }
    
    // waiting time의 총합 구하기
    for (int i = 0; i < pcsCnt; ++i) {
        wtgSum += hrrnArr[i].wtgTime;
    }
    
    ofs << wtgSum << endl;
    
    ifs.close();
    ofs.close();
    
    return 0;
}
