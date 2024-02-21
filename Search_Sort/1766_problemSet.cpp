#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int N, M, A, B;
int degree[32001];
vector<int> connect[32001];

void Input(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> A >> B;
        connect[A].push_back(B);
        degree[B]++;
    }
}

void Solution(){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=1; i<=N; i++){
        if(degree[i]==0){
            pq.push(i);
        }
    }

    for(int i=1; i<=N; i++){
        int cur = pq.top(); pq.pop();

        cout << cur << ' ';

        for(auto nxt : connect[cur]){
            degree[nxt]--;
            if(degree[nxt]==0){
                pq.push(nxt);
            }
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