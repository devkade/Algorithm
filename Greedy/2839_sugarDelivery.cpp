#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, temp, five, three = 0;

    cin >> N;

    temp = N;

    five = N / 5;
    N = N % 5;

    if(temp == 4 || temp == 7){
        cout << -1 << '\n';
        exit(0);
    }
    if(N == 1){
        five -= 1;
        three = 2;
    }
    else if(N == 2){
        five -= 2;
        three = 4;
    }
    else if(N == 3){
        three = 1;
    }
    else if(N == 4){
        five -= 1;
        three = 3;
    }

    cout << five+three << '\n';
    

    return 0;
}