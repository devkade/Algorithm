#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[MX];
int head=0, tail=0;

void push(int x){
    dat[tail++]=x;
}

void pop(){
    if(head < tail) head++;
}

void size(){
    cout << tail - head << endl;
}

int empty(){
    if(head == tail) return 1;
    else return 0;
}

void front(){
    if(empty()) cout << -1 << endl;
    else cout << dat[head] << endl;
}

void back(){
    if(empty()) cout << -1 << endl;
    else cout << dat[tail-1] << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str == "push"){
            int p;
            cin >> p;
            push(p);
        }
        else if(str == "pop"){
            if(!empty()){
                front();
                pop();
            }
            else cout << -1 << endl;
        }
        else if(str == "size") size();
        else if(str == "empty") cout << empty() << endl;
        else if(str == "front"){
            if(empty()) cout << -1 << endl;
            else cout << dat[head] << endl;
        }
        else if(str == "back"){
            if(empty()) cout << -1 << endl;
            else cout << dat[tail-1] << endl;
        } 
    }
    return 0;
}