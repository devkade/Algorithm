#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void bar(int cnt){
    for(int i=0; i < cnt; i++) cout << "____";
}

void func(int n){
    bar(cnt);
    cout << "\"����Լ��� ������?\"" << endl;
    if(n == cnt){
        bar(cnt);
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
    }
    else{
        bar(cnt);
        cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
        bar(cnt);
        cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
        bar(cnt);
        cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
        cnt++;
        func(n);
    }
    bar(cnt);
    cout << "��� �亯�Ͽ���." << endl;
    cnt--;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
    func(n);
    return 0;
}