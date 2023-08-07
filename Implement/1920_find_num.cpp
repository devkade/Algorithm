#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL N, M;
int res, check = 0, idx = 0;
vector<int> vec;


int search(vector<int>& v, int num, int s, int e){
    if (s > e) return 0;

    int mid = (s + e) / 2;

    if (v[mid] == num) return 1;
    else if (v[mid] > num) return search(v, num, s, mid-1);
    else return search(v, num, mid+1, e);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int ins = 0;
    int val;
    for(int i=0; i<N; i++){
        cin >> val;
        vec.push_back(val);
    }
    sort(vec.begin(), vec.end());

    cin >> M;

    while (M--) {
        res = 0;
        cin >> val;
        res = search(vec, val, 0, vec.size()-1);
        if (res) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    

    return 0;
}