#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int n, int fromPos, int toPos);

int main()
{
	int n;
	cin >> n;
	printf("%d\n", int(pow(2,n))-1);
	hanoi(n, 1, 3);
	return 0;
}


void hanoi(int n, int fromPos, int toPos)
{
	int viaPos;
	viaPos = 6-fromPos-toPos;
	if(n<=1)
		printf("%d %d\n", fromPos, toPos);
	else
	{
		// n-1개 원판을 1번째에서 2번째 기둥으로
		hanoi(n-1, fromPos, viaPos);
		printf("%d %d\n", fromPos, toPos);
		hanoi(n-1, viaPos, toPos);
	}
	
}