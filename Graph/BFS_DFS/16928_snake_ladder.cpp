#include <iostream>
#include <vector>
#include <queue>
#define endl '\n';
using namespace std;

int snake[101];
int ladder[101];
int vis[101];
int n, m;
queue<pair<int, int>> q;

void Input(){
    cin >> n >> m;

    int val;
    for(int i=0; i<n; i++){
        cin >> val;
        cin >> ladder[val];
    }
    for(int i=0; i<m; i++){
        cin >> val;
        cin >> snake[val];
    }
}

int game(){
    int start = 1;
    vis[start] = 1;
    q.push({0, start});

    int prev_roll, prev;
    while(!q.empty()){
        auto info = q.front(); q.pop(); 
        prev_roll = info.first;
        prev = info.second;
        if(prev == 100) return prev_roll;
        for(int i=1; i<=6; i++){
            int cur = prev + i;
            int cur_roll = prev_roll + 1;
            if(vis[cur] == 1 || cur > 100 || cur < 1) continue;
            
            vis[cur] = 1;
            if(ladder[cur] != 0){
                cur = ladder[cur];
            }
            else if(snake[cur] != 0){
                cur = snake[cur];
            }
            q.push({cur_roll, cur});
        }
    }
}

void Solution(){
    cout << game() << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}