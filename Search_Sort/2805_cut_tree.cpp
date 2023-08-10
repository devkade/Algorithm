#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL N, M;
LL height[1000001];

LL search(int start, int end){
    LL sum, mid;
    while(start <= end){
        mid = (start + end)/2;
        sum = 0;
        for(int i=0; i<N; i++){
            if (height[i] - mid < 0) continue;
            sum += height[i] - mid;
        }
        if (sum == M) start++;
        else if(sum < M) end = mid-1;
        else start = mid+1;

    }
    return end;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int val, MAX = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> val;
        if (MAX < val) MAX = val;
        height[i] = val;
    }


    cout << search(0, MAX) << '\n';

    return 0;
}