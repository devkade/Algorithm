#include <iostream>
#include <vector>
#include <algorithm>

#define PLUS 1
#define MINUS 2
#define MULTIPLY 3
#define DIVIDE 4
using namespace std;
/*
int max_number(vector<int>* num, vector<int>* oper)
{

}
*/
int main_14888()
{
	int num, n, oper, max, min;
	vector<int> vNum, vOperator;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		vNum.push_back(n);
	}
	for (int j = 0; j < 4; j++)
	{
		cin >> oper;
		vOperator.push_back(oper);
	}
	

	return 0;
}