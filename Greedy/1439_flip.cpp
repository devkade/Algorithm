#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int flip = 0, one=0, zero=0, is_changed = 0;
    string num;

    cin >> num;


    char target;

    if(num.size() == one || num.size() == zero){
        cout << 0 << '\n';
        exit(0);
    }


    if(num[0] == '0') zero++;
    else one++;
    target = num[0];

    for(int i = 1; i < num.size(); i++){
        if(target != num[i]) {
            is_changed = 1;
            if(num[i] == '0') zero++;
            else one++;
            target = num[i];
        }
    }

    if(zero > one) flip = one;
    else flip = zero;

    cout << flip << '\n';

    return 0;
}