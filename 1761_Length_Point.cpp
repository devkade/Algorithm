#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 연결 연결 -> 그래프
// dfs로 쭉 들어가면서 값+

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