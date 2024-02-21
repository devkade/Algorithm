#include <iostream>
#include <stack>
#include <string>
#define endl '\n'
using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";
int t, n;
stack<int> st;

void Input(){
    cin >> t;
}

void Solution(){
    while(t--){
        int remain = 3;
        cin >> n;
        while(remain){
            for(int i=26; i>0; i--){
                if(n - i >= remain-1){
                    n = n-i;
                    remain--;
                    st.push(i-1);
                    break;
                }
            }
        }
        while(!st.empty()){
            cout << alphabet[st.top()];
            st.pop();
        }
        cout << endl;
    }
}

int main(){
   ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}