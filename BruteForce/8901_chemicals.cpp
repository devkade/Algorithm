#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int a, b, c, T;
    int ab, bc, ca;

    cin >> T;

    while(T--){
        cin >> a >> b >> c;
        cin >> ab >> bc >> ca;

        int res = 0;

        for(int i = 0; i <= min(a, b); i++){
            int temp = ab * i;
            int na = a - i;
            int nb = b - i;
            if(bc < ca){
                int aORc = min(na, c);
                temp += ca * aORc;
                int nc = c - aORc;
                na = na - aORc;
                temp += bc * min(nb, nc);
            }
            else{
                int bORc = min(nb, c);
                temp += bc * bORc;
                int nc = c - bORc;
                nb = b - bORc;
                temp += ca * min(nc, na);
            }
            res = max(res, temp);
        }
        cout << res << endl;
    }

    return 0;
}