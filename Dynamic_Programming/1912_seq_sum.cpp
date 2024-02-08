#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int dp[100005];
int n, res;

void solve(){
    if(res > 0)
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (i == 0) res = arr[i];
        else if(res < arr[i]) res = arr[i];
    }

    solve();

    res = dp[0];
    for(int i = 0; i < n; i++){
        if(res < dp[i]) res = dp[i];
    }

    cout << res << '\n';

    return 0;
}