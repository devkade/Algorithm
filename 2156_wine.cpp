#include <iostream>
#include <vector>

using namespace std;

// ���� - �ִ�� ���� �� �ִ� �������� ��
// ��Ģ 1. ������ ���ø� ���� ���ð� ���� ��ġ��
// ��Ģ 2. �������� ������ 3���� ���� ��� ���� �� ����. ���� 2������ ����
// �߰��� 1���� �ȸ��� ��, 2���� �ȸ��� ��

int d[10001];
int a[10001];

int maxNum(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else
	{
		if (b > c)
			return b;
		else
			return c;
	}
}

int wine_2156(int number)
{
	if (number == 1) return d[1] = a[1];
	if (number == 2) return d[2] = a[1] + a[2];
	for (int i = 3; i <= number; i++)
	{
		d[i] = maxNum(d[i - 2] + a[i], d[i - 1], d[i - 3] + a[i - 1] + a[i]);
	}
	return d[number];
}

int main()
{
	int n, value;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> value;
		a[i] = value;
	}
	d[1] = a[1];
	d[2] = a[1] + a[2];
	cout << wine(n);

	return 0;
}