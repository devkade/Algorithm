#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[501][501] = {0,};
int dist[501][501];
int M, N, res = 0;

int dfs(int X, int Y){
    if(X == M-1 && Y == N-1){
        return 1;
    }
    if(dist[X][Y] == -1){
        dist[X][Y] = 0;
        for(int dir = 0; dir < 4; dir++){
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if(board[X][Y] <= board[nx][ny]) continue;
            dist[X][Y] += dfs(nx, ny);
        }

    }
    return dist[X][Y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> M >> N;

    for(int row = 0; row < M; row++){
        for(int col = 0; col < N; col++){
            cin >> board[row][col];
            dist[row][col] = -1;
        }
    }
    cout << endl;


    cout << dfs(0, 0) << '\n';

    for(int row = 0; row < M; row++){
        for(int col = 0; col < N; col++){
            if(dist[row][col]==-1) cout << " ";
            else cout << "  ";
            cout << dist[row][col];
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}