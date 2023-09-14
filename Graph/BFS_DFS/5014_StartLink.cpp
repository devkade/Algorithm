#include <bits/stdc++.h>
using namespace std;

int vis[1000002];
int finish, start, goal, up, down;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> finish >> start >> goal >> up >> down;
    int upDown[2] = {up, -down};
    for(int i = 0; i <= finish; i++){
        vis[i] = -1;
    }
    queue<int> q;
    q.push(start);
    vis[start] = 0;
    if(start == goal){
        cout << vis[start] << endl;
        return 0;
    }
    while(!q.empty()){
        // int endflag = 0;
        int cur = q.front(); q.pop();
        for(int i = 0; i < 2; i++){
            int move = cur + upDown[i];
            if(move < 1 || move > finish) continue;
            if(vis[move] >= 0) continue;
            if(move == goal){
                cout << vis[cur]+1 << endl;
                return 0;
                /*
                endflag = 1;
                break;
                */
            }
            vis[move] = vis[cur] + 1;
            q.push(move);
        }
        // if(endflag) break;
    }
    /*
    for(int i = 1; i <= finish; i++){
        cout << vis[i] << ' ';
    }
    */
    cout << "use the stairs" << endl;
}