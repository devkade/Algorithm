#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        bool isOK = true;
        string str;
        getline(cin, str);
        if(str == ".") break;
        stack<char> s;              // ������ while�ȿ� �־�� �ʱ�ȭ��
        for(auto c : str){
            if(c == '(' || c == '['){
                s.push(c);
            }
            else if(c == ')'){
                if(s.empty() || s.top() != '('){
                    isOK = false;
                    break;
                }
                s.pop();
            }
            else if(c == ']'){
                if(s.empty() || s.top() != '['){
                    isOK = false;
                    break;
                }
                s.pop();
            }
        }
        if(s.empty() == false) isOK = false;
        if(isOK) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}