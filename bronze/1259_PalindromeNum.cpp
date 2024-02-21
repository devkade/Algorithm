#include <iostream>
#include <string>
#define endl '\n';
using namespace std;

int main(){
    string palin;
    while(true){
        bool flag = true;
        cin >> palin;
        if(palin == "0") break;

        for(unsigned int i = 0; i < palin.length()/2; i++){
            if(palin[i] != palin[palin.length()-i-1]){
                cout << "no" << endl;
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "yes" << endl;
    }
    return 0;
}