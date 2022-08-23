#include <bits/stdc++.h>
using namespace std;

#define MAX 1024*3+2

char board[MAX][MAX*2-1];

void star(const int x, const int y){
    board[x][y] = '*';
    board[x+1][y-1] = '*'; board[x+1][y+1] = '*';
    for(int i=-2; i<=2; i++){
        board[x+2][y+i] ='*';
    }
}

void func(int n, int x, int y){
    if(n==3){
        star(x, y);
        return;
    }

    int half = n/2;
    func(half, x, y);
    func(half, x+half, y-half);
    func(half, x+half, y+half);
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    func(n, 0, n-1);
    for(int i=0; i<n; i++){
        for(int j = 0; j < n*2-1; j++){
            if(board[i][j]=='*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }

}