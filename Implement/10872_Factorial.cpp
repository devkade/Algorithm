#include <iostream>

using namespace std;

int Factorial(int n);

int main()
{
	int N;
	cin >> N;
	cout << Factorial(N) << endl;
	
	return 0;
}


int Factorial(int n)
{
	if(n==0) 
		return 1;
	else if(n==1) 
		return 1;
	else
		return n*Factorial(n-1);
}