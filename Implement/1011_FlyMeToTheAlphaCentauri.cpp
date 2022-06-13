#include <iostream>

using namespace std;


int main()
{
	int T, num, D, k, x, y;
	cin >> T;
	for(int i=0; i<T; i++)
	{
		cin >> x >> y;
		num = 0;
		k=1;
		D = y - x;
		if(D==1) num = D;
		else
		{
			num += 2;
			while(true)
			{
				if(D-2*k>2*(k+1))
				{
					D -= 2*k;
					num+=2;
					k++;
				}
				else if((k+1<D-2*k)&&(D-2*k<=2*(k+1)))
				{
					num+=2;
					break;
				}
				else
				{
					num+=1;
					break;
				}
			}
		}
		cout << num << endl;
		
	}
	
	return 0;
}