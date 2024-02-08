#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long long dp[103] = {0,};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    while(T--){
        int N;
        cin >> N;

        if(N <= 5){
            cout << dp[N] << endl;
            continue;
        }
        for(int i = 6; i <= N; i++){
            dp[i] = dp[i-1] + dp[i-5];
        }
        cout << dp[N] << endl;
    }

    return 0;
}