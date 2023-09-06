#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
vector<pair<int, int>> vec;
queue<int> q;
stack<int> st;
int visit[1005];
int flag[1005];

// 재귀적 방식
// void dfs(int v){
//     visit[v] = 1;
//     cout << v << ' ';
//     for(auto link : graph[v]){
//         if(visit[link] == 0)
//             dfs(link);
//     }
// }

void dfs(int V){
    st.push(V);
    visit[V] = 1;

    int v = st.top();
    cout << v << ' ';
    while(!st.empty()){
        v = st.top(); st.pop();
        for(auto link : graph[v]){
            if(visit[link] == 0){
                visit[link] = 1;
                cout << link << ' ';
                st.push(v);
                st.push(link);
                break;
            }
        }
    }
}

void bfs(int V){
    q.push(V);
    visit[V] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        cout << v << ' ';
        for(auto link : graph[v]){
            if(visit[link] == 0){
                q.push(link);
                visit[link] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, V, val1, val2;

    cin >> N >> M >> V;

    for(int i=0; i < M; i++){
        cin >> val1 >> val2;
        if(val1 < val2)
            vec.push_back({val1, val2});
        else
            vec.push_back({val2, val1});
    }
    sort(vec.begin(), vec.end());

    for(int i=0; i < vec.size(); i++){
        val1 = vec[i].first;
        val2 = vec[i].second;
        // 무방향 그래프
        graph[val1].push_back(val2);
        graph[val2].push_back(val1);
    }

    dfs(V);
    cout << '\n';
    fill(visit, visit+N+1, 0);

    bfs(V);

    return 0;
}