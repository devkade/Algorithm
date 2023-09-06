#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MX 10000000

char board[1002][1002];
int dog[1002][1002];
int fire[1002][1002];
int T, w, h;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>> Dq, Fq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> w >> h;
        int ans = MX;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
                if(board[i][j] == '*'){
                    fire[i][j] = 0;
                    dog[i][j] = -1;
                    Fq.push({i, j});
                }
                else if(board[i][j] == '@'){
                    dog[i][j] = 0;
                    fire[i][j] = -1;
                    Dq.push({i, j});
                }
                else{
                    dog[i][j] = -1;
                    fire[i][j] = -1;
                }
            }
        }

        // 불의 bfs
        while(!Fq.empty()){
            auto cur = Fq.front(); Fq.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                Fq.push({nx, ny});
            }
        }
/*
        for(int i = 0; i < h ; i++){
            for(int j = 0; j < w; j++){
                cout << fire[i][j] << '\t';
            }
            cout << endl;
        }
        cout << endl;
*/
        // 상근의 bfs
        int endflag = 0;
        while(!Dq.empty()){
            auto cur = Dq.front(); Dq.pop();
            for(int dir=0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    //ans = min(ans, dog[cur.X][cur.Y]+1);
                    ans = dog[cur.X][cur.Y]+1;
                    endflag=1;
                    break;
                }
                if(board[nx][ny] == '#' || dog[nx][ny] >= 0) continue;
                if(fire[nx][ny] != -1 && fire[nx][ny] <= dog[cur.X][cur.Y]+1) continue;
                dog[nx][ny] = dog[cur.X][cur.Y] + 1;
                Dq.push({nx, ny});
            }
            if(endflag) break;
        }

/*
        for(int i = 0; i < h ; i++){
            for(int j = 0; j < w; j++){
                cout << dog[i][j] << '\t';
            }
            cout << endl;
        }
*/

        if(ans != MX)
            cout << ans << endl;
        else
            cout << "IMPOSSIBLE" << endl;

        while(!Dq.empty()){
            Dq.pop();
        }
    }
}