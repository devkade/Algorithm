#include <iostream>
#include <vector>
#include <queue>
#define endl '\n';
using namespace std;

vector<int> party[51] = {};  // N, i번째 사람의 참가하는 파티 번호
vector<int> participant[51] = {};  // M, 파티 참가자
int truth[51];
int N, M, res=0;
queue<int> q;

void Input(){
    cin >> N >> M;
    int val;
    cin >> val;
    for(int j=1; j<=val; j++){
        int number;
        cin >> number;
        truth[number] = 1;
        q.push(number);
    }
    for(int i=1; i<=M; i++){
        int val;
        cin >> val;
        for(int j=1; j<=val; j++){
            int number;
            cin >> number;
            party[number].push_back(i);
            participant[i].push_back(number);
        }
    }
}

void bfs(){
    while(!q.empty()){
        int number = q.front(); q.pop();
        for(auto partyNum : party[number]){
            for(auto temp : participant[partyNum]){
                if(truth[temp] == 1) continue;
                truth[temp] = 1;
                q.push(temp);
            }
        }
    }
}

void Solution(){
    bfs();
    for(int i=1; i<=M; i++){
        int flag = 1;
        for(auto number : participant[i]){
            if(truth[number]==1){
                flag = 0;
                break;
            }
        }
        if(flag){
            res++;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();
    cout << res << endl;


    return 0;
}