#include <iostream>
#include <vector>

using namespace std;
// * ��ġ�� ũ���� ������(weight)�� Ű(height)�� �Բ� Ŀ�� �Ѵ�. �ƴϸ� �� �Ұ�
// * ������ ����� ��� �Ǵ��� ���ΰ�. 
// �����ؼ� ��� �ű��
// ���� ���ϰ� �� �� �ű��

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