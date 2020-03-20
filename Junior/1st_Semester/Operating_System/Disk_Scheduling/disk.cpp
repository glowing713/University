#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>
using namespace std;

typedef struct{
    int time = 0;
    int pos = 0;
}Ret;




Ret FCFS(int arr[][2], int serv){
    Ret r1;
    
    r1.time = arr[0][0] + arr[0][1] + serv;
    r1.pos = arr[0][1];
    
    for(int i = 1; i < 110 && arr[i][0] != -1; i++){
        if(arr[i][0] <= r1.time){
            r1.time += abs(arr[i][1] - arr[i-1][1]) + serv;
            r1.pos = arr[i][1];
        }else{
            r1.time = arr[i][0] + abs(arr[i][1] - arr[i-1][1]) + serv;
            r1.pos = arr[i][1];
        }
    }
    
    return r1;
};





Ret SSTF(int arr[][2], int serv){
    bool flag = false;
    int num = 9999;
    Ret temp, r2;
    list<Ret> list1;
    list<Ret>::iterator itr, min;
    int array[110][2] = {0,};
    
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110 && arr[j][0] != -1; j++){
            if(arr[j][0] <= r2.time){
                temp.time = arr[j][0];
                temp.pos = arr[j][1];
                list1.push_back(temp);
            }
        }//현재시간보다 작거나 같은 디스크 모두 인큐
        
        for(itr = list1.begin(); itr != list1.end(); itr++){
            if(abs(r2.pos - itr->pos) < num){
                num = abs(r2.pos - itr->pos);
                min = itr;
            }
        }//차이가 최소인 항목 찾기
        
        array[i][0] = min->time;
        array[i][1] = min->pos;
        i++;
    }
    
    
    return FCFS(array, serv);
};




//Ret LOOK(int arr[][2], int serv){
//
//};




int main(void) {
    Ret result;
    string type;
    int temp = 0;
    int serv = 0, time = 0, pos = 0, a = 0, b = 0;
    int arr[110][2] = {0,};
    ifstream ifs;
    ofstream ofs;
    ifs.open("/Users/leesunhwan/Downloads/Coding/Xcode/Disk_Scheduling/Disk_Scheduling/disk.inp.txt");
    ofs.open("/Users/leesunhwan/Downloads/Coding/Xcode/Disk_Scheduling/Disk_Scheduling/disk.out.txt");
    
    ifs >> type >> serv;
    
    while(!ifs.eof()){
        ifs >> a >> b;
        arr[temp][0] = a;
        arr[temp][1] = b;
        
        temp++;
    }
    
    if(type == "FCFS"){
        result = FCFS(arr, serv);
    }else if(type == "SSTF"){
        result = SSTF(arr, serv);
    }else if(type == "LOOK"){
        //        result = LOOK(arr, serv);
    }
    
    ofs << result.time << " " << result.pos << endl;
    
    ifs.close();
    ofs.close();
    
    return 0;
}
