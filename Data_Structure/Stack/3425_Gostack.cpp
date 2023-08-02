#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
typedef long long LL;
stack<LL> st;

bool num(long long x){
    st.push(x);
    return false;
}

bool pop(){
    // 스택에 아무것도 없을 때
    if (st.empty()) return true;

    st.pop();
    return false;
}

bool inv(){
    // 스택에 아무것도 없을 때
    if (st.empty()) return true;

    int temp;
    temp = -st.top();
    st.pop();
    st.push(temp);
    return false;
}

bool dup(){
    if (st.empty()) return true;
    int temp;
    temp = st.top();
    st.push(temp);
    return false;
}

bool swp(){
    if (st.size() < 2) return true;
    int fst, snd;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    st.push(fst);
    st.push(snd);
    return false;
}
bool add(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    temp = fst + snd;
    st.push(temp);
    return false;
}
bool sub(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    temp = snd-fst;
    st.push(temp);
    return false;
}
bool mul(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    temp = snd*fst;

    st.push(temp);
    return false;
}
bool div(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    bool minus = false;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    if (fst == 0) return true;

    // 음수일 때 연산 조건 추가
    if ((snd > 0 && fst < 0) || (snd < 0 && fst > 0)) minus = true;
    temp = abs(snd) / abs(fst);
    if (minus == true) temp = -temp;
    st.push(temp);
    return false;
}
bool mod(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    bool minus = false;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    if (fst == 0) return true;
    
    if (snd < 0) minus = true;
    temp = abs(snd) % abs(fst);
    if (minus == true) temp = -temp;
    st.push(temp);
    return false;
}

int main(){
    LL n, val, cnt = 0;
    bool error;
    string str;
    vector<string> cmd;
    vector<int> n_val;


    while(true){
        error = false;
        cmd.clear();
        n_val.clear();
        while(true){
            cin >> str;
            if (str == "NUM") {
                cin >> val;
                n_val.push_back(val);
            }
            else if (str == "QUIT") {
                return 0;
            }
            else if (str == "END") {
                break;
            }
            cmd.push_back(str);
        }
        cin >> n;

        while(n--){
            cnt = 0;
            cin >> val;
            st.push(val);
            
            for(int i=0; i<cmd.size(); i++){
                if (cmd[i] == "NUM") st.push(n_val[cnt++]);
                else if (cmd[i] == "POP") error = pop();
                else if (cmd[i] == "INV") error = inv();
                else if (cmd[i] == "DUP") error = dup();
                else if (cmd[i] == "SWP") error = swp();
                else if (cmd[i] == "ADD") error = add();
                else if (cmd[i] == "SUB") error = sub();
                else if (cmd[i] == "MUL") error = mul();
                else if (cmd[i] == "DIV") error = div();
                else if (cmd[i] == "MOD") error = mod();

                if (!st.empty() && (st.top() > MAX || st.top() < -MAX)){
                    error = true;
                    break;
                }
            }
            
            if ((st.size() == 1) && error == false) {
                cout << st.top() << endl;
            }
            else {
                cout << "ERROR" << endl;
            }
            while(!st.empty()) {
                st.pop();
            }
            
        }
        cout << endl;
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
typedef long long LL;
stack<LL> st;

bool num(long long x){
    st.push(x);
    return false;
}

bool pop(){
    // 스택에 아무것도 없을 때
    if (st.empty()) return true;

    st.pop();
    return false;
}

bool inv(){
    // 스택에 아무것도 없을 때
    if (st.empty()) return true;

    int temp;
    temp = -st.top();
    st.pop();
    st.push(temp);
    return false;
}

bool dup(){
    if (st.empty()) return true;
    int temp;
    temp = st.top();
    st.push(temp);
    return false;
}

bool swp(){
    if (st.size() < 2) return true;
    int fst, snd;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    st.push(fst);
    st.push(snd);
    return false;
}
bool add(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    temp = fst + snd;
    st.push(temp);
    return false;
}
bool sub(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    temp = snd-fst;
    st.push(temp);
    return false;
}
bool mul(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    temp = snd*fst;

    st.push(temp);
    return false;
}
bool div(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    bool minus = false;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    if (fst == 0) return true;

    // 음수일 때 연산 조건 추가
    if ((snd > 0 && fst < 0) || (snd < 0 && fst > 0)) minus = true;
    temp = abs(snd) / abs(fst);
    if (minus == true) temp = -temp;
    st.push(temp);
    return false;
}
bool mod(){
    if (st.size() < 2) return true;
    LL temp, fst, snd;
    bool minus = false;
    fst = st.top();
    st.pop();
    snd = st.top();
    st.pop();
    if (fst == 0) return true;
    
    if (snd < 0) minus = true;
    temp = abs(snd) % abs(fst);
    if (minus == true) temp = -temp;
    st.push(temp);
    return false;
}

int main(){
    long long n, val, cnt = 0;
    bool error;
    string str;
    vector<string> cmd;
    vector<int> n_val;


    while(true){
        error = false;
        cmd.clear();
        n_val.clear();
        while(true){
            cin >> str;
            if (str == "NUM") {
                cin >> val;
                n_val.push_back(val);
            }
            else if (str == "QUIT") {
                return 0;
            }
            else if (str == "END") {
                break;
            }
            cmd.push_back(str);
        }
        cin >> n;

        while(n--){
            cnt = 0;
            cin >> val;
            st.push(val);
            
            for(int i=0; i<cmd.size(); ++i){
                if (cmd[i] == "NUM") error = num(n_val[cnt++]);
                else if (cmd[i] == "POP") error = pop();
                else if (cmd[i] == "INV") error = inv();
                else if (cmd[i] == "DUP") error = dup();
                else if (cmd[i] == "SWP") error = swp();
                else if (cmd[i] == "ADD") error = add();
                else if (cmd[i] == "SUB") error = sub();
                else if (cmd[i] == "MUL") error = mul();
                else if (cmd[i] == "DIV") error = div();
                else if (cmd[i] == "MOD") error = mod();

                if (!st.empty() && (st.top() > MAX || st.top() < -MAX))
                    error = true;    
                
                if (error) break;
            }
            
            if ((st.size() == 1) && error == false) {
                cout << st.top() << endl;
            }
            else {
                cout << "ERROR" << endl;
            }
            while(!st.empty()) {
                st.pop();
            }
            
        }
        cout << endl;
    }

    return 0;
}