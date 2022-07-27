#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[1005][1005];
int board[1005][1005];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    queue<pair<int, int>> q;
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                q.push({i, j});
            }
            if(board[i][j] == 0){
                dist[i][j] = -1;
            }
        }
    }
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            res = max(res, dist[i][j]);
        }
    }
    cout << res;

}