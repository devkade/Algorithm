#include <bits/stdc++.h>
using namespace std;

int n, m;
int val[10];
int num[10];
int is_used[10];


void func(int k){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    int tmp = 0;
    for(int i=0; i<n; i++){
        if(is_used[i]) continue;
        if(tmp == val[i]) continue;
        if(k != 0 && num[k-1] > val[i]) continue;
        is_used[i] = 1;
        num[k] = val[i];
        tmp = num[k];
        func(k+1);
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