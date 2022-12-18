#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[5][5];
int is_used[5][5];
int ans = 0;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;
int s = 0;

void func(int k, int x, int y){
    if(k == 7 && s >= 4){
        ans++;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if(is_used[nx][ny] == 1) continue;
        if(board[nx][ny] == 'S') s++;
        is_used[nx][ny] = 1;
        func(k+1, nx, ny);
        is_used[nx][ny] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<5; i++){
        for(int j = 0; j < 5; j++){
            cin >> board[i][j];
            if(board[i][j] == 'S') q.push({i, j});
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();

        func(0, cur.X, cur.Y);
    }
    cout << ans << endl;
}