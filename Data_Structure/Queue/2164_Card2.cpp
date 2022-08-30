#include <bits/stdc++.h>

using namespace std;

int N;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie();
    queue<int> Q;
    cin >> N;
    for(int i = 1; i <= N; i++){
        Q.push(i);
    }
    while(true){
        if(Q.size() == 1) break;
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout << Q.front() << endl;

    return 0;
}