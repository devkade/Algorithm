#include <bits/stdc++.h>
using namespace std;

int WBarr[2];
int board[130][130];

// Àç±ÍÇÔ¼ö
void func(const int board[130][130], int n, int x, int y){
    int is_same = 1;
    int num = board[x][y];
    if(n==1){
        WBarr[num]++;
        return;
    }
    for(int i = x; i < x+n; i++){
        for(int j = y; j < y+n; j++){
            if(num == board[i][j]) continue;
            is_same = 0;
            break;
        }
        if(is_same == 0) break;
    }
    if(is_same == 1){
        WBarr[num]++;
        return;
    }
    for(int i = x; i < x+n; i += n/2){
        for(int j = y; j < y+n; j += n/2){
            func(board, n/2, i, j);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    func(board, n, 0, 0);

    cout << WBarr[0] << endl;
    cout << WBarr[1] << endl;
}