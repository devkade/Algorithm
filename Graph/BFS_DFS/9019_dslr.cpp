#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define endl '\n';
#define X first;
#define Y second;
using namespace std;

int start, target;
int vis[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        queue<pair<string, int>> q;
        memset(vis, 0, sizeof(vis));

        cin >> start >> target;
        q.push({"", start});
        vis[start] = 1;
        while(!q.empty()){
            auto info = q.front(); q.pop();
            int val = info.Y;

            if(val == target){
                cout << info.first << endl;
                break;
            }
            
            int temp;
            string cmd = info.X;

            temp = (2 * val) % 10000;
            if(!vis[temp]){
                vis[temp] = 1;
                q.push({cmd + "D", temp});
            }
            temp = (val == 0) ? 9999 : val - 1;
            if(!vis[temp]){
                vis[temp] = 1;
                q.push({cmd + "S", temp});
            }
            temp = (val % 1000) * 10 + (val / 1000);
            if(!vis[temp]){
                vis[temp] = 1;
                q.push({cmd + "L", temp});
            }
            temp = (val / 10) + 1000 * (val % 10);
            if(!vis[temp]){
                vis[temp] = 1;
                q.push({cmd + "R", temp});
            }
        }
    }

    return 0;
}