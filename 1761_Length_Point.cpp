#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� ���� -> �׷���
// dfs�� �� ���鼭 ��+

void dfs(int x)
{
}



int main_1761()
{
	vector<pair<pair<int, int>, int>> vec;
	int n, m, a, b, value;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> value;
		vec[i].first.first = a;
		vec[i].first.second = b;
		vec[i].second = value;
		
	}

	return 0;
}