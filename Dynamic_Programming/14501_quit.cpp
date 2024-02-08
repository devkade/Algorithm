#include <bits/stdc++.h>
using namespace std;
#define X first
 
int N, T[20], P[20], res = 0;
int price[20] = {0,};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int res = 0;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> P[i];
    }

    for(int i=0; i<=N; i++){
        price[i] = max(price[i], res);
        if(P[i]+price[i] > price[i+T[i]] && i+T[i]< N+1)
            price[i+T[i]] = P[i] + price[i];
        if(res < price[i]) res = price[i];
    }

    cout << res << '\n';

    return 0;    
}