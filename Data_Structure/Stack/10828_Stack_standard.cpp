#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<int> s;
    int N;
    cin >> N;
    while(N--){
        string str;
        cin >> str;
        if(str == "push"){
            int p;
            cin >> p;
            s.push(p);
        }
        else if(str == "pop"){
            if(s.empty())   cout << -1 << endl;
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if(str == "size"){
            cout << s.size() << endl;
        }
            
        else if(str == "empty"){
            if(s.empty()){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(str == "top"){
            if(s.empty()) cout << -1 << endl;
            else cout << s.top() << endl;
        }
    }
    return 0;
}