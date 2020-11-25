#include <iostream>
#include <vector>

using namespace std;

int main_10773()
{
	int num, value, sum = 0;
	vector<int> vec;

	cin >> num;
	for (size_t i = 0; i < num; i++)
	{
		cin >> value;
		if (value == 0)
			vec.pop_back();
		else
			vec.push_back(value);
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		sum += vec[i];
	}
	cout << sum << endl;
	return 0;
}