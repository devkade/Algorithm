#include <bits/stdc++.h>
using namespace std;

int n, m;
int val[10];
int num[10];
int is_used[10];


void func(int k){
    if(k==m){
        for(int i=0; i<m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for(int i=0; i<n; i++){
        if(is_used[i]) continue;
        if(num[k]!=0 && num[k]==val[i]) continue;
        is_used[i] = 1;
        num[k] = val[i];
        func(k+1);
        is_used[i] = 0;
        if(num[k+1]!=0) num[k+1] = 0; 
        // 배열 초기화 처리를 안해주면 다음 배열을 찾을 때 중복이라 인식한다.
        // ex)이전 1 3 3 정답 2 1 3 이면 k=2일 때 3이 서로 중복이라 다음 배열찾기로 넘어간다.
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