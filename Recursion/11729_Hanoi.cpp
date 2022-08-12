#include <bits/stdc++.h>
using namespace std;

int cnt = 0;


void Hanoi(int n, int start, int end){
    if(n == 1){
        cout << start << ' ' << end << '\n';
        return ;
    }
    Hanoi(n-1, start, 6-start-end);
    cout << start << ' ' << end << '\n';
    Hanoi(n-1, 6-start-end, end);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << int(pow(2, n))-1 << '\n';
    Hanoi(n, 1, 3);
}