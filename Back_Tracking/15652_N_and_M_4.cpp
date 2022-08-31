#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int is_used[10][10];


void func(int cur, int fixed){
    if(cur == m){
        for(int i=0; i<m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i<=n; i++){
        if(is_used[fixed][i]) continue; // 사용되지 않았다면
        if(cur!=0 && num[cur-1] > i) continue;
        is_used[fixed][i]=1;
        num[cur] = i; 
        func(cur+1, fixed+1);
        is_used[fixed][i]=0;
    }
}


int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cin >> n >> m;
    func(0, 0);
    return 0;
}
