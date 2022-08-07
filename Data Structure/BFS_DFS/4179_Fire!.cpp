#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[1005][1005];
int dist_F[1005][1005];
int dist_J[1005][1005];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int R, C;
queue<pair<int, int>> fire, runner;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            dist_F[i][j] = -1;
            dist_J[i][j] = -1;
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
            if(board[i][j] == 'F'){
                fire.push({i, j});
                dist_F[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                runner.push({i, j});
                dist_J[i][j] = 0;
            }
        }
    }
    while(!fire.empty()){               // 불에 대한 BFS
        auto cur = fire.front(); fire.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(board[nx][ny] == '#' || dist_F[nx][ny] >= 0) continue;
            dist_F[nx][ny] = dist_F[cur.X][cur.Y] + 1;
            fire.push({nx, ny});
        }
    }
    while(!runner.empty()){             // 지훈에 대한 BFS
        auto cur = runner.front(); runner.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C){     // 끝에 도달하면 탈출
                cout << dist_J[cur.X][cur.Y]+1;
                return 0;
            }
            if(dist_J[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(dist_F[nx][ny] != -1 && dist_F[nx][ny] <= dist_J[cur.X][cur.Y]+1) continue;  // 중요!!!
            dist_J[nx][ny] = dist_J[cur.X][cur.Y] + 1;      // 불로 인해 지훈이가 갈 수 없는 경우 제외
            runner.push({nx, ny});                          // 불이 안지나가도 -1이 기본값이기에 -1일 때는 지나갈 수 있도록 처리
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}