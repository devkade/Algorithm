#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dp[501][501] = {0,};
int n, maxNum=0;

int main(){
    ios::sync_with_stdio(false);
    using namespace std;

    cin >> n;

    int val;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> val;
            dp[i][j] = val;
        }
    }

    if(n == 1){
        cout << dp[0][0];
        exit(0);
    }

    for(int depth=1; depth<n; depth++){
        for(int idx=0; idx<=depth; idx++){
            if(idx == depth)
                dp[depth][idx] = dp[depth-1][idx-1] + dp[depth][idx];
            else if(idx == 0)
                dp[depth][idx] = dp[depth-1][idx] + dp[depth][idx];
            else
                dp[depth][idx] = max(dp[depth-1][idx], dp[depth-1][idx-1]) + dp[depth][idx];
            
            maxNum = max(maxNum, dp[depth][idx]);
        }
    }

    cout << maxNum << '\n';

    return 0;
}