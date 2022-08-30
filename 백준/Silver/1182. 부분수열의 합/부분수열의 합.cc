#include <bits/stdc++.h>
using namespace std;

int n, s;
int num[25];
int ans = 0;

void func(int k, int sum){
    if(k == n){
        if(sum == s)
            ans++;
        return;
    }
    func(k+1, sum);
    func(k+1, sum+num[k]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0; i< n; i++){
        cin >> num[i];
    }
    func(0, 0);
    if(s == 0){ans--;}
    cout << ans << endl;
    return 0;
}