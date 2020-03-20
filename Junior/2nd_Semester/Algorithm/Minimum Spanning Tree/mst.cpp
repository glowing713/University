#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>


using namespace std;

int parent[10010];
int sum = 0;


class Node{
public:
    int source, dest, weight, index;
    Node(int source, int dest, int weight, int index){
        this->source = source;
        this->dest = dest;
        this->weight = weight;
        this->index = index;
    }
};

// 노드의 weight를 기준으로 벡터 오름차순하기 위한 연산자 오버로딩
bool operator <(const Node &a, const Node &b){
    return a.weight < b.weight;
}

// 부모노드가 몇번인지 리턴
int getParent(int x){
    while(parent[x] != x){
        x = parent[x];
    }
    return x;
}

// 두 노드의 부모가 같으면 true, 다르면 false
bool sameParent(int x, int y){
    x = getParent(x);
    y = getParent(y);
    if(x == y) return true;
    else return false;
}

// 두 부모노드가 같으면 합친다.
void Union(int x, int y){
    x = getParent(x);
    y = getParent(y);
    
    if(x == y) return;
    if(x < y) parent[y] = x;
}


int main(void) {
    ifstream ifs;
    ofstream ofs;
    ifs.open("/Users/leesunhwan/Downloads/Coding/Xcode/University/Junior/2nd_Semester/Algorithm/Minimum Spanning Tree/Minimum Spanning Tree/mst.inp.txt");
    ofs.open("/Users/leesunhwan/Downloads/Coding/Xcode/University/Junior/2nd_Semester/Algorithm/Minimum Spanning Tree/Minimum Spanning Tree/mst.out.txt");
    int n, m, u, v, w;
    int nodecnt = 0;
    vector<Node> arr;
    vector<int> seq;
    
    ifs >> n >> m;  // 노드 수, 엣지 수
    
    nodecnt = n;    // 노드 수 복사
    
    // 모든 엣지를 벡터에 저장
    for(int i = 0; i < m; ++i){
        ifs >> u >> v >> w;
        arr.push_back(Node(u, v, w, i));
    }
    
    // weight를 기준으로 오름차순 정렬
    sort(arr.begin(), arr.end());
    
    // parent노드가 몇번인지를 저장하는 배열 자기 자신으로 초기화
    for(int i = 0; i < m; ++i){
        parent[i] = i;
    }
    
    // 정렬된 벡터에서 첫번째부터 차례대로 kruskal 알고리즘 수행.
    for(int i = 0; i < m; ++i){
        if(!sameParent(arr[i].source, arr[i].dest) && nodecnt > 0){
            int x = getParent(arr[i].source);
            int y = getParent(arr[i].dest);
            if(x < y) parent[y] = x;
            else parent[x] = y;
            seq.push_back(arr[i].index);
            sum += arr[i].weight;
            nodecnt--; // 노드수-1 개의 엣지만 있으면 되므로 그 이상의 과정은 패스.
        }
    }
    
    ofs << "Tree edges by Kruskal algorithm: " << sum << endl;
    for(int i = 0; i < seq.size(); ++i){
        ofs << seq[i] << endl;
    }
    

    ifs.close();
    ofs.close();

    return 0;
}
