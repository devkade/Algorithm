#include <bits/stdc++.h>
using namespace std;


int arr[105]; // => int arr[201];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, v, res;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i]; // arr[i+100] 음수도 접근할 수 있도록!
	}
	
	cin >> v;
	
	res = 0;
// range-based for문 사용에 익숙해지는 것도 좋음
	for(int i=0; i<N; i++){
		if(arr[i]==v) // arr[i+100]
			res++;
	}
	cout << res << '\n';
	
	return 0;
}