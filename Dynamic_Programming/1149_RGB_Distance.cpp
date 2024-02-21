#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define red 0
#define green 1
#define blue 2
using namespace std;

int house[1003][3];
int N;
int dp[1003][3];
int res = 0;
stack<pair<int, int>> st;

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            int val;
            cin >> val;
            house[i][j] = val;
        }
    }
}

void revDfs(int idx){
    int numhs = 0;
    dp[numhs][idx] += house[numhs][idx];
    st.push({numhs+1, idx});

    while(!st.empty()){
        int num = st.top().first;
        int prev = st.top().second;
        st.pop();
        if(num == N) continue;
        for(int i=0; i<3; i++){
            if(prev == i) continue;
            if(dp[num][i] != 0 && dp[num][i] <= dp[num-1][prev] + house[num][i])
                continue;
            dp[num][i] = dp[num-1][prev] + house[num][i];
            st.push({num+1, i});
        }       
    }
}

void Solution(){
    for(int i=0; i<N; i++){
        revDfs(i);
    }
    cout << min({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}