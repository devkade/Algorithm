#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[103][103];
int n;
int MAX = 0, MIN = 9999, ans = 0;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;

int BFS(int n, int wHeight){
    int vis[103][103] = {};
    int area = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] <= wHeight || vis[i][j] == 1) continue;
            q.push({i, j});
            vis[i][j] = 1;
            area++;
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] <= wHeight || vis[nx][ny] == 1) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    return area;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    vector<int> water;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] > MAX) MAX = board[i][j];
            if(board[i][j] < MIN) MIN = board[i][j];
        }
    }
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << '\t';
        }
        cout << endl;
    }
    */
    for(int wHeight=0; wHeight<MAX; wHeight++){
        water.push_back(BFS(n, wHeight));
    }

    for(auto elem : water){
        ans = max(ans, elem);
    }
    cout << ans << endl;

}