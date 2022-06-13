#include <iostream>

using namespace std;

int main()
{
	int x, m=1, midValue, numerator, denominator;
	cin >> x;
	while((m*m+m)/2<x)
	{
		m++;
	}
	m--;
	midValue = x-((m*m+m)/2);
	if((m+1)%2==0)	// 중간값이 짝수일 때
	{
		numerator = 1;
		denominator = m+1;
		for(int i=1; i<midValue; i++)
		{
			numerator++;
			denominator--;
		}
	}
	else
	{
		numerator = m+1;
		denominator = 1;
		for(int i=1; i<midValue; i++)
		{
			numerator--;
			denominator++;
		}
	}
	
	cout << numerator << "/" << denominator << endl;
		
	return 0;
}