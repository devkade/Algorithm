// �ֳʱ׷� ���� �����
// �ֳʱ׷� ����� ���� �� ���� ���ڸ� �����ؾ� �ϴ°�?
#include <bits/stdc++.h>

using namespace std;

int first[30];
int second[30];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    int cnt = 0;
    cin >> a >> b;
    for(auto elem : a){
        first[(int)elem-97]++;
    }
    for(auto elem : b){
        second[(int)elem-97]++;
    }

    for(int i = 0; i<30; i++){
        if(first[i]!=0 || second[i]!=0){
            if(first[i]>second[i]){
                cnt += first[i] - second[i];
            }
            else if(first[i]<second[i]){
                cnt += second[i] - first[i];
            }
        }
    }

    cout << cnt << endl;
    return 0;
}