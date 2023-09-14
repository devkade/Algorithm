#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int board[303][303];
int N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int row = 0; row < N; row++){
        for(int col = 0; col < M; col++){
            cin >> board[row][col];
        }
    }

    

    return 0;
}