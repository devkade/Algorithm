#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N, M, A, B;
int degree[32002];
vector<int> after[32002];
queue<int> q;

void Input(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> A >> B;
        after[A].push_back(B);
        degree[B]++;
    }
}

void Solution(){
    for(int i=1; i<=N; i++){
        if(degree[i] == 0) q.push(i);
    }

    for(int i=1; i<=N; i++){
        int cur = q.front(); q.pop();

        cout << cur << ' ';

        for(auto nxt : after[cur]){
            degree[nxt]--;
            if(degree[nxt] == 0) q.push(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}