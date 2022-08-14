#include <bits/stdc++.h>
using namespace std;

int ans[5];
int board[2200][2200];

// ����Լ�
void func(const int board[2200][2200], int n, int x, int y){
    int is_same = 1;    // ���� ���� ���� ��� ������ Ȯ��
    int num = board[x][y];
    if(n==1) {
        ans[num+1]++;
        return;
    }
    for(int i = x; i < x+n; i++){ // i < n���� �ϸ� n=3�̰� i=6�� ��
        for(int j = y; j < y+n; j++){ // �ݺ����� �׳� ����ģ��.
            if(num == board[i][j]) continue;
            is_same = 0;
            break;
        }
        if(is_same == 0) break;
    }
    if(is_same == 1){
        ans[num+1]++;       // ������ �� ���ϰ� �ε����� + 1�ߴ�.
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