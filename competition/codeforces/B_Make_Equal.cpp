#include <iostream>

#define endl '\n'
using namespace std;

int t, n, a[20003];
long long sum = 0;

void Initialize(){
    fill(a, a+n, 0);
    sum = 0;
}

void Input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
}

void Solution(){
    long long avg = sum / n;
    long long remain = 0;
    for(int i=0; i<n; i++){
        if(a[i] > avg){
            remain += a[i]-avg;
        }
        else if(a[i] < avg){
            if(avg-a[i] > remain){
                cout << "NO" << endl;
                return;
            }
            remain -= avg-a[i];
        }
    }
    if(remain != 0){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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