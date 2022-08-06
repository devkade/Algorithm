#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[105];
int n;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int Nvis[105][105];
int Bvis[105][105];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    char color = ' ';
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    
    queue<pair<int, int>> q;
    int normal = 1;
    for(int i = 0; i < n; i++){         // �Ϲ� ���
        for(int j = 0; j < n; j++){
            if(Nvis[i][j] >= 1) continue;   // ���⼭ ���� ���� �� continue�ؾ��ϴ� ��
            q.push({i, j});                 // �˾����� �ؿ��� �ɷ��ֱ⿡ �ʿ� ����.
            Nvis[i][j] = normal++;
            color = board[i][j];
            while(!q.empty()){                  // ���� ���� Ȯ��
                auto cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(Nvis[nx][ny] >= 1 || board[cur.X][cur.Y] != board[nx][ny]) continue;
                    Nvis[nx][ny] = Nvis[cur.X][cur.Y];
                    q.push({nx, ny});
                }
            }
        }
    }
    normal--;
    cout << normal << ' ';
    for(int i = 0; i < n; i++) {        // ����� ������ ����
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'G'){
                board[i][j] = 'R';
            }
        }
    } 
    int blind = 1;   
    color = ' ';
    for(int i = 0; i < n; i++){         // ���ϻ����� BFS
        for(int j = 0; j < n; j++){
            if(Bvis[i][j] >= 1) continue;
            q.push({i, j});
            Bvis[i][j] = blind++;
            color = board[i][j];
            while(!q.empty()){                  // ���� ���� Ȯ��
                auto cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(Bvis[nx][ny] >= 1 || board[cur.X][cur.Y] != board[nx][ny]) continue;
                    Bvis[nx][ny] = Bvis[cur.X][cur.Y]; q.push({nx, ny}); }
            }
        }
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << Bvis[i][j];
        }
        cout << endl;
    }
    */
    cout << blind-1;
}