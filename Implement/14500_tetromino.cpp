#include <iostream>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int n, m, board[505][505] = {};
int blocks[19][4][2] = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, // ㅡ
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, // ㅣ
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}}, // ㅁ
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {0, 1}, {0, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {2, -1}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    {{0, 0}, {1, 0}, {1, -1}, {2, -1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {0, 2}},
    {{0, 0}, {0, 1}, {-1, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
};

void Input(){
    cin >> n >> m;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cin >> board[row][col];
        }
    }
}

bool is_inside(int row, int col){
    if (row < 0 || row >= n || col < 0 || col >= m) return false;
    return true;
}

int tetromino(){
    int max = 0;
    
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            int temp = 0;
            for(int i = 0; i < 19; i++){
                if (!is_inside(row+blocks[i][2][0], col+blocks[i][2][1]) || !is_inside(row+blocks[i][3][0], col+blocks[i][3][1])) continue;
                temp = board[row+blocks[i][0][0]][col+blocks[i][0][1]] + board[row+blocks[i][1][0]][col+blocks[i][1][1]] + \
                        board[row+blocks[i][2][0]][col+blocks[i][2][1]] + board[row+blocks[i][3][0]][col+blocks[i][3][1]];
                if (temp > max) max = temp;
            }
        }
    }
    return max;
}

void Solution(){
    int max;
    max = tetromino();
    cout << max << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solution();

    return 0;
}