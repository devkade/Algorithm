#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int K, N;
int lan[10005];

int search(LL start, LL end){
    LL sum, mid;
    while(start <= end){
        sum = 0;
        mid = (start + end)/2;
        for(int i=0; i<K; i++){
            sum += lan[i] / mid;
        }
        if (sum >= N) start = mid + 1;
        else end = mid - 1;
    }
    return end;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    LL val, high=0;

    cin >> K >> N;
    
    for(int i=0; i<K; i++){
        cin >> lan[i];
        if (high < lan[i]) high=lan[i];
    }

    cout << search(1, high) << '\n';

    

    return 0;
}