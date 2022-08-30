// 연결리스트
#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    string str;
    while(T--){
        list<char> L = {};
        cin >> str;
        auto cursor = L.begin();
        for(auto c : str){
            if(c == '<')
                {if(cursor != L.begin()) cursor--;}
            else if(c == '>')
                {if(cursor != L.end()) cursor++;}
            else if(c == '-'){
                if(cursor != L.begin()){
                    cursor--;
                    cursor = L.erase(cursor);
                }
            } 
            else{
                L.insert(cursor, c);
            }
            
        }
        for(auto elem : L){
            cout << elem;
        }
        cout << endl;
    }


    return 0;
}