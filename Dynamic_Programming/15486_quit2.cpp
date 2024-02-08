#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int T[1500005], P[1500005], res=0;
int dp[1500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> T[i] >> P[i];
    }

    for(int i=0; i<=n; i++){
        dp[i] = max(dp[i], res);
        if(i+T[i] < n+1 && dp[i]+P[i] > dp[i+T[i]]){
            dp[i+T[i]] = dp[i] + P[i];
        }
        res = max(dp[i], res);
    }

    for(int i=0; i<=n; i++){
        cout << dp[i] << ' ';
    }
    cout << endl;

    cout << res << endl;

    return 0;
}