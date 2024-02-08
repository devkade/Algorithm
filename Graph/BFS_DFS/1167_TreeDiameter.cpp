#include <iostream>
#include <vector>
#include <stack>
#define endl '\n';
using namespace std;

int V;
vector<pair<int, int>> vec[100001];
stack<pair<int, int>> st;
int vis[100002], res = 0;

void Initialize(){
    fill(vis, vis+100002, 0);
}

void Input(){
    cin >> V;
    for(int i = 1; i <= V; i++){
        int start, end, dist;
        cin >> start;
        while(true){
            cin >> end ;
            if(end == -1) break;
            cin >> dist;
            vec[start].push_back({end, dist});
        }
    }
}

int dfs(int start){
    st.push({start, 0});
    vis[start] = 1;

    int max_v = 0, max_dist = 0;
    
    while(!st.empty()){
        auto info = st.top(); st.pop();
        int prev_v = info.first;
        int prev_dist = info.second;

        if(max_dist < prev_dist){
            max_dist = prev_dist;
            max_v = prev_v;
        }

        for(auto nxt : vec[prev_v]){
            int cand_v = nxt.first;
            int cand_dist = nxt.second;
            if (vis[cand_v] == 1 || prev_v == cand_v) continue;

            st.push({cand_v, prev_dist + cand_dist});
            vis[cand_v] = 1;
        }
    }
    if(res < max_dist) res = max_dist;
    return max_v;
}

void Solution(){
    int max_v = dfs(1);
    Initialize();
    max_v = dfs(max_v);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}