#include <bits/stdc++.h>
using namespace std;

int n, m;
int val[10];
int is_used[10][10];
int num[10];

/*
void func(int k, int fixed){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i<n; i++){
        if(is_used[fixed][i]) continue;
        is_used[fixed][i] = 1;
        num[k] = val[i];
        func(k+1, fixed+1);
        is_used[fixed][i] = 0;
    }
}
*/

void func(int k){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++){
        num[k]= val[i];
        func(k+1);
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