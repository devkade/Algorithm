#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos++] = x;
}

int pop(){
    if(pos > 0){
        pos--;
        return dat[pos];
    }
    return -1;
}

int size(){
    return pos;
}

bool empty(){
    if(pos == 0){
        return 1;
    }
    return 0;
}

int top(){
    if(pos == 0) return -1;
    return dat[pos-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string str;
    int p;
    while(n--){
        cin >> str;
        if(str == "push"){
            cin >> p;
            push(p);
        }
        else if(str == "pop")
            cout << pop() << endl;
        else if(str == "size")
            cout << size() << endl;
        else if(str == "empty")
            cout << empty() << endl;
        else if(str == "top")
            cout << top() << endl;
    }
    return 0;
}