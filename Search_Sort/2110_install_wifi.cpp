#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> home;

int search(int start, int end){
    int mid, res=0, cnt;
    while(start <= end){
        mid = (start + end) / 2;

        int installed = home[0];       
        cnt = 1;
        for (int i=0; i<N; i++){
            if (home[i]-installed >= mid){
                cnt++;
                installed = home[i];
            }
        }

        if(cnt >= C){
            res = max(res, mid);
            start = mid+1;
        }
        else end = mid-1;
    }

    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int val;

    cin >> N >> C;
    
    for(int i=0; i<N; i++){
        cin >> val;
        home.push_back(val);
    }
    sort(home.begin(),home.end());

    int min_dist = 1;
    int max_dist = home[N-1]-home[0];
    cout << search(min_dist, max_dist) << '\n';


    return 0;
}