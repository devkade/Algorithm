#include <iostream>

using namespace std;

bool is_primeNum(int x);

int main()
{
	int N, x, num=0;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> x;
		if(x == 1) continue;
		if(is_primeNum(x))
			num++;
	}
	cout << num << endl;
	
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