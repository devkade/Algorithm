#include <iostream>
#include <string>

using namespace std;

bool isGroup(string s);

int main()
{
	int num, result=0;
	string str;
	cin >> num;
	for(int i=0; i<num; i++)
	{
		cin >> str;
		if(isGroup(str))
			result++;
	}
	cout << result << endl;	
	
	return 0;
}

bool isGroup(string s)
{
	char bAlpa;
	for(int i=0; i<s.size()-1; i++)
	{
		if(s[i]!=s[i+1])	// ���ĺ��� �ٲ�� ���� aabb �̸� 1-2�ε��� ����
		{
			bAlpa = s[i];
			for(int j = i+1; j<s.size(); j++)		// �� ���ĺ� ���� �� �Ǵ�
			{
				if(bAlpa == s[j])
					return false;
			}
		}
		
	}
	return true;
}