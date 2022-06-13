#include <iostream>

using namespace std;

// 블랙잭
// 세 가지를 선택 -> M에 가장 가까운 합을 출력
// 모든 경우의 수 -> 100X99X98;
int cardNum[101];


int main()
{
	int n, m, num, max=0, sum=0;
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> num;
		cardNum[i]=num;
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			for(int k=j+1; k<n; k++)
			{
				sum = cardNum[i]+cardNum[j]+cardNum[k];
				if(m>=sum&&max<sum)
					max = sum;
			}
		}
	}
	printf("%d\n", max);
				
	
	return 0;
}