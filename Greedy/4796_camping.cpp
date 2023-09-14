#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int L, P, V, share=0, rem=0, res=0, i=1;

    while(true){
        res = 0;
        cin >> L >> P >> V;

        if(L == 0 && P == 0 && V == 0) break;

        share = V / P;
        rem = V % P;

        res += share * L;

        if(L > rem){
            res += rem;
        }
        else{
            res += L;
        }

        printf("Case %d: %d\n", i, res);
        i++;
    }

    return 0;
}