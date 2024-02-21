#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#define endl '\n'
using namespace std;

int LCS[1002][1002];
string s1, s2;
stack<char> st;

void Input(){
    cin >> s1 >> s2;
}

void Solution(){
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    for(int i=1; i<s1.length(); i++){
        for(int j=1; j<s2.length(); j++){
            if(s1[i] == s2[j])
                LCS[i][j] = LCS[i-1][j-1]+1;
            else{
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    int i = s1.length()-1;
    int j = s2.length()-1;
    while(LCS[i][j]){
        if(LCS[i][j] == LCS[i-1][j]){
            i--;
        }
        else if(LCS[i][j] == LCS[i][j-1]){
            j--;
        }
        else{
            st.push(s1[i]);
            i--;j--;
        }
    }

    cout << LCS[s1.length()-1][s2.length()-1] << endl;
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();

    return 0;
}