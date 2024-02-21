#include <iostream>

#define endl '\n'
using namespace std;

int N;
int matInfo[501][2];
int dp[501][501];

void Input(){
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> matInfo[i][0] >> matInfo[i][1];
    }
}

void Solution(){
    for(int i=1; i<N; i++){
        for(int j=1; i+j<=N; j++){
            dp[j][i+j] = INT32_MAX;
            for(int k=j; k<=i+j; k++){
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] \
                                        + matInfo[j][0]*matInfo[k][1]*matInfo[i+j][1]);
            }
        }
    }
    cout << dp[1][N] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}