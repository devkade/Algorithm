#include <bits/stdc++.h>
using namespace std;

int ans[5];
int board[2200][2200];

// 재귀함수
void func(const int board[2200][2200], int n, int x, int y){
    int is_same = 1;    // 종이 안의 값이 모두 같은지 확인
    int num = board[x][y];
    if(n==1) {
        ans[num+1]++;
        return;
    }
    for(int i = x; i < x+n; i++){ // i < n으로 하면 n=3이고 i=6일 때
        for(int j = y; j < y+n; j++){ // 반복문을 그냥 지나친다.
            if(num == board[i][j]) continue;
            is_same = 0;
            break;
        }
        if(is_same == 0) break;
    }
    if(is_same == 1){
        ans[num+1]++;       // 저장할 때 편리하게 인덱스를 + 1했다.
        return;
    }
    for(int i = x; i < x+n; i += n/3){
        for(int j = y; j < y+n; j += n/3){
            func(board, n/3, i, j);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    func(board, n, 0, 0);
    cout << ans[0] << endl;
    cout << ans[1] << endl;
    cout << ans[2] << endl;
}