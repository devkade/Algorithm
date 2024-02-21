#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int N, M;
int board[1025][1025];
int dp[1025][1025];

void Input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i+1][j+1];
            dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + board[i+1][j+1];
        }
    }
}

void Solution(){
    int x1, x2, y1, y2;
    int res;
    while(M--){
        cin >> x1 >> y1 >> x2 >> y2;
        res = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout << res << endl;
    }
}

int main(){
   ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}