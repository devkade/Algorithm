#include <bits/stdc++.h>
using namespace std;

int res = 0;
stack<int> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++){
        cout << res << endl;
        if(str[i] == '('){
            s.push(str[i]);
        }
        else{           // str[i] == ')' 일 때 
            if(str[i-1] == '('){        // 레이져일 때
                s.pop(); 
                res += s.size();
            }
            else{                       // 막대기의 끝일 때
                s.pop();
                res += 1;
            }
        }
    }

    cout << res << endl;


    return 0;
}