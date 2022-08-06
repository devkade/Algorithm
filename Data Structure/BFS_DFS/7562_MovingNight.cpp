#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[302][302];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int l;
pair<int, int> now, target;
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> l;
        cin >> now.X >> now.Y;
        cin >> target.X >> target.Y;


        while(!q.empty()){
            q.pop();
        }

        // dist √ ±‚»≠
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                dist[i][j] = -1;
            }
        }
        q.push({now.X, now.Y});
        dist[now.X][now.Y] = 0;
        if(now.X == target.X && now.Y == target.Y){
            cout << dist[now.X][now.Y] << endl;
            continue;
        }

        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0; dir < 8; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                        if(dist[nx][ny] >= 0) continue;
                        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        if(target.X == nx && target.Y == ny){
                            cout << dist[nx][ny] << endl;
                            break;
                        }
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}