#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[30][30];
int vis[30][30];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int n;
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char temp;
            cin >> temp;
            if(temp  == '0')
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << '\t';
        }
        cout << endl;
    }
    */
    int area = 0;
    vector<int> cVec;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            if(board[i][j] == 0 || vis[i][j] == 1) continue;
            q.push({i, j});
            vis[i][j] = 1;
            area++;
            cnt++;   
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    cnt++;
                }
                if(q.empty() && cnt != 0){
                    cVec.push_back(cnt);
                }
            }
        }
    }

    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << vis[i][j] << '\t';
        }
        cout << endl;
    }
    */

    
    sort(cVec.begin(), cVec.end());
    cout << area << endl;
    for(auto elem : cVec){
        cout << elem << endl;
    }
    
    
}

/* 2회차
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int board[30][30];
int vis[30][30];
int group = 0, N, res;
vector<int> vec;
queue<pair<int, int>> q;

int bfs(){
    int cnt = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
            cnt++;
        }
    }
    return cnt;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char ch;
            cin >> ch;
            if(ch == '0'){
                board[i][j] = 0;
            }
            else
                board[i][j] = 1;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            res = 0;
            if(board[i][j] == 0 || vis[i][j] == 1) continue;
            q.push({i, j});
            vis[i][j] = 1;
            group++;
            res++;
            res += bfs();
            if(res >= 1){
                vec.push_back(res);
            }
        }
    }

    cout << group << '\n';

    sort(vec.begin(), vec.end());
    for(auto val : vec){
        cout << val << '\n';
    }

    return 0;
}
*/