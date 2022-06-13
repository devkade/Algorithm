#include <iostream>

using namespace std;
#define pow(x) x*x

bool Pythagoras(int x, int y, int z);

int main() 
{
  	int x, y, z;
	while(true)
	{
		cin >> x >> y >> z;
		if(x==0&&y==0&&z==0)
			break;
		if(Pythagoras(x, y, z))
		{
			cout << "right" << endl;
			continue;
		}
		cout << "wrong" << endl;
	}
	
	
	return 0;
}

bool Pythagoras(int x, int y, int z)
{
	int max, a, b;
	if(x>y)
	{
		if(x>z)
		{
			max = x;
			a=y;
			b=z;
		}
		else
		{
			max = z;			
			a=x;
			b=y;
		}
	}
	else
	{
		if(y>z)
		{
			max = y;
			a=x;
			b=z;
		}
		else
		{
			max = z;
			a=x;
			b=y;
		}
	}
	if(pow(max)==pow(a)+pow(b))
		return true;
	else
		return false;
	
}