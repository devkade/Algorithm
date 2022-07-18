#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        stack<char> s;
        bool isOK = true;
        for(char c : str){
            if(c == '(') s.push(c);
            else{
                if(s.empty() || s.top() != '(') isOK = false;
                else s.pop();
            }
        }
        if(!s.empty() || isOK == false) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}