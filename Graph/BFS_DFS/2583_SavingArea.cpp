#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[105][105];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int x, y, k;
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> y >> x >> k;
    pair<int, int> Left, Right;
    while(k--){
        cin >> Left.X >> Left.Y >> Right.X >> Right.Y;
        for(int i=y-Right.Y; i<y-Left.Y; i++){
            for(int j=Left.X; j<Right.X; j++){
                board[i][j] = -1;
            }
        }
    }
    // 직사각형 그리기 확인
    /*
    for(int i=0; i< y; i++){
        for(int j=0; j< x; j++){
            cout << board[i][j] << '\t';
        }
        cout << endl;
    }
    */
    int cArray[105];
    int index = 0;
    int area = 0;
    for(int i=0; i < y; i++){
        for(int j=0; j < x; j++){
            int cnt = 0;
            if(board[i][j] == 0){
                q.push({j, i});
                board[i][j] = 1;
                area++;
                cnt++;
            }
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir=0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
                    if(board[ny][nx] >= 1 || board[ny][nx] == -1) continue;
                    board[ny][nx] = board[cur.Y][cur.X] + 1; 
                    q.push({nx, ny});  
                    cnt++;
                }
                if(q.empty() && cnt != 0){
                    cArray[index] = cnt;
                    index++;
                }
            }
        }
    }
    /*
    for(int i=0; i< y; i++){
        for(int j=0; j< x; j++){
            cout << board[i][j] << '\t';
        }
        cout << endl;
    }
    */
    ///*
    sort(cArray, cArray+index);
    cout << area << endl;
    for(int i = 0; i < index; i++){
        cout << cArray[i] << ' ';
    }
    //*/
}