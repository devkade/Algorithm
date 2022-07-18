// 송신탑의 왼쪽으로 신호를 줌. 왼쪽에 높은 탑이 있어야 함.
#include <bits/stdc++.h>

using namespace std;


// 층을 저장하는 방법 생각해보기
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, res = 0;
    stack<pair<int, int>> s;
    cin >> n;
    s.push({100000001, 0});
    for(int i=1; i<=n; i++){
        int p;
        cin >> p;
        if(s.empty() || p > s.top().first){
            while(p > s.top().first){
                s.pop();
            }
            res = s.top().second;
            cout << res << ' ';
        }
        else{
            res = s.top().second;
            cout << res << ' ';
        }
        s.push({p, i});
    }

    return 0;
}