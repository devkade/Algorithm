#include <iostream>
#include <cmath>

using namespace std;

const double PI = std::acos(-1);
int main() 
{
  	int r;
	double taxi, euclid;
	cin >> r;
	taxi = 2*r*r;
	euclid = PI*r*r;
	cout << fixed;
	cout.precision(6);
	cout << euclid << endl << taxi << endl;
	
	
	return 0;
}