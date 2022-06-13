#include <iostream>
#include <cmath>

using namespace std;

struct Round
{
	int x;
	int y;
	int r;
};

int main() 
{
  	int T, x1, y1, r1, x2, y2, r2, D, sumR, subR;
	Round a, b;
	cin >> T;
	for(int i=0; i<T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		a.x = x1;	a.y = y1;	a.r = r1;
		b.x = x2;	b.y = y2;	b.r = r2;
		if(a.x==b.x&&a.y==b.y&&a.r==b.r)
		{
			cout << -1 << endl;
			continue;
		}
		D = pow(abs(a.x-b.x),2)+pow(abs(a.y-b.y),2);
		sumR = pow(a.r + b.r,2);
		subR = pow(abs(a.r-b.r),2);
		if(D>sumR||D<subR)
		{
			cout << 0 << endl;
			continue;
		}
		else if(D==sumR||D==subR)
		{
			cout << 1 << endl;
			continue;
		}
		else
		{
			cout << 2 << endl;
			continue;
		}
		
	}
	
	return 0;
}