#include <bits/stdc++.h>
using namespace std;


int arr[105]; // => int arr[201];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, v, res;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i]; // arr[i+100] ������ ������ �� �ֵ���!
	}
	
	cin >> v;
	
	res = 0;
// range-based for�� ��뿡 �ͼ������� �͵� ����
	for(int i=0; i<N; i++){
		if(arr[i]==v) // arr[i+100]
			res++;
	}
	cout << res << '\n';
	
	return 0;
}