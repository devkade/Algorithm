#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, x, y; 
	long long num, res = 0;

	cin >> T;

	for(int i = 0; i < T; i++){
		num = 1;
		res = 0;
		cin >> x >> y;
		long long diff = y - x;
		if(diff == 2){
			cout << 2 << '\n';
			continue;
		}
		while(true){
			if(num * 2 < diff){
				diff = diff - num * 2;
				res += 2;
				num++;
			}
			else if(num * 2 == diff){
				if (num+1 < diff) res += 2;
				else res++;
				break;
			}
			else {
				diff = diff - num;
				res++;
			}
			if(diff <= 0) break;
		}
		cout << res << '\n';
	}

	return 0;
}