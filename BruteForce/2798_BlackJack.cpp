#include <iostream>

using namespace std;

// ����
// �� ������ ���� -> M�� ���� ����� ���� ���
// ��� ����� �� -> 100X99X98;
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