#include <iostream>
#include <queue>
#include <map>
#define endl '\n'
using namespace std;

priority_queue<int> max_q;
priority_queue<int, vector<int>, greater<int>> min_q;
map<int, int> ckpt;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, k, val;
    char ch;

    cin >> T;

    while(T--){
        while(!max_q.empty()) max_q.pop();
        while(!min_q.empty()) min_q.pop();
        ckpt.clear();
        cin >> k;
        while(k--){
            cin >> ch >> val;

            if (ch=='I'){
                max_q.push(val);
                min_q.push(val);
                ckpt[val]++;
            }
            else{
                if (val==1){
                    if (!max_q.empty()){
                        ckpt[max_q.top()]--;
                        max_q.pop();
                    }
                }
                else{
                    if (!min_q.empty()){
                        ckpt[min_q.top()]--;
                        min_q.pop();
                    }
                }
                while(!min_q.empty() && ckpt[min_q.top()]==0)
                    min_q.pop();
                while(!max_q.empty() && ckpt[max_q.top()]==0)
                    max_q.pop();
            }
        }
        if (max_q.empty() || min_q.empty()) {
            cout << "EMPTY" << endl;
        }
        else{
            cout << max_q.top() << ' ' << min_q.top() << endl;
        }
    }

    return 0;
}