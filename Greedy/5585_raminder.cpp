#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, res = 0;

    cin >> N;

    N = 1000 - N;

    while(N != 0){
        if(N >= 500){
            res += N / 500;
            N %= 500;
        }
        else if(N >= 100){
            res += N / 100;
            N %= 100;
        }
        else if(N >= 50){
            res += N / 50;
            N %= 50;
        }
        else if(N >= 10){
            res += N / 10;
            N %= 10;
        }
        else if(N >= 5){
            res += N / 5;
            N %= 5;
        }
        else if(N >= 1){
            res += N / 1;
            N %= 1;
        }
    }

    cout << res << '\n';

    return 0;
}