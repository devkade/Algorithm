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
    �����ʺ��� ����. ��ū�� �ʱⰪ -1
    ���簪���� ���ʰ��� ū�� ������ ��
    ������ ���簪 ��ū��, ũ�� ��ū������ ū�� ������ ��
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