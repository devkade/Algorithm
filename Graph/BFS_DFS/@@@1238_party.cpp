#include <iostream>
#include <vector>
#include <queue>
#define E first
#define T second

int N, M, X;
vector<pair<int,int>> town[10001];
queue<pair<int, int>> q; // pair<chosen_end, time_sum>
int vis[10001];
int res=0;

void Input(){
    cin >> N >> M >> X;
    for(int i=0; i<M; i++){
        int start, end, time;
        cin >> start >> end >> time;
        town[i].push_back({end, time});
    }
}

void Initialize(){
    fill(vis, vis+10001, 0);
}

void bfs(int start){
    q.push({start, 0});
    vis[start] = 1;
    while(!q.empty()){
        auto prev = q.front(); q.pop();

        if(prev.E == X){
            if(res < prev.T) res = prev.T;
            break;
        }       

        for(auto nxt : town[prev]){
            if(vis[nxt.E] == 1) continue;
            vis[nxt.E] = 1;
            nxt.T += prev.T;
            q.push(nxt);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();


    return 0;
}