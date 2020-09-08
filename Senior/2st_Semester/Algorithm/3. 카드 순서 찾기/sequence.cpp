#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;


int cnt = 0;
deque<int> mixed_list;
int order[1001] = {0, };
deque<int> original_list;


void sequence() {
    for (int i = cnt; i > 0; --i) {
        // "sth" is n th big number in the rest of the ordered list
        int n = order[i];
        // "sth" is n th number of remaining ordered list
        int nthNum = mixed_list[n];
        original_list.push_front(nthNum);
        // pop the number
        mixed_list.erase(mixed_list.begin() + n);
    }
}


int main() {
    FILE* ifs;
    FILE* ofs;
    ifs = fopen("sequence.inp", "rt");
    ofs = fopen("sequence.out", "wt");

    fscanf(ifs, "%d", &cnt);    // count of numbers
    
    // mixed number list
    for (int i = 1; i <= cnt; ++i) {
        int temp = 0;
        fscanf(ifs, "%d", &temp);
        mixed_list.push_back(temp);
    }
    // order mixed number list by ascend
    sort(mixed_list.begin(), mixed_list.end());
    // number order list
    for (int i = 1; i <= cnt; ++i) {
        fscanf(ifs, "%d", &order[i]);
    }
    
    // fill original_list
    sequence();
    
    // print original_list
    for (int i = 0; i < original_list.size() - 1; ++i) {
        fprintf(ofs, "%d\n", original_list[i]);
    }
    fprintf(ofs, "%d", original_list[cnt - 1]);
    

    fclose(ifs);
    fclose(ofs);

    return 0;
}
