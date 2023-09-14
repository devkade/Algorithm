#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int vis[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, res=MAX;
    queue<int> q;
    
    cin >> N >> K;

    fill(vis, vis+MAX, MAX);
    vis[N] = 0;
    q.push(N);
    while(!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == K){
            res = vis[cur];
            break;
        }

        if(cur * 2 < MAX && vis[cur * 2] > vis[cur]){
            vis[cur*2] = vis[cur];
            q.push(cur*2);
        }

        if(cur + 1 < MAX && vis[cur + 1] > vis[cur] + 1){
            vis[cur+1] = vis[cur] + 1;
            q.push(cur+1);
        }

        if(cur - 1 >= 0 && vis[cur - 1] > vis[cur] + 1){
            vis[cur - 1] = vis[cur] + 1;
            q.push(cur - 1);
        }
    }


    cout << res << '\n';


    return 0;
}