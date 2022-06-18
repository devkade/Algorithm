// 연결리스트 stl list 사용
#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> L;
    string str;
    int M;
    cin >> str;
    for(auto elem : str) {
        L.push_back(elem);
    }
    auto cursor = L.end();
    cin >> M;
    char p;
    while(M--) {
        cin >> p;
        switch(p) {
            case 'L':
                if(cursor != L.begin()) cursor--;
                break;
            case 'D':
                if(cursor != L.end()) cursor++;
                break;
            case 'B':
                if(cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
                break;
            case 'P':
                char inp;
                cin >> inp;
                L.insert(cursor, inp);
                break;
        }
        
    }

    for(auto elem : L)
        cout << elem;

    return 0;
}