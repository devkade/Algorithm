#include <bits/stdc++.h>
using namespace std;

int k;
int num[6];
int val[50];
int is_used[50];

void func(int cur){
    if(cur == 6){
        for(int i=0; i<6; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for(int i=0; i<k; i++){
        if(is_used[i]) continue;
        if(cur != 0 && num[cur-1] > val[i]) continue;
        is_used[i] = 1;
        num[cur] = val[i];
        func(cur+1);
        is_used[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        
        cin >> k;
        if(k == 0) break;
        for(int i=0; i<k; i++){
            cin >> val[i];
        }
        func(0);    
        cout << endl;
    }
    return 0;
}