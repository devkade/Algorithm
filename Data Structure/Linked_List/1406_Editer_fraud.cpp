// 연결리스트 야매 풀이법
#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char data){
    dat[unused] = data;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    string str;
    int N, M, cursor=0;
    char inp;
    cin >> str >> M;
    N = str.size();     // 문자열의 길이
    for(auto elem : str){       // 문자열의 문자를 연결리스트로 자료화
        insert(cursor, elem);
        cursor++;
    }

    for (int i = 0; i < M; i++)             // 조작키를 눌렀을 때
    {
        cin >> inp;
        switch (inp){
            case 'L':
                if(pre[cursor] != -1) cursor = pre[cursor];
                break;
            case 'D':
                if(nxt[cursor] != -1) cursor = nxt[cursor];
                break;
            case 'B':
                if(pre[cursor] != -1){          // 커서의 차이 dat일 때 pre일 때
                    erase(cursor);              // dat일 때로 하면 커서가 하나 더 이전으로 위치하게 됨
                    cursor = pre[cursor];
                }
                
                break;
            case 'P':
                char c1;
                cin >> c1;
                insert(cursor, c1);
                cursor = nxt[cursor];
                break;
        }
    
    }
    
    traverse();

    return 0;
}