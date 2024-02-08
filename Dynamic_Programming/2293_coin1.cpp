#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int coin[105];
int dp[10005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> coin[i];
    }

    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = coin[i]; j <= k; j++){
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }

    cout << dp[k] << endl;

    return 0;
}