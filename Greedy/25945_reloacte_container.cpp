#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long long containers[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, sum = 0, res = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> containers[i];
        sum += containers[i];
    }

    int avg = sum / n;

    sum = 0;
    for(int i = 0; i < n; i++){
        if(containers[i] < avg){
            res += avg - containers[i];
        }
        else if(avg+1 < containers[i]){
            sum += containers[i] - (avg+1);
        }
    }
    if(sum > res){
        res = sum;
    }
    cout << res << endl;

    return 0;
}