#include <bits/stdc++.h>
using namespace std;

// 중복을 허용하여 선택
int n, m;
int num[10];
int is_used[10][10];
int fixed=0;

void func(int cur, int fixed){
    if(cur == m){
        for(int i = 0; i < m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(is_used[fixed][i]) continue;
        is_used[fixed][i] = 1;
        num[cur] = i;
        func(cur+1, fixed+1);
        is_used[fixed][i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0,0);
    return 0;
}
