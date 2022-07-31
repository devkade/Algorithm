#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int m, n, k;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int board[55][55] = {};     // 테스트 케이스가 많기 때문에
        int vis[55][55] = {};       // 꼭 초기화를 해줘야 함.
        cin >> m >> n >> k;
        while(k--){                 // 배추가 있는 곳 표시
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << board[i][j];
            }
            cout << endl;
        }
        */

        queue<pair<int, int>> q;
        int ans = 0;                // BFS 돌리기
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(vis[row][col] == 0 && board[row][col] == 1){
                    vis[row][col] = 1;
                    q.push({row, col});
                    ans++;
                }
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] != 0 || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        cout << ans << endl;
    }
}