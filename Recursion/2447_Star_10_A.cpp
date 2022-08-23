// 다시 풀어보기
#include <bits/stdc++.h>
using namespace std;

char board[6600][6600];

void star(int n, int x, int y){
    if(n == 1){
        board[x][y] = '*';
        return;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1)
                continue;
            star(n/3, x+n/3*i, y+n/3*j);
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        fill(board[i], board[i]+n, ' ');
    }

    star(n, 0, 0);
    for(int i = 0; i < n; i++)
        cout << board[i] << '\n';
}