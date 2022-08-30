#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int vis[502][502];              // �湮 Ȯ�� �迭
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int> > q;       // 2���� �迭�̹Ƿ� pair ���


int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    int n, m, val;
    int board[502][502];
    cin >> n >> m;
    for(int i = 0; i < n; i++){         // �����ǿ� �� �Է�
        for(int j = 0; j < m; j++){
            cin >> val;
            board[i][j] = val;
        }
    }
    int cnt = 0, area = 0;
    for(int row = 0; row < n; row++){   
        for(int col = 0; col < m; col++){
            int temp = 0;
            if(vis[row][col] != 0 || board[row][col] != 1) continue;    // �ʱⰪ ����
            vis[row][col] = 1;
            q.push({row, col});
            cnt++;
            while(!q.empty()){                  // 2~4�� ����
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