#include <iostream>
#include <vector>

using namespace std;

// 목적 - 최대로 마실 수 있는 포도주의 양
// 규칙 1. 포도주 마시면 전부 마시고 원래 위치로
// 규칙 2. 연속으로 놓여진 3개의 잔을 모두 마실 수 없음. 연속 2개까지 가능
// 중간에 1개를 안먹을 때, 2개를 안먹을 때

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