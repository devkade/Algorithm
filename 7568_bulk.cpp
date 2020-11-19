#include <iostream>
#include <vector>

using namespace std;
// * 덩치가 크려면 몸무게(weight)와 키(height)가 함께 커야 한다. 아니면 비교 불가
// * 문제는 등수를 어떻게 판단할 것인가. 
// 정렬해서 등수 매기기
// 정렬 안하고 등 수 매기기

int main_7568()
{
	int num, weight, height, grade;
	vector<vector<int>> infos;
	vector<int> element;

	cin >> num;

	for (size_t i = 0; i < num; i++)
	{
		cin >> weight >> height;
		element.push_back(weight);
		element.push_back(height);
		infos.push_back(element);
		element.clear();
	}

	for (size_t i = 0; i < infos.size(); i++)
	{
		grade = 0;
		for (size_t j = 0; j < infos.size(); j++)
		{
			if (i == j)
				continue;
			else
			{
				if (infos[i][0] < infos[j][0] && infos[i][1] < infos[j][1])
				{
					grade++;
				}
			}
		}
		cout << grade + 1 << " ";
	}
	

	return 0;
}