#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100005

int seq[MAX];
int head_idx = 1, n, len;
bool is_head = true, is_error = false;
string p, num;

void parse(){
    int start = 0;
    int idx = 1;
    for(int i=1; i<num.length()-1; i++){
        if(num[i] == ',') continue;
        if(num[i+1] == ',' || num[i+1] == ']'){
            seq[idx++] = stoi(num.substr(i-start, start+1));
            start = 0;
        }
        else{
            start++;
        }
    }
}

void func(){
    for(int i=0; i<p.length(); i++){
        if(p[i] == 'R'){
            if(is_head) is_head = false;
            else is_head = true;
        }
        else{
            if(head_idx == n){
                is_error = true;
                return;
            }
            if(is_head) head_idx++;
            else n--;
        }
    }
}

void print(){
    cout << '[';
    if(is_head){
        for(int i=head_idx; i<n; i++) {
            cout << seq[i];
            if(i != n-1) cout << ',';
        }
    }
    else{
        for(int i=n-1; i>=head_idx; i--) {
            cout << seq[i];
            if(i != head_idx) cout << ',';
        }
    }
    cout << ']' << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        head_idx = 1;
        is_head = true;
        is_error = false;
        fill(seq, seq+MAX, 0);
        cin >> p >> n >> num;
        n++;
        parse();
        func();
        if(is_error) {
            cout << "error" << endl;
            continue;
        }
        print();
        
    }


    return 0;
}