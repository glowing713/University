#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Cpu{
    int pn;
    int arr;
    int bst;
};

bool comp_arr(const Cpu &a, const Cpu &b){
    if(a.arr < b.arr){
        return true;
    }
    else if(a.arr == b.arr){
        return a.pn < b.pn;
    }
    else{
        return false;
    }
}

bool comp_bst(const Cpu &a, const Cpu &b){
    return a.bst<b.bst;
}

int main(void){
    
    ifstream ifs;
    ofstream ofs;
    ifs.open("sjf.inp");
    ofs.open("sjf.out");
    
    int num = 0, total = 0, waiting = 0, go = 0, dest = 0;
    
    Cpu pn;
    vector<Cpu> v1;            //프로세스 정보 저장할 구조체 배열 생성
    vector<int> v2;
    
    ifs >> num;
    
    for(int i=0;i<num;i++){
        ifs >> pn.pn >> pn.arr >> pn.bst;
        v1.push_back(pn);
    }
    
    sort(v1.begin(),v1.end(),comp_arr);
    
    total += v1[0].bst;
    
    for(int i=1;i<v1.size();i++){
        if(v1[i].arr <= total){
            total += v1[i].bst;
            v2.push_back(i);
        }else{
            total = v1[i].arr + v1[i].bst;
        }
    }
    
    go = v2[0];
    dest = v2[v2.size()-1];
    
    sort(v1.begin()+go,v1.begin()+dest+1,comp_bst);
    
    total = v1[0].bst;
    for(int i=1;i<v1.size();i++){
        int j = 0, sum = 0;
        if(v1[i].arr < total){
            total += v1[i].bst;
        }else{
            total = v1[i].arr + v1[i].bst;
        }
        for(j=0;j<i;j++){
            sum += v1[j].bst;
        }
        if(v1[i].arr < total){
            waiting += (sum - v1[j].arr);
        }
    }
    
    ofs << waiting << endl;
    
    ifs.close();
    ofs.close();
    
    return 0;
}
