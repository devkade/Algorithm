#include <iostream>

using namespace std;

int main()
{
	int num, shortD=1, range=1;
	cin >> num;
	while(true)
	{
		if(num <= range)
		{
			cout << shortD << endl;
			break;
		}
		else
		{
			range += shortD*6;
			shortD++;
		}
	}
	
	return 0;
}