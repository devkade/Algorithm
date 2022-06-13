#include <bits/stdc++.h>
using namespace std;


int arr[1000005];
bool used[2000001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, cnt;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	cin >> x;
	
	cnt = 0;
	
	for(int i=1; i<=n; i++){
		if(x-arr[i]>0 && used[x-arr[i]])
			cnt++;
		used[arr[i]]=true;
	}
	cout << cnt << '\n';
	
	return 0;
}