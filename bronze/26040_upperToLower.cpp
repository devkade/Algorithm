#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
  string A, B;
  getline(cin, A);
  getline(cin, B);

  vector<int> vec;

  for(int i = 0; i < B.length(); i++){
    if(B[i] != ' '){
      vec.push_back(B[i]);
    }
  }
  
  for(int i = 0; i < A.length(); i++){
    for(char nxt : vec){
      if(A[i] == nxt) A[i] += 32;
    }
  }

  cout << A << endl;

  return 0;
}