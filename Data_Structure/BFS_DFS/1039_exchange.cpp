#include <bits/stdc++.h>
using namespace std;

int depth[1000001];
int visit[1000001] = {};
string N;
int res = 0, K, level=0;
queue<pair<string, int>> q;
queue<int> max_q;

string Swap(string str, int i, int j){
    char temp;
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    return str;
}


void bfs(){
    int stage = 0;
    while(q.empty()==0){
        string str = q.front().first;
        level = q.front().second;
        if (stage != level) {
            stage = level;
            fill(visit, visit+1000001, 0);
        }
        if (level == K) {
            max_q.push(stoi(str));
            q.pop();
            continue;
        }

        for(int i=0; i<N.size()-1; i++){
            for(int j=i+1; j<N.size(); j++){
                string change = str;
                if(i==0 && str[j] == '0') continue;
                change = Swap(str, i, j);

                int val = stoi(change);
                // 방문 여부 확인
                if (!visit[val]){
                    visit[val] = 1;
                    q.push({change, level+1});
                }                 
            }
        }
        q.pop();
    }
}

int main(){
    ios::sync_with_stdio(true);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;

    q.push({N, 0});

    if (K==0){
        cout << N << endl;
        exit(0);
    }
    else if (N.size() == 1 || (N.size() == 2 && stoi(N) % 10 == 0)){
        cout << -1 << endl;
        exit(0);
    }

    bfs();

    while(!max_q.empty()){
        if(res < max_q.front()){
            res = max_q.front();
        }
        max_q.pop();
    }

    cout << res << endl;


    return 0;
}