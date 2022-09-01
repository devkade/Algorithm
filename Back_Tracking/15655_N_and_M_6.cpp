#include <bits/stdc++.h>
using namespace std;

int n, m;
int is_used[10];
int val[10];
int num[10];


void func(int k){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
    }
    int st = 0;
    if(k != 0) st = k;
    for(int i=st; i<n; i++){
        if(num[k-1] >= val[i]) continue;
        num[k] = val[i];
        func(k+1);
    }
}
'''
void func(int k){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++){
        if(is_used[i]) continue;
        if(num[k-1]>val[i]) continue;
        is_used[i] = 1;
        num[k] = val[i];
        func(k+1);
        is_used[i] = 0;
    }
}
'''

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