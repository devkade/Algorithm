#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x){
    dat[--head] = x;
}

void push_back(int x){
    dat[tail++] = x;
}

int pop_front(){
    if(tail-head == 0) return -1;
    else {
        return dat[head++];
    }
}

int pop_back(){
    if(tail-head == 0) return -1;
    else {
        return dat[--tail];
    }
}

int size(){
    return tail-head;
}

int empty(){
    if(tail-head == 0) return 1;
    return 0;
}

int front(){
    if(tail-head == 0) return -1;
    return dat[head];
}

int back(){
    if(tail-head == 0) return -1;
    return dat[tail-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str == "push_front"){
            int i;
            cin >> i;
            push_front(i);
        }
        else if(str == "push_back"){
            int i;
            cin >> i;
            push_back(i);
        }
        else if(str == "pop_front"){
            cout << pop_front() << endl;
        }
        else if(str == "pop_back"){
            cout << pop_back() << endl;
        }
        else if(str == "size"){
            cout << size() << endl;
        }
        else if(str == "empty"){
            cout << empty() << endl;
        }
        else if(str == "front"){
            cout << front() << endl;
        }
        else cout << back() << endl;
    }

    return 0;
}