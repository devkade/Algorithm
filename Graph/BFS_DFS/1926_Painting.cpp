#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int vis[502][502];              // 방문 확인 배열
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int> > q;       // 2차원 배열이므로 pair 사용


int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    int n, m, val;
    int board[502][502];
    cin >> n >> m;
    for(int i = 0; i < n; i++){         // 보드판에 값 입력
        for(int j = 0; j < m; j++){
            cin >> val;
            board[i][j] = val;
        }
    }
    int cnt = 0, area = 0;
    for(int row = 0; row < n; row++){   
        for(int col = 0; col < m; col++){
            int temp = 0;
            if(vis[row][col] != 0 || board[row][col] != 1) continue;    // 초기값 설정
            vis[row][col] = 1;
            q.push({row, col});
            cnt++;
            while(!q.empty()){                  // 2~4번 과정
                pair<int, int> cur = q.front();
                q.pop();
                temp++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            if(area < temp) area = temp;
        }
    }
    cout << cnt << endl;
    cout << area << endl;
}