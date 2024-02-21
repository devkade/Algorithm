#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string str;
  cin >> str;

  for(int i = 0; i < str.length(); i++){
    int sum = 0;
    int val = int(str[i]);
    while(val != 0){
      sum += val % 10;
      val /= 10; 
    }
    while(sum--) cout << str[i];
    cout << endl;
  }
  return 0;
}