#include <bits/stdc++.h>
using namespace std;

int vis[100005];
int students[100005];
int n;

void cycle(int x){
    int cur = x;
    while(true){
        vis[cur] = x;
        cur = students[cur];
        if(vis[cur] == x){
            while(vis[cur] != -1){
                vis[cur] = -1;
                cur = students[cur];
            }
            return;
        }
        else if(vis[cur] != 0) return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;

    while(T--){
        cin >> n;
        fill(vis, vis+n+1, 0);
        for(int i=1; i<=n; i++){
            cin >> students[i];
        }
        int res = 0;
        for(int i=1; i<=n; i++){
            if(vis[i] == 0) cycle(i);
        }
        for(int i=1; i<=n; i++){
            if(vis[i] != -1) res++; 
        }
        cout << res << '\n';
    }

    return 0;
}