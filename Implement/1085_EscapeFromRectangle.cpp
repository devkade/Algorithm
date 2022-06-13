#include <iostream>

using namespace std;

int minDistance(int x, int y, int w, int h);

int main() 
{
  	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << minDistance(x, y, w, h) << endl;
	
	return 0;
}


int minDistance(int x, int y, int w, int h)
{
	int mW, mH;
	(w/2<x)? mW=w-x:mW=x;
	(h/2<y)? mH=h-y:mH=y;
	return (mW<mH)? mW : mH;
}