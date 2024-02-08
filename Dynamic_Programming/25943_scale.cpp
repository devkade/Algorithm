#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int weight[8] = {100, 50, 20, 10, 5, 2, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, left = 0, right = 0;
    int res = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        if(i == 0) cin >> left;
        else if(i == 1) cin >> right;
        else{
            int val;
            cin >> val;
            if(left > right) right += val;
            else left += val;
        }
    }
    int diff = abs(left - right);

    for(int i = 0; i < 7; i++){
        if(weight[i] <= diff){
            res += diff / weight[i];
            diff = diff % weight[i];
        }
    }

    cout << res << endl;


    return 0;
}