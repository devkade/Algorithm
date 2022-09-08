#include <bits/stdc++.h>
using namespace std;

int n, m;
int val[10];
int num[10];


void func(int k){
    if(k==m){
        for(int i=0; i<m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    int tmp = 0;
    for(int i=0; i<n; i++){
        if(tmp == val[i]) continue;
        num[k] = val[i];
        tmp = num[k];
        func(k+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    sort(val, val+n);
    func(0);
    return 0;
}