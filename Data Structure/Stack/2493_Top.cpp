// �۽�ž�� �������� ��ȣ�� ��. ���ʿ� ���� ž�� �־�� ��.
#include <bits/stdc++.h>

using namespace std;


// ���� �����ϴ� ��� �����غ���
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