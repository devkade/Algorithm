#include <iostream>

using namespace std;

int cab[50][50];
bool is_checked[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int x, int y)
{
    is_checked[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if (0 <= nX && nX <= 50 && 0 <= nY && nY <= 50)
        {
            if (cab[nX][nY] == 1 && is_checked[nX][nY] == false)
                dfs(nX, nY);
        }
    }
}

int main()
{
    int T, width, height, point, x, y;

    cin >> T;
    
    for (int k = 0; k < T; k++)
    {
        int cnt = 0;
        cin >> width >> height >> point;
        for (int i = 0; i < point; i++)
        {
            cin >> x >> y;
            cab[x][y] = 1;
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (cab[i][j] == 1 && is_checked[i][j] == false)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}