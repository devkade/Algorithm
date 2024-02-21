#include <iostream>

#define endl '\n'
using namespace std;

int N, work[100001], res;

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        int val;
        cin >> val;
        work[val]++;
        if(work[val] > res){
            res = work[val];
        }
    }
}

void Solution(){
    if(N % 2 == 0){
        if(res > N/2) {
            cout << "NO" << endl;
            return;
        }
    }
    else{
        if(res > N/2+1){
            cout << "NO" << endl;
            return;
        } 
    }
    cout << "YES" << endl;
}

int main(){
   ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}