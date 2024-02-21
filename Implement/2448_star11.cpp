#include <iostream>

#define endl '\n'
using namespace std;

int N;
char tri[3][6] = {
    "  *  ",
    " * * ",
    "*****"
};
char board[3100][6200];


void Input(){
    cin >> N;
}

void Solution(int n, int y, int x){
    if(n == 1){
        for(int i=0; i<3; i++){
            for(int j=0; j<5; j++){
                board[y+i][x+j] = tri[i][j];            
            }
        }
        return;
    }
    Solution(n/2, y, x+3*n/2);
    Solution(n/2, y+3*n/2, x);
    Solution(n/2, y+3*n/2, x+3*n);
}

void Solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<2*N-1; j++){
            if(board[i][j] != '*') cout << " ";
            else cout << "*";
        }
        cout << endl;
    }
}

int main(){
   ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution(N/3, 0, 0);
    Solve();

    return 0;
}
