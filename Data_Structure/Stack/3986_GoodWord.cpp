#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, cntA, cntB, sum = 0;
    bool isOK = true;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        stack<char> s;
        cntA = cntB = 0;            // 초기화
        isOK = true화
        for(char c : str){
            if(s.empty()){          // 스택이 비었을 때 처리
                if(c == 'A') cntA++;
                else cntB++;
                s.push(c);
            }
            else{                   // 스택이 비어있지 않을 때
                if(s.top() == c){   // 같을 때 pair로 묶어서 pop
                    if(c == 'A') cntA--;
                    else cntB--;
                    s.pop();
                }
                else{               // 같지 않으면 스택에 넣어줌
                    if(c == 'A'){
                        cntA++;
                        s.push(c);
                    }
                    else if(c == 'B'){
                        cntB++;
                        s.push(c);
                    }
                        
                }
            }
        }
        if(s.empty() && cntA == 0 && cntB == 0) sum++; // 참, 거짓 판단
    }
    cout << sum << endl;
    return 0;
}