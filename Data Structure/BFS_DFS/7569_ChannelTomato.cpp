#include <bits/stdc++.h>
using namespace std;

int dist[102][102][102];
int board[102][102][102];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int m, n, h;
queue<tuple<int, int, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;

    // 초기에 익은 토마토 확인
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                int temp;
                cin >> temp;
                board[i][j][k] = temp;
                if(board[i][j][k]== 0){
                    dist[i][j][k] = -1;
                }
                if(board[i][j][k] == 1)
                    q.push({j, k, i});
            }
        }
    }
    /*
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cout << dist[i][j][k];
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cout << board[i][j][k];
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    */
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0; dir < 6; dir++){
                        int nx = get<0>(cur) + dx[dir];
                        int ny = get<1>(cur) + dy[dir];
                        int nz = get<2>(cur) + dz[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
                        if(dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == -1) continue;
                        dist[nz][nx][ny] = dist[get<2>(cur)][get<0>(cur)][get<1>(cur)] + 1;
                        q.push({nx, ny, nz});
                    }
                }
            }
        }
    } 

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }
    cout << ans << endl;
}