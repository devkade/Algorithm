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
        cntA = cntB = 0;            // �ʱ�ȭ
        isOK = trueȭ
        for(char c : str){
            if(s.empty()){          // ������ ����� �� ó��
                if(c == 'A') cntA++;
                else cntB++;
                s.push(c);
            }
            else{                   // ������ ������� ���� ��
                if(s.top() == c){   // ���� �� pair�� ��� pop
                    if(c == 'A') cntA--;
                    else cntB--;
                    s.pop();
                }
                else{               // ���� ������ ���ÿ� �־���
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
        if(s.empty() && cntA == 0 && cntB == 0) sum++; // ��, ���� �Ǵ�
    }
    cout << sum << endl;
    return 0;
}