#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int bytes[101], cost[101];
int dp[101][10001];
int N, M, sum = 0, res = INT32_MAX;

void Input(){
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> bytes[i];
    }
    for(int i=1; i<=N; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

}

void Solution(){
    for(int i=1; i<=N; i++){
        for(int j=0; j<=sum; j++){
            if(j >= cost[i]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]]+bytes[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(dp[i][j] >= M) {
                res = min(res, j);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();
    cout << res << endl;

    return 0;
}