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
// �ʿ��� ���� ���� ���
  for (int i=0; i<2; ++i) {
    for (int j=1; j<7; ++j) {
      // ������ �ʿ��� ��ŭ ���� ���� �߰�
      ans += s[i][j] / K;
      // �л��� ���� ���, �ϳ��� ���� �� �ʿ��ϹǷ� ���� ���� �߰�
      if (s[i][j] % K) ++ans;
    }
  }
// �������� �κ��� ���� ó���ϰ� ���� ó���ϴ� ��ĵ� ����.
*/
	cout << res << '\n';
	
	
	return 0;
}