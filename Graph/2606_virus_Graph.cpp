#include <iostream>
#include <vector>

using namespace std;

// Union-Find 알고리즘

int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int main_2606()
{
	int parent[101];
	int comNum, edge, a, b, count = 0;
	cin >> comNum;
	cin >> edge;
	for (int i = 1; i <= comNum; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < edge; i++)
	{
		cin >> a >> b;
		unionParent(parent, a, b);
	}
	
	for (int i = 2; i <= comNum; i++)
	{
		if (findParent(parent, 1, i))
			count++;
	}

	cout << count;

	return 0;
}