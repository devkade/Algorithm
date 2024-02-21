#include <iostream>
#include <map>
#define endl '\n'
typedef long long ll;
using namespace std;

int N;
int x, p;
ll res = 0;
map<ll, ll> m;

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> p;
        m.insert({x, p});
    }
}

void Solution(){
    if(N == 2){
        auto start = m.begin();
        res += start->second;
        start++;
        if(res > start->second) res = start->second;
        return;
    }
    auto iter = m.begin();
    auto end = m.end();
    iter++;
    end--;
    res += iter->second;
    for(; iter != end; iter++){
        auto temp = end;
        if(iter == --temp){
            break;
        }
        temp = iter;
        temp++;
        res += temp->first - iter->first + temp->second;
    }
    int left, right;
    auto temp = m.begin();
    temp++;
    left = temp->first - m.begin()->first + m.begin()->second;
    temp = m.end();
    end = m.end();
    temp--;
    temp--;
    end--;
    right = end->first - temp->first + end->second;
    if(left > right){
        res += right;
    }
    else{
        res += left;
    }
}

int main(){
   ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();
    cout << res << endl;

    return 0;
}