#include <bits/stdc++.h>
using namespace std;

int n, m;
int val[10];
int is_used[10];
int num[10];

void func(int cur){
    if(cur == m){
        for(int i = 0; i < m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
    }
    for(int i = 0; i<n; i++){
        if(is_used[i]) continue;
        is_used[i] = 1;
        num[cur] = val[i];
        func(cur+1);
        is_used[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> val[i];
    }
    sort(val, val+n);

    func(0);
    return 0;
}