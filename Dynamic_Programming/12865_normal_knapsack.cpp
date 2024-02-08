#include <bits/stdc++.h>
using namespace std;

int weights[101];
int values[101];
int dp[101][100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        int w, v;
        cin >> weights[i] >> values[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j < weights[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]]+ values[i]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    
    // cout << dp[n][k] << endl;

    return 0;
}