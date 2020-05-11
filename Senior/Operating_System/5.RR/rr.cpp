#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _PROCESS {
    int pid;
    int time;
}PROCESS;

void pcsSort(vector<vector<int>> &vec, const int vecSize) {
    for (int i = vecSize; i > 1; --i) {
        for (int j = 1; j < i; ++j) {
            if (vec[j][0] > vec[j+1][0]) {  // 도착 순서대로
                swap(vec[j], vec[j+1]);
            }else if (vec[j][0] == vec[j+1][0]) {   // 도착 시점이 같다면
                if (vec[j][108] > vec[j+1][108]) {    // 우선순위 높은(숫자작은) 프로세스가 우선
                    swap(vec[j], vec[j+1]);
                }else if (vec[j][108] == vec[j+1][108]){
                    if (vec[j][109] > vec[j+1][109]) {  // 우선순위 같으면 프로세스 번호 순으로
                        swap(vec[j], vec[j+1]);
                    }
                }
            }
        }
    }
}



int main() {
    ifstream ifs("rr.inp");
    ofstream ofs("rr.out");
    vector<vector<int>> pcsInpVec (110, vector<int>(110, 0));  // 프로세스 cpu, i/o 시간 저장
    queue<PROCESS> readyQueue;  // 대기큐
    PROCESS tempP;
    int pcsCnt = 0, timeSlice = 0, nowTime = 0; // 입력파일의 프로세스 개수, 타임슬라이스, 현재시각
    int pcsTimeCnt[110] = {0, };    // 프로세스 cpu,i/o 시간 개수
    int isExist[110] = {0, };   // ready queue에 들어갔는지 여부
    int index[110] = {0, }; // 각 프로세스의 cpu,i/o 벡터의 어디에 위치하는지
    
    int startTime[110] = {0, }; // 각 프로세스의 시작 시각
    int endTime[110] = {0, }; // 각 프로세스의 종료 시각
    
    
    ifs >> pcsCnt >> timeSlice;
    
    /******************** 데이터 입력받기 ********************/
    for (int i = 1; i <= pcsCnt; ++i) {
        //        int t_arrTime, t_pcsTimeCnt;
        ifs >> startTime[i] >> pcsTimeCnt[i];  // 각 프로세스 도착시간/ cpu,i/o 시간 입력 개수
        pcsInpVec[i][0] = startTime[i];    // 프로세스 벡터의 첫 원소는 프로세스 도착 시간
        //        pcsTimeCnt[i] = t_pcsTimeCnt;   // pcsTimeCnt[i]는 입력으로 받은 프로세스 cpu, i/o 시간 개수 저장
        pcsInpVec[i][108] = 1; // 실행된 적이 있는 지를 체크
        pcsInpVec[i][109] = i;  // 프로세스 벡터의 마지막 원소는 프로세스 번호
        
        for (int j = 1; j <= pcsTimeCnt[i]; ++j) {
            ifs >> pcsInpVec[i][j];
        }
        index[i] = 1;   // i번 프로세스의 프로세스 벡터 위치
    }
    
    /******************** 처리하기 ********************/
    while (1) {
        // 우선순위 높은(숫자작은) 순으로 오름차순 정렬
        pcsSort(pcsInpVec, pcsCnt);
        
        // 현재시간을 기준으로 들어온 프로세스 대기 큐에 Push
        for (int i = 1; i <= pcsCnt; ++i) {
            int t_Pid = pcsInpVec[i][109];  // i행의 프로세스가 t_Pid 번이라는 것.
            int t_Col = index[t_Pid];   // t_Pid번 프로세스 벡터에 몇 번째 작업인지
            if (pcsInpVec[i][0] <= nowTime && isExist[t_Pid] != 1) {    // 프로세스 도착시간이 현재 시각보다 이전이고, 대기 큐에 없다면
                if (index[t_Pid] <= pcsTimeCnt[t_Pid]) {    // 아직 프로세스 작업도 남아있다면, Push
                    tempP.pid = t_Pid; tempP.time = pcsInpVec[i][t_Col];  // 프로세스 번호와 cpu시간을 담은 구조체
                    readyQueue.push(tempP);
                    pcsInpVec[i][108] = 1;
                    isExist[t_Pid] = 1; // 현재 프로세스가 대기 큐에 존재한다는 체크
                }
            }
        }
        
        //################# 대기 큐의 가장 오래된 프로세스부터 처리 #################//
        if (!readyQueue.empty()) {
            //********************* 대기 큐가 차 있는 경우 *********************//
            if (readyQueue.front().time > timeSlice) {  // 프로세스의 cpu 시간이 현재시간보다 크다면
                readyQueue.front().time -= timeSlice;   // timeslice 만큼 시간 감소
                nowTime += timeSlice;   // 현재 시간에 timeslice 만큼 증가
                // 현재시간을 기준으로 들어온 프로세스 대기 큐에 Push
                for (int i = 1; i <= pcsCnt; ++i) {
                    int t_Pid = pcsInpVec[i][109];
                    int t_Col = index[t_Pid];
                    if (pcsInpVec[i][0] <= nowTime && isExist[t_Pid] != 1) {    // 프로세스 도착시간이 현재 시각보다 이전이고, 대기 큐에 없다면 Push
                        if (index[t_Pid] <= pcsTimeCnt[t_Pid]) {    // 아직 프로세스 작업이 남아있는 것만, Push
                        tempP.pid = t_Pid; tempP.time = pcsInpVec[i][t_Col];  // 프로세스 번호와 cpu시간을 담은 구조체
                        readyQueue.push(tempP);
                        isExist[t_Pid] = 1; // 현재 프로세스가 대기 큐에 존재한다는 체크
                        }
                    }
                }
                tempP = readyQueue.front(); // 다시 큐의 맨 뒤로 Push
                readyQueue.pop();
                readyQueue.push(tempP);
            }else {                                     // 프로세스의 cpu 시간이 timeslice보다 작거나 같다면
                int t_pid = 0;
                tempP = readyQueue.front();
                nowTime += tempP.time;  // 프로세스의 남은 cpu 시간만큼 현재시간 증가
                readyQueue.pop();       // 대기 큐에서 Pop하고 isExist 배열에 없다고 체크
                isExist[tempP.pid] = 0;
                for (int i = 1; i <= pcsCnt; ++i) {
                    if (pcsInpVec[i][109] == tempP.pid) t_pid = i;  // 프로세스 2차원 벡터는 sort해서 행이 계속해서 바뀌므로 109번째 열에 저장된 pid와 일치하는 행을 찾는다
                }
                pcsInpVec[t_pid][0]  = nowTime + pcsInpVec[t_pid][index[tempP.pid] + 1];    // 현재시간에 i/o시간을 더한 이후가 다음 도착시간
                pcsInpVec[t_pid][108] = 2;  // i/o 끝난 이후에는 우선순위가 2
                index[tempP.pid] += 2;  // 다음 cpu시간을 가리킴
                // 프로세스 벡터의 인덱스가 입력 개수를 넘어갔다면 프로세스가 끝이라는 것. 종료시각 기록
                if (index[tempP.pid] > pcsTimeCnt[tempP.pid]){
                    endTime[tempP.pid] = nowTime;
                }
            }
        }else {
            //********************* 대기 큐가 비어있는 경우 *********************//
            bool t_Flag = false;
            int t_pid = 0;
            
            // 대기 큐가 비어있는데, 처리안한 프로세스는 없는 지 체크
            for (int i = 1; i <= pcsCnt; ++i) {
                t_pid = pcsInpVec[i][109];
                if (index[t_pid] <= pcsTimeCnt[t_pid]) {    // 아직 도착하지는 않았지만 처리할 작업이 남은 프로세스를 찾는 작업
                    nowTime = pcsInpVec[i][0];
                    t_Flag = true;
                    break;
                }
            }
            
            if (!t_Flag) {
                cout << "더 이상 처리할 프로세스가 없어 작업 종료\n";
                break;
            }
        }
    }
    
    
    /******************** 프로세스 대기시간 계산 (WT = TAT - BT) ********************/
    for (int i = 1; i <= pcsCnt; ++i) {
        endTime[i] -= startTime[i]; // Turn Around Time
        int t_Pid = pcsInpVec[i][109];  // i행의 프로세스가 t_Pid 번이라는 것.
        for (int j = 1; j <= pcsTimeCnt[t_Pid]; ++j) {
            endTime[t_Pid] -= pcsInpVec[i][j];  // 프로세스 TAT에서 실행시간을 빼는 작업
        }
    }
    
    for (int i = 1; i <= pcsCnt; ++i) {
        ofs << i << " " << endTime[i] << '\n';
    }
    
    ifs.close();
    ofs.close();
    return 0;
}
