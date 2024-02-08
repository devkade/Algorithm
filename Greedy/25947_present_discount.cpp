#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

double price[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, b, a;
    double sum = 0, res = 0;

    cin >> n >> b >> a;

    for(int i = 0; i < n; i++){
        cin >> price[i];
    }

    sort(price, price+n);

    for(int i = 0; i < a; i++){
        sum += price[i]/2;
        if(sum > b){
            cout << res << endl;
            exit(0);
        }
        res++;
        if(i == n-1) {
            break;
        }
    }

    for(int i = a; i < n; i++){
        sum += price[i-a] / 2;
        sum += price[i] / 2;
        if(sum > b){
            break;
        }
        res++;
    }

    cout << res << endl;

    return 0;
}