#include <cstdio>
#include <deque>
#define MAX 1000000000
using namespace std;


/*
   Breadth First Search
                        */
int min_path_finder(const int &start, const int &dest, const int &k, int (&map)[11][11]) {
    int min_dist[11][11] = {0, };
    int cnt_path[11][11] = {0, };
    int strt_row = 0, strt_col = 0;
    int dest_row = 0, dest_col = 0;
    deque<pair<int, int>> q;
    
    // 상, 하, 좌, 우
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // find starting point row, col
    strt_row = start / 10;  strt_col = start % 10;
    // find destination point row, col
    dest_row = dest / 10;  dest_col = dest % 10;
    
    // 모든 거리가 10억이라고 가정 (최소 거리를 찾으면 줄일 것임)
    fill(&min_dist[0][0], &min_dist[0][0] + 121, MAX);
    min_dist[strt_row][strt_col] = 0;
    cnt_path[strt_row][strt_col] = 1;
    
    q.push_back(make_pair(strt_row, strt_col));
    // 시작점은 지날 수 없다고 표기하려고 -1로 설정
    map[strt_row][strt_col] = -1;
    
    
    while (!q.empty()) {
        int now_row = q.front().first;
        int now_col = q.front().second;
        q.pop_front();
        
        for (int i = 0; i < 4; ++i) {
            int new_row = now_row + dx[i];  int new_col = now_col + dy[i];
            
            /* 현재 위치에서 네 방향으로 움직일 때, 벽이 아니면서 범위 내에 있어야 한다. */
            if (new_row >= min(strt_row, dest_row) &&  new_row <= max(strt_row, dest_row) && new_col >= min(strt_col, dest_col) && new_col <= max(strt_col, dest_col) && map[new_row][new_col] != -1) {
                
                if (min_dist[new_row][new_col] > min_dist[now_row][now_col] + 1) {
                    q.push_back(make_pair(new_row, new_col));
                    min_dist[new_row][new_col] = min_dist[now_row][now_col] + 1;
                    cnt_path[new_row][new_col] = cnt_path[now_row][now_col];
                }else if (min_dist[new_row][new_col] == min_dist[now_row][now_col] + 1)
                    cnt_path[new_row][new_col] += cnt_path[now_row][now_col];
                
            }else {
                continue;
            }
        }
    }
    
    
    return cnt_path[dest_row][dest_col];
}




int main() {
    FILE* ifs;
    FILE* ofs;
    ifs = fopen("path.inp", "rt");
    ofs = fopen("path.out", "wt");

    int map[11][11] = {0, };
    int start = 0, dest = 0, k = 0;
    
    fscanf(ifs, "%d %d %d", &start, &dest, &k);
    
    // set blocked room as -1
    for (int i = 0; i < k; ++i) {
        int temp = 0;
        fscanf(ifs, "%d", &temp);
        // blocked room
        map[temp / 10][temp % 10] = -1;
    }
    
    
    fprintf(ofs, "%d", min_path_finder(start, dest, k, map));

    fclose(ifs);
    fclose(ofs);

    return 0;
}
