#include <bits/stdc++.h>
using namespace std;

vector<string> vec;

bool compare(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string word;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> word;
        if(find(vec.begin(), vec.end(), word) == vec.end()){
            vec.push_back(word);
        }
    }
    sort(vec.begin(), vec.end(), compare);

    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << '\n';
    }

    return 0;
}