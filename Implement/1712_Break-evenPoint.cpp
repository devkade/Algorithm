#include <iostream>

using namespace std;

int main()
{
	int fixV, changeV, sellV, val;
	cin >> fixV >> changeV >> sellV;
	
	if((sellV-changeV) <= 0)
		val = -1;
	else
	{
		val = (fixV/(sellV-changeV))+1;
	}
	cout << val << endl;
	
	return 0;
}