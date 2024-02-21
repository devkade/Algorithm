#include <iostream>

#define endl '\n'
using namespace std;

int T, N;
int Info[501][2];
int dp[501][501];

void Input(){
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> Info[i][0];
        Info[i][1] = Info[i-1][1] + Info[i][0];
    }
}

void Solution(){
    while(T--){
        Input();
        for(int i=1; i<N; i++){
            for(int j=1; i+j<=N; j++){
                dp[j][i+j] = INT32_MAX;
                for(int k=j; k<=i+j; k++){
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + Info[i+j][1] - Info[j-1][1]);
                    // cout << i << ' ' << j << ' ' << k << endl;
                    // cout << dp[j][k]  << ' ' << dp[k+1][i+j] << ' ' << Info[i+j][1] - Info[j-1][1] << endl;
                    cout << dp[j][i+j] << ' ';
                }
                cout << endl;
            }
        }
        cout << dp[1][N] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    Solution();

    return 0;
}