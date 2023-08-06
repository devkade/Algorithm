#include <bits/stdc++.h>
using namespace std;

int board[50][50];
int vis[50][50];
int dist[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M;

int dfs(int x, int y){
    if (board[x][y] == 0 || x < 0 || x >= N || y < 0 || y >= M) return 0;
    if (vis[x][y] == 1) {
        cout << -1 << endl;
        exit(0);
    }
    if (dist[x][y] != -1) return dist[x][y];

    vis[x][y] = 1;
    dist[x][y] = 0;

    int mat = board[x][y];
    for(int dir = 0; dir<4; dir++){
        int nx = x + dx[dir] * mat;
        int ny = y + dy[dir] * mat;
        if(dist[x][y]<dfs(nx, ny)+1){
            dist[x][y] = dfs(nx, ny)+1;
        }
    }
    vis[x][y] = 0;
    return dist[x][y];
}


int main(){
    ios::sync_with_stdio(true);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int row=0; row<N; row++){
        string str;
        cin >> str;
        for (int col=0; col<M; col++){
            dist[row][col] = -1;
            int val;
            if (str[col]=='H') val = 0;
            else {
                val = int(str[col]) - 48;
            }

            board[row][col] = val;
        }
    }

    int res = dfs(0,0);

    cout << res << endl;

    return 0;
}