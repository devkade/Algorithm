#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int n, sum=0, res;
vector<int> vec;

void Input(){
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        exit(0);
    }
}

void eratos(int n){
    vector<int> prime(n+1, 1);

    for(int i=2; i*i<=n; ++i){
        if(prime[i]){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = 0;
            }
        }
    }

    for(int i=2; i<=n; ++i){
        if(prime[i]) vec.push_back(i);
    }
}

void Solution(){
    eratos(n);
    int start = 0; 
    int end = 0;
    res = 0;
    while(start<=end && end<=vec.size()){
        if(sum < n){
            sum+=vec[end];
            end++;
        }
        else{
            sum-=vec[start];
            start++;
        }
        if(sum == n) res++;
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();

    return 0;
}