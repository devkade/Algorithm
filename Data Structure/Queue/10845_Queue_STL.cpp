#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    queue<int> q;
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str == "push"){
            int p;
            cin >> p;
            q.push(p);
        }
        else if(str == "front"){
            if(q.empty()) cout << -1 << endl;
            else cout << q.front() << endl;
        }
        else if(str == "back"){
            if(q.empty()) cout << -1 << endl;
            else cout << q.back() << endl;
        }
        else if(str == "size") cout << q.size() << endl;
        else if(str == "empty") cout << int(q.empty()) << endl;
        else if(str == "pop"){
            if(q.empty()) cout << -1 << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
    return 0;
}