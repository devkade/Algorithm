#include <bits/stdc++.h>
using namespace std;
#define X get<0>
#define Y get<1>
#define Z get<2>

char board[33][33][33];
int vis[33][33][33];
int level, row, column;
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = { 0, 0,-1, 1, 0, 0};
int dz[6] = { 0, 0, 0, 0, -1, 1};
queue<tuple<int, int, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        cin >> level >> row >> column;
        if(level == 0 && row == 0 && column == 0) break;
        for(int L = 0; L < level; L++){
            for(int R = 0; R < row; R++){
                for(int C = 0; C < column; C++){
                    cin >> board[L][R][C];
                    vis[L][R][C] = -1;
                    if(board[L][R][C] == 'S'){
                        q.push({C, R, L});
                        vis[L][R][C] = 0;
                    }
                }
            }
        }
        /*
        for(int L = 0; L < level; L++){
            for(int R = 0; R < row; R++){
                for(int C = 0; C < column; C++){
                    cout << board[L][R][C] << '\t';
                }
                cout << endl;
            }
            cout << endl << endl;
        }
        */
        int endflag = 0;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir = 0; dir < 6; dir++){
                int nx = X(cur) + dx[dir];
                int ny = Y(cur) + dy[dir];
                int nz = Z(cur) + dz[dir];
                if(nx < 0 || nx >= column || ny < 0 || ny >= row || nz < 0 || nz >= level) continue;
                if(board[nz][ny][nx] == '#' || vis[nz][ny][nx] >= 0) continue;
                if(board[nz][ny][nx] == 'E'){
                    cout << "Escaped in " << vis[Z(cur)][Y(cur)][X(cur)] + 1 << " minute(s)." << endl;
                    endflag = 1;
                    break;
                }
                q.push({nx, ny, nz});
                vis[nz][ny][nx] = vis[Z(cur)][Y(cur)][X(cur)] + 1;
            }
            if(endflag) break;
        }
        /*
        for(int L = 0; L < level; L++){
            for(int R = 0; R < row; R++){
                for(int C = 0; C < column; C++){
                    cout << vis[L][R][C] << '\t';
                }
                cout << endl;
            }
            cout << endl << endl;
        }
        */
        if(!endflag) cout << "Trapped!" << endl;
        while(!q.empty()) q.pop();
    }
}
