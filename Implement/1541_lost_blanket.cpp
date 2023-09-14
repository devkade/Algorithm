#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string input, num;

    cin >> input;

    int start = 0, temp=0, idx = 0, is_minus=0, res=0;
 
    // - +++의 경우, -가 연속되는 경우, 
    for(int i=0; i<input.length(); i++){
        if(isdigit(input[i])){
            temp = temp*10 + (input[i]-48);
        }
        else{
            if(is_minus==1){
                res -= temp;
            }
            else{
                if(input[i] == '-'){
                    is_minus = 1;
                    res += temp;
                }
                else{
                    res += temp;
                }
            }
            temp = 0;
        }
    }
    if(is_minus) res -= temp;
    else res += temp;
    
    cout << res << '\n';

    return 0;
}