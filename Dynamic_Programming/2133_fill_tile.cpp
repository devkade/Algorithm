#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int dp[33];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    if(n % 2 == 1){
        cout << 0 << endl;
        exit(0);
    }
    dp[0] = 1;
    for(int i=2; i<=n; i+=2){
        for(int j=2; j<=i; j+=2){
            int first = i-(i-j), factor;
            if(first == 2) factor = 3;
            else factor = 2;
            dp[i] += dp[i-j] * factor;
        }
    }

    cout << dp[n] << endl;

    return 0;
}