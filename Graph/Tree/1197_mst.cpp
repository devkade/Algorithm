#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define endl '\n'
using namespace std;

int V, E, A, B, C;
int parent[10001];
int res = 0;
vector<tuple<int, int, int>> graph;

int Find(int x){
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

int Union(int i){
    int x = get<1>(graph[i]);
    int y = get<2>(graph[i]);
    x = Find(x);
    y = Find(y);
    if(x != y){
        parent[y] = x;
        return get<0>(graph[i]);
    }
    return 0;
}

void Initialize(){
    for(int i=1; i<=V; i++){
        parent[i] = i;
    }
}

void Input(){
    cin >> V >> E;
    for(int i=0; i<E; i++){
        cin >> A >> B >> C;
        graph.push_back(make_tuple(C, A, B));
    }
    sort(graph.begin(), graph.end());
}

void Solution(){
    for(int i=0; i<E; i++){
        res += Union(i);
    }
    cout << res << endl;
}

int main(){
   ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Initialize();
    Solution();

    return 0;
}