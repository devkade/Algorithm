#include <iostream>

using namespace std;

struct Coordinate{
	int x;
	int y;
};

int main() 
{
  	Coordinate a, b, c, res;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	
	if((a.x==b.x))
		res.x = c.x;
	else if((a.x==c.x))
		res.x = b.x;
	else if(b.x==c.x)
		res.x = a.x;
	
	if((a.y==b.y))
		res.y = c.y;
	else if((a.y==c.y))
		res.y = b.y;
	else if(b.y==c.y)
		res.y = a.y;
	
	cout << res.x << " " << res.y << endl;
	
	
	return 0;
}