#include <bits/stdc++.h>
using namespace std;

int num[1000001];

int main(){
    int N, val;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> val;
        num[i] = val;
    }

    sort(num, num+N);

    for(int i=0; i<N; i++){
        cout << num[i] << '\n';
    }

    return 0;
}