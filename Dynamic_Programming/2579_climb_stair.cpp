#include <bits/stdc++.h>
using namespace std;

int dp[303];
int arr[303];
int N;

void solve(int n){
    if(n==1){
        cout << arr[0] << '\n';
    }
    else if(n==2){
        cout << arr[0] + arr[1] << '\n';
    }
    else{
        dp[0] = arr[0];
        dp[1] = dp[0] + arr[1];
        dp[2] = max(arr[0], arr[1]) + arr[2];
        for(int i=3; i<n; i++){
            dp[i] = max(dp[i-2], dp[i-3]+arr[i-1]) + arr[i];
        }
        cout << dp[n-1] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    solve(N);

    return 0;
}