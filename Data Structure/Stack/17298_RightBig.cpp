#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, rightBig = -1, temp;
    stack<int> s, res;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        s.push(val);
    }
    /*
    오른쪽부터 시작. 오큰수 초기값 -1
    현재값보다 왼쪽값이 큰지 작은지 비교
    작으면 현재값 오큰수, 크면 오큰수보다 큰지 작은지 비교
    */
    res.push(rightBig);
    for(int i=1; i<n; i++){
        temp = s.top();
        s.pop();
        if(s.top() <= temp){
            rightBig = temp;
        }
        else{
            if(s.top() > rightBig){
                rightBig = -1;
            }
        }
        res.push(rightBig);
    }
    while(n--){
        cout << res.top() << ' ';
        res.pop();
    }
    return 0;
}