#include <iostream>

using namespace std;

int a, b;
int gcd, lcm;

void Input(){
    cin >> a >> b;
}

void GCD(){
    int val1, val2;
    if(a < b){
        val1 = b;
        val2 = a;
    }
    else{
        val1 = a;
        val2 = b;
    }

    while(val2 != 0){
        int temp = val1 % val2;
        val1 = val2;
        val2 = temp;
    }

    gcd = val1;
}

void LCM(){
    lcm = (a * b) / gcd;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    GCD();
    LCM();
    cout << gcd << endl;
    cout << lcm << endl;
    return 0;
}