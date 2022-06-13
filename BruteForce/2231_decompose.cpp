#include <iostream>

using namespace std;

void sumEachDigit(int &sum, int num);

int main()
{
	int n, sum, temp;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		sum=0;
		sum+=i;
		sumEachDigit(sum, i);
		if(sum == n)
		{
			cout << i << endl;
			break;
		}
	}
	if(sum > n)
		cout << 0 << endl;
	return 0;
}

void sumEachDigit(int &sum, int num)
{
	while(num!=0)
	{
		sum += num%10;
		num /= 10;
	}
}