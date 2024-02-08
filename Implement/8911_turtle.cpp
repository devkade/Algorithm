#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second

pair <int, int> point;
char dirs[4] = {'n', 'w', 's', 'e'};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int x_min = 0, y_min = 0, x_max = 0, y_max = 0;
        int idx = 0;
        char dir = dirs[idx];
        point = {0, 0};

        string str;
        cin >> str;
        
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'F' || str[i] == 'B'){
                if(dir == 'n'){
                    if(str[i] == 'F') {
                        point.Y++;
                        if(point.Y > y_max) y_max = point.Y;
                    }
                    else{
                        point.Y--;
                        if(point.Y < y_min) y_min = point.Y;
                    }
                }
                else if(dir == 'e'){
                    if(str[i] == 'F') {
                        point.X++;
                        if(point.X > x_max) x_max = point.X;
                    }
                    else{
                        point.X--;
                        if(point.X < x_min) x_min = point.X;
                    }
                }
                else if(dir == 's'){
                    if(str[i] == 'B') {
                        point.Y++;
                        if(point.Y > y_max) y_max = point.Y;
                    }
                    else{
                        point.Y--;
                        if(point.Y < y_min) y_min = point.Y;
                    }
                }
                else{
                    if(str[i] == 'B') {
                        point.X++;
                        if(point.X > x_max) x_max = point.X;
                    }
                    else{
                        point.X--;
                        if(point.X < x_min) x_min = point.X;
                    }
                }
            }
            else if(str[i] == 'L'){
                idx = (idx + 1) % 4;
                dir = dirs[idx];
            }
            else if(str[i] == 'R'){
                idx = (idx-1);
                if(idx < 0) idx += 4;
                dir = dirs[idx];
            }
        }
        int width = x_max - x_min;
        int height = y_max - y_min;

        cout << width*height << endl;
    }
    

    return 0;
}