#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;

int n;
ll sol[100001];
ll res, out1, out2;

void Input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> sol[i];
    }
}

void Solution(){
    res = INT64_MAX;
    ll start = 0, end = n-1;
    
    while(start < end){
        ll mix = sol[start]+sol[end];
        if(res > abs(mix)){
            res = abs(mix);
            out1 = sol[start];
            out2 = sol[end];
        }
        if(mix > 0) end--;
        else start++;
    }
    cout << out1 << ' ' << out2 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();

    return 0;
}