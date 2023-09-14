#include <bits/stdc++.h>
using namespace std;

int arr[1004], dp[1004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, res = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    fill(dp, dp+n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    for(int i = 0; i < n; i++){
        if (res < dp[i]) res = dp[i];
    }

    cout << res << '\n';

    return 0;
}