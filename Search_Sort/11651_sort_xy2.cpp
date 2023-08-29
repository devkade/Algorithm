#include <bits/stdc++.h>
using namespace std;
vector <pair<int, int>> vec;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end(), compare);

    for(int i=0; i<n; i++){
        cout << vec[i].first << " " << vec[i].second << '\n';
    }

    return 0;
}