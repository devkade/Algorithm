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
		// ���ĺ� ������ ī���� => ���ĺ� ������ ���� 1�� �ƴ� 2, 3, ... ����
		for(int elem : origin){
			arr[elem-'a']++;
		}
		
		for(int elem : changed){
			if(arr[elem-'a']==0){
				res = 0;
			}
			// origin�� ae�ε� changed�� aa�� ��� Ȯ���ϱ� ��Ʊ⿡ �����鼭 ī����
			else{
				arr[elem-'a']--;
			}
		}
		// �ʿ��� ���ĺ� �� �Ϻθ� ����� ��� ó�� + �迭 �ʱ�ȭ
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