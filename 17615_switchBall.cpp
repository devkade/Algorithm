#include <iostream>
#include <string>

using namespace std;

int main_17615()
{
	int n, index = 0, count = 0, blue_cnt = 0, red_cnt = 0, result;
	string balls;
	cin >> n >> balls;
	
	for (auto elem : balls)
	{
		if (elem == 'R') red_cnt++;
		else blue_cnt++;
	}
	result = min(red_cnt, blue_cnt);

	while (true)
	{
		if (balls[index] == 'R')
			count++;
		else
			break;
		index++;
	}
	result = min(result, red_cnt - count);


	index = 0; count = 0;
	while (true)
	{
		if (balls[balls.length()-1-index] == 'R')
			count++;
		else
			break;
		index++;
	}
	result = min(result, red_cnt - count);

	index = 0; count = 0;
	while (true)
	{
		if (balls[index] == 'B')
			count++;
		else
			break;
		index++;
	}
	result = min(result, blue_cnt - count);

	index = 0; count = 0;
	while (true)
	{
		if (balls[balls.length()-1-index] == 'B')
			count++;
		else
			break;
		index++;
	}
	result = min(result, blue_cnt - count);

	cout << result;

	return 0;
}