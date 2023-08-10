#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, res=-1, sum, div;

    cin >> N;

    for(int i=0; i<N; i++){
        sum = 0;        
        sum += i;

        div = i;
        while(div != 0){
            sum += div % 10;
            div = div / 10;
        }

        if (N == sum) {
            res = i;
            break;
        }
    }
    if (res == -1) res = 0;

    cout << res << '\n';
        

    return 0;
}