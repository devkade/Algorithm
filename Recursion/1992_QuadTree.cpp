#include <bits/stdc++.h>
using namespace std;

char board[66][66];
vector<int> vec;

void func(char board[66][66], int n, int x, int y){
    int is_same = 1;
    if(n==1) {
        cout << board[x][y];
        return;
    }
    for(int i=x; i < x+n; i++)
    for(int j=y; j < y+n; j++){
        if(board[x][y]==board[i][j]) continue;
        is_same=0;
        break;
    }

    if(is_same){
        cout << board[x][y];
        return;
    }
    cout << '(';
    // 4방향으로 나누는 과정이 아래 for문이므로 바깥에 괄호를 넣어야 함.
    for(int i=x; i < x+n; i += n/2)
    for(int j=y; j < y+n; j += n/2)
        func(board, n/2, i, j);
    cout << ')';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        cin >> board[i][j];
    
    func(board, n, 0, 0);
}