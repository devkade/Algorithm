#include <iostream>
#include <stack>
#include <vector>
#define endl '\n'
using namespace std;

int phone[100001];
int N, res = 0;
stack<int> st;
int vis[100001];

void Input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> phone[i];
    }
}

void dfs(){
    while(!st.empty()){
        int cur = st.top(); st.pop();
        if(vis[phone[cur]] == 1) continue;
        st.push(phone[cur]);
        vis[phone[cur]] = 1;
    }
}

void Solution(){
    for(int i=1; i<=N; i++){
        st.push(i);
    }
    dfs();

    for(int i=1; i<=N; i++){
        if(phone[i] == i){
            res++;
            phone[i] = (i%N)+1;
        }
    }

    cout << res << endl;
    for(int i=1; i<=N; i++)
        cout << phone[i] << ' ';
}

int main(){
   ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}