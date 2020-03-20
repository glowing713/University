#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef struct LIGHT{
    int num, l, r, distance;
}LIGHT;

typedef struct STREET{
    int l, r;
}STREET;

bool compare(LIGHT a, LIGHT b){
    return a.l < b.l;
}

int main(){
    ifstream ifs;
    ofstream ofs;
    ifs.open("light.inp");
    ofs.open("light.out");
    
    LIGHT light_Inp;
    STREET street_Inp;
    vector<LIGHT> light;
    vector<STREET> street;
    int N = 0, K = 0, l = 0, r = 0 ,cnt = 0;
    
    ifs >> N;
    
    for(int i = 0; i < N; ++i){
        light_Inp.num = i+1;
        ifs >> light_Inp.l >> light_Inp.r;
        light_Inp.distance = light_Inp.r - light_Inp.l;
        light.push_back(light_Inp);
    }
    
    sort(light.begin(), light.end(), compare);
    
    ifs >> K;
    
    for(int num = 0; num < K; ++num){
        
        int max_dis = 0, index = 0;
        int begin = 0, end = 0;
        ifs >> l >> r;
        
        for(int i = 0; i < N; ++i){
            if(l >= r){
                ofs << cnt << endl;;
                cnt = 0;
                break;
            }
            
            while(true){
                if(l >= light[i].l && l < light[i].r){
                    break;
                }
                ++i;
            }
                        
            for(int j = i; j < N; ++j){
                
                if(l < light[j].l){
                    i = j;
                    break;
                }
                
                // 범위 내에서 가장 거리가 긴 것을 찾는다.
                if(light[j].r > max_dis){
                    max_dis = light[j].r;
                    index = j;
                }
            }
            
            
            if(max_dis == l){
                ofs << -1 << endl;
                index = 0;
                cnt = 0;
                break;
            }
            l = max_dis;
            ++cnt;
            if(l >= r){
                ofs << cnt << endl;
                index = 0;
                cnt = 0;
                break;
            }
        }
    }
    
    
    ifs.close();
    ofs.close();
    
    return 0;
}
