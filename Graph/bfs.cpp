#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void BFS(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main() {
	// 1과 2를 연결한다.
	a[1].push_back(2);
	a[2].push_back(1);


	// 1과 3을 연결한다.
	a[1].push_back(3);
	a[3].push_back(1);


	// 2와 3을 연결한다.
	a[2].push_back(3);
	a[3].push_back(2);


	// 2과 4를 연결한다.
	a[2].push_back(4);
	a[4].push_back(2);


	// 2와 5를 연결한다.
	a[2].push_back(5);
	a[5].push_back(2);


	// 3과 6을 연결한다.
	a[3].push_back(6);
	a[6].push_back(3);


	// 3과 7을 연결한다.
	a[3].push_back(7);
	a[7].push_back(3);


	// 4와 5를 연결한다.
	a[4].push_back(5);
	a[5].push_back(4);


	// 6과 7을 연결한다.
	a[6].push_back(7);
	a[7].push_back(6);


	// BFS를 수행한다.
	BFS(1);


	return 0;
}