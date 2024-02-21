#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int prev_status = 0, cur_status = 0; // 0 = mix, -1 = descending, 1 = ascending

    int a[8];
    for(int i=0; i<8; i++){
        cin >> a[i];
        if(i != 0 && a[i] > a[i-1]) cur_status = 1;
        else if(i != 0 && a[i] < a[i-1]) cur_status = -1;

        if(prev_status == cur_status || i == 0 || i == 1){
            prev_status = cur_status;
        }
        else{
            cout << "mixed" << endl;
            exit(0);
        }
    }
    if(cur_status == 1) cout << "ascending" << endl;
    else cout << "descending" << endl;


    return 0;
}