#include <bits/stdc++.h>
using namespace std;

int num[500005];
int freq_ck[8005] = {0,};

int main(){
    int N, val, mid, range, idx, offset = 4000;
    int avg, sum = 0;
    int low = 9999, high = -9999, max_idx= 4003, equal = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> val;
        // 산술 평균
        sum += val;

        // 중앙값
        num[i] = val;
        freq_ck[val+offset]++;
    }

    sort(num, num+N);

    for(int i = 0; i < N; i++){
        // 최빈값
        val = num[i];
        idx = val + offset;

        if (freq_ck[idx] > freq_ck[max_idx+offset]) {
            max_idx = val;
            equal = 0;
        }
        else if (freq_ck[idx] == freq_ck[max_idx+offset]){
            if(equal == 0 && val != max_idx){
                equal = 1;
                max_idx = val;
            }
        }
        // 범위
        if (low > val) low = val;
        if (high < val) high = val;
    }
    

    avg = round((float)sum / N);
    
    cout << avg << '\n';

    cout << num[(N-1)/2] << '\n';
    
    cout << max_idx << '\n';

    range = high-low;
    cout << range << '\n';

    return 0;
}