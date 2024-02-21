#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, K;
long long res=0;
pair<int, int> jewelry[300001];
int bag[300001];
priority_queue<int> pq;

void Input(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        int m, v;
        cin >> m >> v;
        jewelry[i] = make_pair(m, v);
    }
    for(int i=0; i<K; i++){
        cin >> bag[i];
    }
}

void Solution(){
    sort(jewelry, jewelry+N);
    sort(bag, bag+K);

    int j = 0;

    for(int i=0; i<K; i++){
        while(j < N && bag[i] >= jewelry[j].first){
            pq.push(jewelry[j].second);
            j++;
        }
        if(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}