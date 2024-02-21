#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int t, n, x, y;
long long a[20002];
int res = 0;

void Initialize(){
    fill(a, a+n, 0);
    res = 0;
}

void Input(){
    cin >> n >> x >> y;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

void Solution(){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((a[i]+a[j])%x != 0 || abs(a[i]-a[j])%y!=0) continue;
            res++;
        }
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        Input();
        Solution();
        Initialize();
    }

    return 0;
}