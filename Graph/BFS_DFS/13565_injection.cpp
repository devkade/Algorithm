#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second

int board[1003][1003];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue <pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int M, N;

    cin >> M >> N;
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            char ch;
            cin >> ch;
            if(ch == '0') board[i][j] = 0;
            else board[i][j] = 1;

            if(i == 0 && board[i][j] == 0){
                board[i][j] = -1;
                q.push({i, j});
            }
        }
    }


    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if(board[nx][ny] == -1 || board[nx][ny] == 1) continue;
            if(nx == M-1){
                cout << "YES" << endl;
                return 0;
            }
            q.push({nx, ny});
            board[nx][ny] = -1;
        }
    }

    cout << "NO" << endl;

    return 0;
}