#include <bits/stdc++.h>
using namespace std;


int arr[30];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, res=1;
	string origin, changed;
	cin >> N;
	
	for(int i=0; i<N; ++i){
		res = 1;
		cin >> origin >> changed;
		// 알파벳 순서로 카운팅 => 알파벳 개수에 따라 1이 아닌 2, 3, ... 가능
		for(int elem : origin){
			arr[elem-'a']++;
		}
		
		for(int elem : changed){
			if(arr[elem-'a']==0){
				res = 0;
			}
			// origin이 ae인데 changed가 aa인 경우 확인하기 어렵기에 빼가면서 카운팅
			else{
				arr[elem-'a']--;
			}
		}
		// 필요한 알파벳 중 일부만 사용한 경우 처리 + 배열 초기화
		for(int i=0; i<30; i++){
			if(arr[i]!=0){
				res=0;
				arr[i]=0;
			} 
		}
		if(res==1) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	
	
	return 0;
}