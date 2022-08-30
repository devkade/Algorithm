#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    int n;
    ll sum = 0, height;
    cin >> n;
    while(n--){
        cin >> height;
        if(s.empty()) s.push(height);
        else{
            while(!s.empty() && s.top() <= height){
                s.pop();
            }
            sum += s.size();
            s.push(height);
        }
    }
    cout << sum << endl;

    return 0;
}