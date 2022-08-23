#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int is_used[10];

void func(int k){
	if(k==m){
		for(int i=0; i<m; i++){
			cout << arr[i] << ' ';
		}
		cout << endl;
		return;
	}
	for(int i=1; i<=n; i++){
		if(!is_used[i]){
			if(k!=0 && i < arr[k-1]) continue;
			is_used[i] = 1;
			arr[k] = i;
			func(k+1);
			is_used[i] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}
