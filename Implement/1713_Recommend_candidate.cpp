#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int recommend[105];     // 추천 횟수
int check[105];         // 사진틀에 들어왔는지 여부 체크
vector<int> frame;

int main(){
    ios::sync_with_stdio(true);
    cin.tie(0); cout.tie(0);

    int N, size, num, old = 0;
    check[104] = 99999;

    cin >> N;
    
    size = N;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        old++;

        // Frame이 채워져 있는 상태에서 새로운 후보가 들어온 경우
        if (frame.size() == size && !check[num-1]){
            int idx = -1;
            pair<int, int> min = {104, 99999};
            for (int k=0; k<frame.size(); k++){
                int n = frame[k];
                // 현재까지 추천수가 가장 적은 학생 추출
                if (min.Y > recommend[n-1]) {
                    idx = k;
                    min.X = n;
                    min.Y = recommend[n-1];
                }
                // 추천수가 동일할 때 오래된 학생 추출
                else if (min.Y == recommend[n-1]){
                    if (check[min.X-1] > check[n-1]){
                        idx = k;
                        min.X = n;
                        min.Y = recommend[n-1];
                    } 
                }
            }
            recommend[min.X-1] = 0;
            check[min.X-1] = 0;

            frame[idx] = num;
            recommend[num-1]++;
            check[num-1] = old;
        }
        // 사진틀에 있는 후보가 추천을 받은 경우
        else if (check[num-1]){
            recommend[num-1]++;
        }
        else{
            recommend[num-1]++;
            check[num-1] = old;
            frame.push_back(num);
        }
    }

    sort(frame.begin(), frame.end());

    for (int i : frame){
        cout << i << " ";
    }

    return 0;
}