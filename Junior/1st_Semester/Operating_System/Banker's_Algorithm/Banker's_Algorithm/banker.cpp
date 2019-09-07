#define MAX 50
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class banker{
private:
    int pn = 0, rn = 0, que_count = 0;
    string sen;
    int max[MAX][MAX] = {0}, alloc[MAX][MAX] = {0}, need[MAX][MAX] = {0}, avail[MAX] = {0}, total[MAX] = {0},
    temp[MAX] = {0}, work_alloc[MAX][MAX] = {0}, work_need[MAX][MAX] = {0}, work_avail[MAX] = {0};
    vector< int > sun, wait_q;
    
public:
    void execute();
    void request();
    bool safety_check();
    void enqueue();
    void release();
    void print_avail();
};

// File read
void banker::execute(){
    ifstream ifs;
    ofstream ofs;
    ifs.open("banker.inp");
    ofs.open("banker.out");
    
    ifs >> pn >> rn;
    for(int i = 0;i < rn;i++){
        ifs >> total[i];
    }
    // Max
    for(int i = 0;i < pn;i++){
        for(int j = 0;j < rn;j++){
            ifs >> max[i][j];
        }
    }
    // Allocation
    for(int i = 0;i < pn;i++){
        for(int j = 0;j < rn;j++){
            ifs >> alloc[i][j];
            
        }
    }
    // Available
    for(int i = 0;i < rn;i++){
        int a = 0;
        for(int j = 0;j < pn;j++){
            a += alloc[j][i];
        }
        avail[i] = total[i] - a;
    }
    // Need
    for(int i = 0;i < pn;i++){
        for(int j = 0;j < rn;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    do{
        ifs >> sen;
        
        if(sen == "request"){
            for(int i = 0;i < rn + 1;i++){      // request 정보 읽기
                ifs >> temp[i];
            }
            request();
        }else if(sen == "release"){
            for(int i = 0;i < rn + 1;i++){      // release 정보 읽기
                ifs >> temp[i];
            }
            release();
        }
    }while(sen != "quit");
    
    ifs.close();
    ofs.close();
}

// request 요청 처리
void banker::request(){
    // need와 available보다 request가 더 크면, 대기큐 삽입없이 이전 자원 그대로 출력.
    for(int i = 0;i < rn;i++){
        if(need[temp[0]][i] < temp[i + 1]){     // need보다 request가 큰 경우
            print_avail();
            break;
        }
        if(avail[i] < temp[i + 1]){             // available보다 request가 큰 경우
            print_avail();
            break;
        }
    }
    
    // 검사용으로 복사
    for(int i = 0;i < pn;i++){
        for(int j = 0;j < rn;j++){
            work_alloc[i][j] = alloc[i][j];
            work_need[i][j] = need[i][j];
        }
        work_avail[i] = avail[i];
    }
    
    // safe하면 변경된 avail 출력
    if(safety_check() == true){
        for(int j = 0;j < rn;j++){
            alloc[temp[0]][j] += temp[j + 1];
            need[temp[0]][j] -= temp[j + 1];
            avail[j] -= temp[j + 1];
        }
        print_avail();
        // unsafe하면 그대로 출력하고 대기 큐에 enqueue.
    }else{
        print_avail();
        enqueue();
    }
}

// request의 safety check
bool banker::safety_check(){
    bool finish[MAX] = {0};
    int count = 0;
    
    while(count < pn){
        // 모든 프로세스 완료하거나, unsafe하면 종료.
        // 매 차례마다 모든 프로세스를 검사하며
        // 하나라도 safe가 나오면 루프 반복, 하나도 없으면 루프 종료.
        bool flag = false;
        for(int i = 0;i < pn;i++){
            if(finish[i] == 0){
                // need가 가능한 프로세스 체크
                int j = 0;
                for(j = 0;j < rn;j++)
                    if(work_need[i][j] > work_avail[i])
                        break;
                // 가능한 프로세스의 할당된 자원 반환
                if(j == rn){
                    for(int k = 0;k < rn;k++){
                        work_avail[k] += work_alloc[i][k];
                    }
                    finish[i] = 1;
                    // 가능한 프로세스 찾아서 flag가 true.
                    flag = true;
                    count++;
                }
            }
        }
        // unsafe한 경우
        if(flag == false){
            return false;
        }
    }
    return true;
}

void banker::enqueue(){
    for(int i = 0;i < rn + 1;i++){
        wait_q.push_back(temp[i]);
        sun.push_back(temp[i]);
    }
    que_count++;
}

void banker::release(){
    int num = que_count;
    int vector_gap = que_count * (rn + 1);
    // release한 자원 avail에 할당
    for(int i = 0;i < rn;i++){
        avail[i] += temp[i + 1];
    }
    // wait queue가 비어있는 경우, 그대로 출력
    if(num == 0){
        print_avail();
    }else{
        // wait queue에 대기 중인 요청이 있는 경우 safety 검사
        for(int m = 1;m < num;m++){
            // queue에 들어간 요청 수만큼 반복
            // request 정보 배열에 저장
            for(int j = 0;j < rn;j++){
                temp[j] = wait_q[j + (m * vector_gap)];
            }
            /***********     여기부터 request 절차 시작     ***********/
            // need와 available보다 request가 더 크면, 건너뛴다.
            for(int i = 0;i < rn;i++){
                if(need[temp[0]][i] < temp[i + 1]){     // need보다 request가 큰 경우
                    break;
                }
                if(avail[i] < temp[i + 1]){             // available보다 request가 큰 경우
                    break;
                }
            }
            
            // 검사용으로 복사
            for(int i = 0;i < pn;i++){
                for(int j = 0;j < rn;j++){
                    work_alloc[i][j] = alloc[i][j];
                    work_need[i][j] = need[i][j];
                }
                work_avail[i] = avail[i];
            }
            
            // safe하면 변경된 avail 출력
            if(safety_check() == true){
                for(int j = 0;j < rn;j++){
                    alloc[temp[0]][j] += temp[j + 1];
                    need[temp[0]][j] -= temp[j + 1];
                    avail[j] -= temp[j + 1];
                }
                print_avail();
                /******** dequeue ********/
                sun.erase(sun.begin()+(m * vector_gap), sun.begin()+(m+1) * vector_gap);
            }
        }
    }
}


// 사용 가능 자원 출력
void banker::print_avail(){
    ofstream ofs;
    ofs.open("banker.out", ios::app);
    
    for(int i = 0;i < rn;i++){
        cout << avail[i] << " ";
        ofs << avail[i] << " ";
    }
    cout << endl;
    ofs << endl;
    ofs.close();
}

int main(void) {
    banker b1;
    b1.execute();
    
    return 0;
}
