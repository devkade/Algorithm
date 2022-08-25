#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[10];
int is_used[10];

void func(int k){
    if(k==m){
        for(int i=0; i<m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(!is_used[i]){
            ans[k] = i;
            is_used[i] = 1;
            func(k+1);
            is_used[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
    return 0;
}