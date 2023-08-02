#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[50][50];
int dist[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;
queue<pair<int, int>> w;
int R, C;

void water(){
    int num = w.size();
    while(num--){
        pair<int, int> cur = w.front(); 
        w.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if ((nx < 0)||(nx >= R)||(ny < 0)||(ny >= C)) continue;
            if (board[nx][ny] != '.') continue;
            board[nx][ny] = '*';
            w.push({nx, ny});
        }
    }
}

int escape(){
    int check = -1;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        if (check != dist[cur.X][cur.Y]){
            water();
            check = dist[cur.X][cur.Y];
        }
        for (int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if ((nx < 0)||(nx >= R)||(ny < 0)||(ny >= C)) continue;
            if (board[nx][ny] == '*' || board[nx][ny] == 'X' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            if (board[nx][ny] == 'D') return dist[nx][ny];
            q.push({nx, ny});
        }
    }
    return -1;
};

int main(){
    ios::sync_with_stdio(true);
    cin.tie(), cout.tie();

    cin >> R >> C;
    for(int row=0; row<R; row++){
        for(int col=0; col<C; col++){
            cin >> board[row][col];
            dist[row][col] = -1;
            if (board[row][col] == 'S'){
                q.push({row, col});
                dist[row][col] = 0;
            }
            else if (board[row][col] == '*'){
                w.push({row, col});
            }

        }
    }

    int dest_dist = escape();

    if (dest_dist == -1){
        cout << "KAKTUS" << endl;
    }
    else{
        cout << dest_dist << endl;
    }

    return 0;
}