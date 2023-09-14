#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, res = 0;
    
    cin >> a >> b;

    while(true){
        if(b % 10 != 1 && b % 2 == 1){
            cout << -1 << '\n';
            exit(0);
        }
        else if(b % 10 == 1){
            res++;
            b = b / 10;
        }
        else{
            b = b / 2;
            res++;
        }
        if(a > b){
            cout << -1 << '\n';
            exit(0);
        }
        else if(a == b){
            break;
        }
    }

    cout << res+1 << '\n';

    return 0;
}