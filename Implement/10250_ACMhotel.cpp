#include <iostream>

using namespace std;

int main()
{
	int t, h, w, n, out, x, k;
	cin >> t;
	for(int i=0; i < t; i++)
	{
		cin >> h >> w >> n;
		x = n/h;
		k = n-h*x;
		if(k == 0)
		{
			cout << 100*h+x << endl;
		}
		else
		{
			cout << 100*k+x+1 << endl;
		}
		
	}
	
	
	return 0;
}