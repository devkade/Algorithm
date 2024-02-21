#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define endl '\n'
using namespace std;

int T, N, K, a, b, goal;
int Time[1001];
vector<int> Sequence[1001];
int Indegree[1001];
int Res[1001];

void Input(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> Time[i];
    }
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        Sequence[a].push_back(b);
        Indegree[b]++;
    }
    cin >> goal;
}

void Initialize(){
    for (int i = 0; i <= N; i++) Sequence[i].clear();
    memset(Time, 0, sizeof(Time));
    memset(Res, 0, sizeof(Res));
    memset(Indegree, 0, sizeof(Indegree));
}

void Solution(){
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(Indegree[i]==0){
            q.push(i);
            Res[i] = Time[i];
        }
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : Sequence[cur]){
            Res[nxt] = (Res[nxt] < Res[cur]+Time[nxt]) ? Res[cur]+Time[nxt] : Res[nxt];
            Indegree[nxt]--;
            if(Indegree[nxt]==0){
                q.push(nxt);
            }
        }
    }
    cout << Res[goal] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--){
        Input();
        Solution();
        Initialize();
    }

    return 0;
}