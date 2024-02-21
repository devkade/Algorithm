#include <iostream>

#define endl '\n'
using namespace std;

int N, M;
int s, e;
int num[2002];
int dp[2002][2002];

void Input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> num[i];
    }
}

void Solution(){
    for(int i=1; i<=N; i++){
        dp[i][i] = 1;
    }
    for(int i=0; i<N; i++){
        if(num[i] == num[i+1]){
            dp[i][i+1]=1;
        }
    }
    for(int r=3; r<=N; r++){
        for(int st=1; st<=N-r+1; st++){
            int end = st+r-1;

            if(num[st]==num[end] && dp[st+1][end-1]){
                dp[st][end] = 1;
            }
        }
    }

    cin >> M;
    for(int i=0; i<M; i++){
        cin >> s >> e;
        cout << dp[s][e] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();

    return 0;
}