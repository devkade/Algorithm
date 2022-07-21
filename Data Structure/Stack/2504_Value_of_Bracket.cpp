// 분배법칙을 사용해서 하나씩 곱해주는 부분으로 코드 구성
#include <bits/stdc++.h>
using namespace std;

stack<int> s;
string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    int sum = 0;
    int num = 1;
    for(int i = 0; i <str.size(); i++){
        if(str[i] == '('){
            num *= 2;
            s.push(str[i]);
        }
        else if(str[i] == '['){
            num *= 3;
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            if(s.empty() || s.top() != '('){
                cout << 0;
                return 0;
            }
            if(str[i-1] == '(') sum += num;
            s.pop();
            num /= 2;
        }
        else{   // str[i] == ']'
            if(s.empty() || s.top() != '['){
                cout << 0;
                return 0;
            }
            if(str[i-1] == '[') sum += num;
            s.pop();
            num /= 3;
        }
    }
    if(s.empty()) cout << sum;
    else cout << 0;
}