#include <iostream>

using namespace std;

int main()
{
	double a, b, v, n, de; int day;
	cin >> a >> b >> v;
	
	day = (v-b)/(a-b);

	if(day != (v-b)/(a-b))
		day++;
		
	
	cout << day << endl;
	
	return 0;
}