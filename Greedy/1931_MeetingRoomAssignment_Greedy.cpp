#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������ pair�� �ް� ���� �ð��� ���� �������� ����
// for�� ������ �� �� ���� �������� ī��Ʈ
/* �ð��ʰ�
int main()
{
	vector<pair<int, int>> vec;
	pair<int, int> p;

	int num, start, end, count, maxCount = 0, j = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> start >> end;
		p.first = start;
		p.second = end;
		vec.push_back(p);
	}
	sort(vec.begin(), vec.end());



	// ���� count�� �ϸ� ��.
	for (int i = 0; i < vec.size()-1; i++)
	{
		start = vec[i].first;
		end = vec[i].second;
		j = i + 1;
		count = 1;
		while (true)
		{
			if (vec[j].first >= end)
			{
				end = vec[j].second;
				count++;
				
			}
			j++;
			if (j == vec.size())
				break;

		}
		if(maxCount < count)
			maxCount = count;
	}
	cout << maxCount << endl;

	return 0;
}
*/


struct Time
{
	int begin;
	int end;
};

bool compare(Time t, Time s)
{
	if (t.end == s.end)
	{
		return t.begin < s.begin;
	}
	else
	{
		return t.end < s.end;
	}
}

int main()
{
	int n, cnt = 0, end = 0;
	cin >> n;
	vector<Time> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].begin >> vec[i].end;
		
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < n; i++)
	{
		if (end <= vec[i].begin)
		{
			end = vec[i].end;
			cnt++;
		}
			
	}

	cout << cnt << endl;

	return 0;
}


