#include <iostream>
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4

using namespace std;



int main()
{
	int input, units, num=0, temp;
	cin >> input;
	
	units = input%10;
	if(units == 8 || units == 3)
	{	
		temp = input-3*ONE;
		num += ONE;
	}
	else if(units == 6 || units == 1)
	{
		temp = input-3*TWO;
		num += TWO;		
	}
	else if(units == 9 || units == 4)
	{	
		temp = input-3*THREE;
		num += THREE;
	}
	else if(units == 7 || units == 2)
	{
		temp = input-3*FOUR;
		num += FOUR;
	}
	else
	{
		temp = input;
	}
	
	if(temp < 0)
		num = -1;
	else
	{
		if(temp%5==0)
		{
			num += temp/5;
		}
		else
		{
			num = -1;
		}
	}
	
	cout << num << endl;
	
	return 0;
}