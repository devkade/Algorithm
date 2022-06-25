#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    int K;
    cin >> K;
    stack<int> s;
    while(K--){
        int p;
        cin >> p;
        if(p != 0){
            s.push(p);
        }
        else{
            if(!s.empty()){
                s.pop();
            }
        }
    }
    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum << endl;
    return 0;
}