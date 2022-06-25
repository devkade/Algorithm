// 연결리스트
#include <bits/stdc++.h>

using namespace std;

const int MX = 10005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

int erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
    return addr;
}

void insert(int addr, int d){
    dat[unused] = d;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void traverse(){
    int cur = nxt[0];
    while(cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    list<int> L = {};
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        insert(i, i+1);
    }
    cout << "<";
    int cursor = 0;
    // 연결리스트에서 해당되는 숫자 선택해 출력
    while(nxt[0] != -1){
        for (int i = 0; i < K; i++)
        {
            if(nxt[cursor] != -1)
                cursor = nxt[cursor];
            else
                cursor = nxt[0];
        }
        cout << erase(cursor);
        if(nxt[0] != -1)
            cout << ", ";
    }

    cout << '>';
    return 0;
}