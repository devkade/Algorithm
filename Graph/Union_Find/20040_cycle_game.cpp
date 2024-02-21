#include <iostream>

#define endl '\n'
using namespace std;

int N, M;
int parent[500001];
int res = 0;

void Input(){
    cin >> N >> M;
}

int Find(int i){
    if(parent[i]==i) return i;
    else return parent[i] = Find(parent[i]);
}

int Union(int i, int j){
    i = Find(i);
    j = Find(j);
    if(i==j) {
        return 1;
    }
    else{
        parent[i] = j;
        return 0;
    }
}

void Solution(){
    for(int i=1; i<=N; i++){
        parent[i]=i;
    }
    for(int i=1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        if(Union(a, b)){
            res = i;
            break;
        }
    }
    if(res == 0) cout << 0 << endl;
    else cout << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();

    return 0;
}