#include <iostream>
#include <vector>

using namespace std;

int main_2667()
{
	int n, val;
	vector<vector<int>> vec;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> val;
			vec[i][j] = val;
		}
	}


	return 0;
}