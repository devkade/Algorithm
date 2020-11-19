#include <iostream>
#include <vector>

using namespace std;


// 등수가 높은 사람대로 정렬. 정렬할 때 부모찾아가는 식으로
// 정렬한 vector에 X가 없다면 최대 1등, 최소 꼴등
// 정렬한 vector에 X가 있다면 최대 1+X앞에 정렬된 사람 수, 꼴등-X뒤에 정렬된 사람 수
int main_17616()
{
	vector<int> highVec, lowVec;
	int n, m, x, a, b;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		highVec.push_back(a);
		lowVec.push_back(b);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lowVec[j] == highVec[i])
			{
				
			}
		}
	}

	return 0;
}