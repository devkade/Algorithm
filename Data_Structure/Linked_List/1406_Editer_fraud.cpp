// ���Ḯ��Ʈ �߸� Ǯ�̹�
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
    N = str.size();     // ���ڿ��� ����
    for(auto elem : str){       // ���ڿ��� ���ڸ� ���Ḯ��Ʈ�� �ڷ�ȭ
        insert(cursor, elem);
        cursor++;
    }

    for (int i = 0; i < M; i++)             // ����Ű�� ������ ��
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
                if(pre[cursor] != -1){          // Ŀ���� ���� dat�� �� pre�� ��
                    erase(cursor);              // dat�� ���� �ϸ� Ŀ���� �ϳ� �� �������� ��ġ�ϰ� ��
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