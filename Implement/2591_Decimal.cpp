#include <iostream>

using namespace std;

bool is_primeNum(int x);

int main()
{
	int m, n, sum=0, min = 10001, i;
	cin >> m >> n;
	
	if(m==1)
	{
		if(n>=2)
		{
			sum+=2;
			min=2;
			i = m;
		}
	}
	if(m==2)
	{
		sum+=2;
		min=2;
	}
	if(m%2==0)
	{
		i = m+1;
	}
	else
	{
		i = m;
	}
	
	for(i; i<=n; i+=2)
	{
		if(i == 1) continue;
		if(is_primeNum(i))
		{
			sum+=i;
			if(min > i)
				min = i;
		}
	}
	if(sum == 0)
		cout << -1 << endl;
	else
	{
		cout << sum << endl << min << endl;
	}
	
	return 0;
}

bool is_primeNum(int x)
{
	int i = 2;
	while(i*i<=x)
	{
		if(x%i==0)
			return false;
		i++;
	}
	return true;
}