#include <bits/stdc++.h>
using namespace std;

int n;
int col[40];
int crossT[40];
int crossB[40];
int ans = 0;

void func(int k){
    if(k == n){
        ans++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(col[i] || crossT[k+i] || crossB[i-k+n-1]) continue;
        col[i] = 1;
        crossT[k+i] = 1;
        crossB[i-k+n-1] = 1;
        func(k+1);
        col[i] = 0;
        crossT[k+i] = 0;
        crossB[i-k+n-1] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << ans << endl;
}