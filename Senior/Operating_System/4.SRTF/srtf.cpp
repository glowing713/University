#include <iostream>
#include <fstream>
using namespace std;


typedef struct _Process {
    int pid;
    int arrTime;
    int bstTime;
    int pcsEndTime;
    int wtgTime;
    int flag;
}Process;

int pcsCnt = 0;
Process srtfArr[60];


Process* GetPCS(Process *startPCS, int time) {
    Process* tempP;
    
    if(startPCS == NULL)
        tempP = &srtfArr[0];
    else
        tempP = startPCS;
    
    for(int i = 0; i < pcsCnt ; ++i) {
        if(srtfArr[i].arrTime <= time && srtfArr[i].bstTime !=0) {
            if(tempP->bstTime > srtfArr[i].bstTime || tempP->bstTime == 0)
                tempP = &srtfArr[i];
        }
    }
    
    if(tempP->arrTime > time)
        tempP = NULL;
    
    return tempP;
}

int Check() {
    for(int i = 0; i < pcsCnt ; ++i) {
        if(srtfArr[i].bstTime !=0)
            return 1;
    }
    return 0;
}


void PCS_Sort() {
    Process tempP;
    for(int i = pcsCnt - 1; i > 0; --i) {
        for(int j = 0; j < i; ++j) {
            if(srtfArr[j].arrTime > srtfArr[j+1].arrTime) {
                tempP = srtfArr[j+1];
                srtfArr[j+1] = srtfArr[j];
                srtfArr[j] = tempP;
            }
            else if(srtfArr[j].arrTime == srtfArr[j+1].arrTime && srtfArr[j].pid > srtfArr[j+1].pid) {
                tempP = srtfArr[j+1];
                srtfArr[j+1] = srtfArr[j];
                srtfArr[j] = tempP;
            }
        }
    }
}


int main() {
    int wtgSum = 0;
    
    Process* beginPCS = NULL;
    Process* tempP = NULL;
    
    ifstream ifs("srtf.inp");
    ofstream ofs("srtf.out");
    
    ifs >> pcsCnt;
    
    for(int i = 0; i < pcsCnt ; ++i) {
        ifs >> srtfArr[i].pid >> srtfArr[i].arrTime >> srtfArr[i].bstTime;
        srtfArr[i].pcsEndTime = 0;  srtfArr[i].wtgTime = 0; srtfArr[i].flag = 0;
    }
    
    PCS_Sort();
    
    for (int time = 0;;time++) {
        beginPCS = GetPCS(beginPCS, time);
        if(beginPCS == tempP)
            tempP = beginPCS;
        
        else {
            if(tempP != NULL) {
                tempP->pcsEndTime = time;
            }
            
            if(beginPCS->flag == 0) {
                beginPCS->flag = 1;
                beginPCS->wtgTime = time - beginPCS->arrTime;
                tempP = beginPCS;
            }
            else {
                beginPCS->wtgTime += (time - beginPCS->pcsEndTime);
                tempP = beginPCS;
            }
        }
        
        if(beginPCS == NULL){
            continue;
        }
        
        beginPCS->bstTime--;
        
        if(beginPCS->bstTime < 0){
            beginPCS->bstTime = 0;
        }
        
        if(Check() == 0){
            break;
        }
    }
    
    for(int i = 0; i < pcsCnt ; ++i) {
        wtgSum += srtfArr[i].wtgTime;
    }
    ofs << wtgSum << endl;
    
    ifs.close();
    ofs.close();
    
    return 0;
}
