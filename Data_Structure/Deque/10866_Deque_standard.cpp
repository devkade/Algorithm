#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    deque<int> D;
    int N;
    cin >> N;
    while(N--){
        string str;
        cin >> str;
        if(str == "push_front"){
            int i;
            cin >> i;
            D.push_front(i);
        }
        else if(str == "push_back"){
            int i;
            cin >> i;
            D.push_back(i);
        }
        else if(str == "pop_front"){
            if(!D.empty()){
                cout << D.front() << endl;
                D.pop_front();
            }
            else cout << -1 << endl;
        }
        else if(str == "pop_back"){
            if(!D.empty()){
                cout << D.back() << endl;
                D.pop_back();
            }
            else cout << -1 << endl;
        }
        else if(str == "size"){
            cout << D.size() << endl;
        }
        else if(str == "empty"){
            if(D.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(str == "front"){
            if(!D.empty())
                cout << D.front() << endl;
            else cout << -1 << endl;
        }
        else{
            if(!D.empty()){
                cout << D.back() << endl;
            }
            else cout << -1 << endl;
        }
    }

    return 0;
}