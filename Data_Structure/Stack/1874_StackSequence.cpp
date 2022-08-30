#include <bits/stdc++.h>

using namespace std;


int N, k=1;
string str = "";

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    stack<int> s;
    
    cin >> N;
    while(N--){
        int val;
        cin >> val;
        if(val > k){
            while(k <= val){
                str += "+\n";
                s.push(k++);
            }
            str += "-\n";
            s.pop();
        }
        else if(val == k){
            str += "+\n";
            str += "-\n";
            k++;
        }
        else{
            if(s.empty()) continue;
            if(val != s.top()){
                cout << "NO\n";
                return 0;
            }
            else{
                str += "-\n";
                s.pop();
            }
        }
    }
    cout << str;
}