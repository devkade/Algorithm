#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    LL res = 1;

    cin >> N >> M;
    N--; M--;

    if(N >= 2){
        if(3<=M && M<6) res += 3;
        else if(M==2) res += 2;
        else if(M==1) res += 1;
        else if(M==6) res += 4;
        else if(M==0) res += 0;
        else {
            res += 4;
            res += M-6;
        }
    }
    else if(N == 1){
        if(M >= 6) res += 3;
        else if(M == 5 || M == 4) res += 2;
        else if(M == 2 || M == 3) res += 1;
        else if(M == 0) res += 0;
    }
    else if(N == 0 || M == 0) res += 0;
    else{
        res += 4;
        res += M-6;
    }

    cout << res << '\n';

    return 0;
}