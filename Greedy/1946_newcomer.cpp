#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, is_pass = 1;
    pair<int, int> rank[100005];

    cin >> T;

    while(T--){
        int res = 1;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> rank[i].first >> rank[i].second;
        }
        sort(rank, rank+N, compare);

        int idx = 0;
        for(int i = 1; i < N; i++){
            if(rank[i].second < rank[idx].second){
                res++;
                idx = i;
            }
        }
        cout << res << '\n';
    }

    return 0;
}