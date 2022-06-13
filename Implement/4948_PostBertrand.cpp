#include <iostream>


using namespace std;

bool is_prime(int n);

int main() 
{
  	int inp, num;
	
	while(true)
	{
		num = 0;
		cin >> inp;
		if(inp==0) break;
		for(int i=inp+1; i<=2*inp; i++)
		{
			if(is_prime(i))
			{
				num++;
			}
		}
		cout << num << endl;
	}
	
	return 0;
}


bool is_prime(int n)
{
	int i = 2;
	for(i; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}