#include <iostream>
#include <vector>

using namespace std;


// ����� ���� ������ ����. ������ �� �θ�ã�ư��� ������
// ������ vector�� X�� ���ٸ� �ִ� 1��, �ּ� �õ�
// ������ vector�� X�� �ִٸ� �ִ� 1+X�տ� ���ĵ� ��� ��, �õ�-X�ڿ� ���ĵ� ��� ��
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