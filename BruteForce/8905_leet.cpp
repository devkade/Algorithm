#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int k;
string original, leet_word;
string leet_mapping[30];

bool isPossible(int o_idx, int l_idx){
    if(o_idx == original.length() && l_idx == leet_word.length()){
        return true;
    }
    if(o_idx == original.length() || l_idx == leet_word.length()){
        return false;
    }
    int alpha_idx = original[o_idx]-'a';
    if(leet_mapping[alpha_idx] == ""){
        for(int i = 1; i <= k && l_idx + i <= leet_word.length(); i++){
            leet_mapping[alpha_idx] = leet_word.substr(l_idx, i);
            if(isPossible(o_idx+1, l_idx+i)){
                return true;
            }
        }
        leet_mapping[alpha_idx] = "";
    }
    else{
        string mapped_leet = leet_mapping[alpha_idx];
        if(mapped_leet == leet_word.substr(l_idx, mapped_leet.length())){
            if(isPossible(o_idx+1, l_idx+mapped_leet.length())){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        fill(leet_mapping, leet_mapping+30, "");
        cin >> k >> original >> leet_word;
        bool res = isPossible(0, 0);
        if(res) cout << 1 << endl; 
        else cout << 0 << endl;
    }

    return 0;
}