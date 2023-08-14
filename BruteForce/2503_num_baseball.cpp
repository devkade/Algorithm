#include <bits/stdc++.h>
using namespace std;

string nums[105];
int strikes[105], balls[105], fail[1005] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int N, s, b, res = 0;
    char hunds, tens, ones;
    string question;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> question >> s >> b;
        nums[i] = question;
        strikes[i] = s;
        balls[i] = b;
    }

    for(int i = 123; i <= 987; i++){
        string temp = to_string(i);
        hunds = temp[0];
        tens = temp[1];
        ones = temp[2];
        
        if(hunds == tens || hunds == ones || tens == ones) continue;
        if(tens == '0' || ones == '0') continue;

        for(int j = 0; j < N; j++){
            s = 0;
            b = 0;
            question = nums[j];
            for(int k=0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    if(temp[k] == question[l]){
                        if(k == l) s++;
                        else b++;
                    }
                }
            }
            if(s != strikes[j] || b != balls[j])
                fail[i] = 1;
        }
    }

    for(int i = 123; i <= 987; i++){
        string temp = to_string(i);
        hunds = temp[0];
        tens = temp[1];
        ones = temp[2];
        if(hunds == tens || hunds == ones || tens == ones) continue;
        if(tens == '0' || ones == '0') continue;

        if (fail[i] == 0) res++;
    }

    cout << res << '\n';

    return 0;
}