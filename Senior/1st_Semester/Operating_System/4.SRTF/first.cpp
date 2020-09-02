#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


typedef struct _PROCESS {
    int pid;
    int arrTime;
    int bstTime;
    int originBst;
    int pcsEndTime;
    int tatTime;
    int wtgTime;
    bool flag;
}PROCESS;


PROCESS srtfArr[60];
PROCESS inpPCS; // 입력데이터의 프로세스 정보를 저장하기 위한 구조체 변수
int pcsCnt = 0;   // 입력으로 들어오는 프로세스 개수


void PCS_Sort();
void SJF_Sort();
void SRTFscheduling();



int main(void) {
    ifstream ifs ("srtf.inp");
    ofstream ofs ("srtf.out");
    
    int wtgSum = 0; // waiting time의 총합
    
    ifs >> pcsCnt;
    
    // 프로세스 정보 PROCESS형 배열에 입력
    for (int i = 0; i < pcsCnt; ++i) {
        ifs >> inpPCS.pid >> inpPCS.arrTime >> inpPCS.bstTime;
        inpPCS.originBst = inpPCS.bstTime;
        srtfArr[i] = inpPCS;
    }
    
    
    /******** 도착시간이 빠른 것부터 느린 것으로 정렬,
     동일한 도착시간은 pid가 작은 것 부터 큰 것으로 정렬 ********/
    PCS_Sort();
    
    SRTFscheduling();
    
    
    // 각 프로세스의 TAT(Turn Around Time) 기록
    for (int i = 0; i < pcsCnt; ++i) {
        srtfArr[i].tatTime = srtfArr[i].pcsEndTime - srtfArr[i].arrTime;
    }
    
    // 각 프로세스의 Waiting Time 기록
    // Waiting Time = Turn Around Time - CPU Time
    for (int i = 0; i < pcsCnt; ++i) {
        srtfArr[i].wtgTime = srtfArr[i].tatTime - srtfArr[i].originBst;
    }
    
    // waiting time의 총합 구하기
    for (int i = 0; i < pcsCnt; ++i) {
        wtgSum += srtfArr[i].wtgTime;
    }
    
    ofs << wtgSum << endl;
    
    ifs.close();
    ofs.close();
    
    return 0;
}




void PCS_Sort() {
    PROCESS tempP;
    for (int i = pcsCnt-1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (srtfArr[j].arrTime > srtfArr[j+1].arrTime) {    // 도착시간 오름차순
                tempP = srtfArr[j+1];
                srtfArr[j+1] = srtfArr[j];
                srtfArr[j] = tempP;
            }else if (srtfArr[j].arrTime == srtfArr[j+1].arrTime) { // 도착시간이 같을 때
                if (srtfArr[j].bstTime == srtfArr[j+1].bstTime) {
                    if (srtfArr[j].pid > srtfArr[j+1].pid) {
                        tempP = srtfArr[j+1];
                        srtfArr[j+1] = srtfArr[j];
                        srtfArr[j] = tempP;
                    }
                }else if (srtfArr[j].bstTime > srtfArr[j+1].bstTime) {
                    tempP = srtfArr[j+1];
                    srtfArr[j+1] = srtfArr[j];
                    srtfArr[j] = tempP;
                }
            }
        }
    }
}


void SJF_Sort() {
    PROCESS tempP;
    for (int i = pcsCnt-1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (srtfArr[j].bstTime > srtfArr[j+1].bstTime) {
                tempP = srtfArr[j+1];
                srtfArr[j+1] = srtfArr[j];
                srtfArr[j] = tempP;
            }else if (srtfArr[j].bstTime == srtfArr[j+1].bstTime && srtfArr[j].pid > srtfArr[j+1].pid) {
                tempP = srtfArr[j+1];
                srtfArr[j+1] = srtfArr[j];
                srtfArr[j] = tempP;
            }
        }
    }
}


void SRTFscheduling() {
    int minPcsID = 0;
    int temp_end = 0;
    int nowTime = 0;   // 프로세스 최종 종료 시각을 기록하기 위해 현재 시간을 저장
    
    nowTime = srtfArr[0].arrTime;   // 첫 프로세스 도착시간을 시작 시점으로 초기화
    
    for (int sec = 1; sec <= srtfArr[pcsCnt-1].arrTime; ++sec) {
        
        if (srtfArr[minPcsID].bstTime > 0) {
            srtfArr[minPcsID].bstTime -= 1;
        }
        
        for (int j = 0; srtfArr[j].arrTime <= sec; ++j) {
            temp_end = j;
        }
        
        if (srtfArr[minPcsID].bstTime == 0 && srtfArr[minPcsID].flag != true) {
            srtfArr[minPcsID].pcsEndTime = sec;
            srtfArr[minPcsID].flag = true;
        }
        
        for (int k = 0; k <= temp_end; ++k) {
            if (srtfArr[minPcsID].bstTime == 0 || srtfArr[minPcsID].bstTime > srtfArr[k].bstTime) {
                minPcsID = k;
            }else if (srtfArr[minPcsID].bstTime == srtfArr[k].bstTime) {
                minPcsID = srtfArr[minPcsID].pid > srtfArr[k].pid ? k : minPcsID;
            }
        }
        
    }
    
    nowTime = srtfArr[pcsCnt-1].arrTime;
    
    SJF_Sort();
    
    // 실행시간이 짧은 프로세스 순으로 차례차례 남은 처리
    for (int i = 0; i < pcsCnt; ++i) {
        if (srtfArr[i].bstTime != 0) {
            srtfArr[i].pcsEndTime = nowTime + srtfArr[i].bstTime;
            srtfArr[i].bstTime = 0;
            nowTime = srtfArr[i].pcsEndTime;
        }
    }
    
}
