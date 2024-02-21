#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, M, res=0, last;
int parent[100001];
vector<pair<int, pair<int, int>>> edge;

void Input(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        parent[i]=i;
    }
    int a, b, c;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        edge.push_back({c,{a, b}});
    }
    sort(edge.begin(), edge.end());
}

int Find(int x){
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        parent[y] = x;
    }
}

int sameParent(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return 1;
    return 0;
}


void Solution(){
    for(int i=0; i<edge.size(); i++){
        if(sameParent(edge[i].second.first, edge[i].second.second) == 0){
            Union(edge[i].second.first, edge[i].second.second);
            last = edge[i].first;
            res += last;
        }
    }
    cout << res - last << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();

    return 0;
}