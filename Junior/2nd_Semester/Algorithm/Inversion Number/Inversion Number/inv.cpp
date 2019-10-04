#define MAX 100010
#include <iostream>
#include <fstream>

using namespace std;

int sorted_temp[MAX]; // 정렬된 배열을 담을 임시변수(다시 원래 배열에 복사할)
long long invCnt = 0; // inversion 횟수


void merge(int list[], int left, int mid, int right);

void merge_sort(int list[], int left, int right);

int main(void) {
    ifstream ifs;
    ofstream ofs;
    ifs.open("inv.inp");
    ofs.open("inv.out");

    int testCase = 0, compNum = 0; // 테스트 케이스 수, 수열 원소의 개수
    int list[MAX] = {0,};   // 수열 원소를 담는 배열
    
    
    ifs >> testCase;
    // 테스트 케이스 수대로 반복
    for(int i = 0; i < testCase; ++i){
        invCnt = 0;
        ifs >> compNum;
        // 수열 원소의 개수만큼 반복
        for(int j = 0; j < compNum; ++j){
            ifs >> list[j];
        }

        merge_sort(list, 0, compNum - 1);

        ofs << invCnt << endl;
    }
    
    ifs.close();
    ofs.close();
    return 0;
}


// 분할 정복에서 원소가 하나일때까지 분할후 역으로 합병. 이진트리 후위순회과 비슷하다.
void merge_sort(int list[], int left, int right){
    
    if(left < right){
        int mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}

void merge(int list[], int left, int mid, int right){
    int i = left, j = mid+1, k = left;
    
    // 작은 원소부터 임시배열에 삽입
    while(i<=mid && j<=right){
        if(list[i] <= list[j]){
            sorted_temp[k++] = list[i++];
        }else{
            invCnt += (mid - i + 1);
            sorted_temp[k++] = list[j++];
        }
    }

    // 한쪽이 끝이나고 남은배열도 전부 삽입
    if(i > mid){    // 왼쪽 배열이 전부 삽입(오른쪽이 남았다)
        for(int l = j; l <= right; ++l){
            sorted_temp[k++] = list[l];
        }
    }else{
        for(int l = i; l <= mid; ++l){
            sorted_temp[k++] = list[l];
        }
    }
    
    //정렬된 임시배열을 원래 배열에 삽입
    for(int l = left; l <= right; ++l){
        list[l] = sorted_temp[l];
    }
}
