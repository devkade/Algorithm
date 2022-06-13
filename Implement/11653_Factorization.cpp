#include <iostream>

using namespace std;

bool is_primeNum(int n);

int main()
{
	int N;
	cin >> N;
	for(int i=2; i*i<=N; i++)
	{
		if(is_primeNum(i))
		{
			while(N%i==0)
			{
				cout << i << endl;
				N = N/i;
			}
		}
	}
	if((N!=0)&&(N!=1))
		cout << N << endl;
	
	return 0;
}


bool is_primeNum(int n)
{
	int i = 2;
	while(i*i<=n)
	{
		if(n%i==0)
			return false;
		i++;
	}
	return true;
}