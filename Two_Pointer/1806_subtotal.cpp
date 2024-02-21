#include <iostream>

#define endl '\n'
using namespace std;

int N, S;
int arr[100001];
int res, sum=0;

void Input(){
    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
}

void Solution(){
    res = INT32_MAX;
    sum = arr[0];
    int start = 0;
    int end = 0;
    while(start <= end && end < N){
        if(sum >= S) res = min(res, end-start+1);
        if(sum < S){
            end++;
            sum += arr[end];
        }
        else{
            sum -= arr[start];
            start++;
        }
    }
    if(res == INT32_MAX) cout << 0 << endl;
    else cout << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}