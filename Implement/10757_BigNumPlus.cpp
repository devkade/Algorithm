#include <iostream>
#include <string>
#include <vector>


using namespace std;

//48
void bigNum(string A, string B);

int main() 
{
  	string A, B;
	cin >> A >> B;
	
	bigNum(A, B);
	
	
	return 0;
}

void bigNum(string A, string B)
{
	int lenA = A.length();
	int lenB = B.length();
	int len, sum;
	int iA[10001], iB[10001];
	vector<int> res;
	bool roundUp = false;
	
	// 자릿수가 많은 것을 A로
	if(lenA < lenB)
	{
		swap(A, B);
		lenA = A.length();
		lenB = B.length();
	}
	len = lenA;		// 최대 길이
	
	for(int i = 0; i<lenA; i++)
		iA[i+1] = A.at(i)-'0';
	
	for(int i = 0; i<lenB; i++)
		iB[i+1+(lenA-lenB)] = B.at(i)-'0';
	
	for(int i = len; i>0; i--)
	{
		sum = iA[i]+iB[i];
		if(roundUp)
			sum+=1;
		
		roundUp=false;
		
		if(sum > 9)
		{
			roundUp=true;
			res.push_back(sum % 10);
		}
		else
		{
			res.push_back(sum);
		}
	}
	
	if(roundUp)
		cout << 1;
	for(int i=res.size()-1; i>=0; i--)
		cout << res[i];
	
}