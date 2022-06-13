#include <bits/stdc++.h>
using namespace std;


int arr[2][7];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, max, gender, year, res=0;
	cin >> N >> max;
	
	for(int i=0; i<N; ++i){
		cin >> gender >> year;
		arr[gender][year]++;
	}
	
	for(int i=0; i<2; ++i){
		for(int j=1; j<=6; ++j){
			if(arr[i][j]==0) continue;
			
			if(arr[i][j]%max!=0)
				res += arr[i][j]/max +1;
			else
				res += arr[i][j]/max;
		}
	}
/*
// 필요한 방의 개수 계산
  for (int i=0; i<2; ++i) {
    for (int j=1; j<7; ++j) {
      // 배정에 필요한 만큼 방의 개수 추가
      ans += s[i][j] / K;
      // 학생이 남을 경우, 하나의 방이 더 필요하므로 방의 개수 추가
      if (s[i][j] % K) ++ans;
    }
  }
// 공통적인 부분은 먼저 처리하고 예외 처리하는 방식도 있음.
*/
	cout << res << '\n';
	
	
	return 0;
}