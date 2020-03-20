#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct Cpu{
    int pn;
    int arr;
    int burst;
    int wait;
};

bool CompareArr(const Cpu& a, const Cpu& b){
    return a.arr < b.arr;
}

bool ComparePn(const Cpu& a, const Cpu& b){
    return a.pn < b.pn;
}

void swap(int a, int b){
    int temp=a;
    b=temp;
    a=b;
}

int main(void) {
    ifstream ifs;
    ofstream ofs;
    ifs.open("/Users/leesunhwan/Downloads/Coding/Xcode/2019 3학년 1학기/OS/FCFS/FCFS/fcfs.inp.txt");
    ofs.open("/Users/leesunhwan/Downloads/Coding/Xcode/2019 3학년 1학기/OS/FCFS/FCFS/fcfs.out.txt");
    
    int num = 0, i = 0, j = 0, least = 0;
    int result = 0;

    ifs >> num;
    
    struct Cpu pn[num];
    vector<Cpu> v1;
    
    for(i=0;i<num;i++){
        for(j=0;j<3;j++){
            ifs >> pn[i].pn >> pn[i].arr >> pn[i].burst;        //구조체에 프로세스 정보 입력
        }
    }
    
    for(i=0;i<num;i++){                                     //벡터에 각 프로세스 입력
        v1.push_back(pn[i]);
    }
    
    sort(v1.begin(), v1.end(), CompareArr);                 //도착시간에 따라 오름차순 정렬
    
    for(i=0;i<num-1;i++){
        for(j=0;j<num;j++){
            least = pn[i].pn;
            if(pn[i].arr == pn[j].arr){
                if(pn[i].pn > pn[j].pn){
                    least = pn[j].pn;
                }
            }
        }
        if(least != pn[i].pn){
            swap(pn[i].pn, least);
        }
    }
    
    pn[0].wait = pn[0].arr;
    for(i=1;i<num;i++){
        int bst_sum = 0;
        for(j=0;j<i;j++){
            bst_sum+=pn[i].burst;
        }
        pn[i].wait = bst_sum - pn[i].arr;
    }
    
    for(i=0;i<num;i++){
        result = pn[i].wait;
    }
    
    ofs << result;
    
    ifs.close();
    ofs.close();
    
    return 0;
}
