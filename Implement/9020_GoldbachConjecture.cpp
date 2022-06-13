#include <iostream>

// 골드바흐의 추측
// 중앙에서부터 찾아가는 방식. ex) 10 -> 5+5


using namespace std;

bool is_prime(int n);

int main() 
{
  	int T, n, gol, den;
	cin >> T;
	for(int i=0; i<T; i++)
	{
		cin >> n;
		gol = n/2;
		while(true)
		{
			if(is_prime(gol))
			{
				den = n-gol;
				if(is_prime(den))
				{
					cout << gol << " " << den << endl;
					break;
				}
				else
				{
					gol--;
				}
			}
			else
			{
				gol--;
			}
		}
			
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