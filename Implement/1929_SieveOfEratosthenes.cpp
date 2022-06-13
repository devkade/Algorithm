#include <iostream>

using namespace std;

int main() 
{
  	bool arr[1000001];
  	int M, N;

  	cin >> M >> N;

  	arr[0] = arr[1] = true;

  	for (int i=2; i*i<=N; i++)
  	{
    	if (!arr[i])
    	{
	      	for (int j = i * 2; j <= N; j += i)
    	    	arr[j] = true;
    	}
  	}

  	for (int i = M; i <= N; i++)
  	{
    	if (!arr[i])
     	 	cout << i << '\n';
  	}
	return 0;
}