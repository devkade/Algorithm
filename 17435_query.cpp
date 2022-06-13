#include <iostream>

using namespace std;
// �ð��ʰ� �߻� -> dp -> �����ϱ� ���� -> 2���� �迭?
int q[200001];
int f[200001];

int query(int n, int x)
{
    if(n == 1)
        return f[x-1];
    else
    {
        return query(f, n-1, x);
    }
}

int main()
{
    int m, temp, q, n, x;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        f[i] = temp;
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n >> x;
        cout << query(n, x) << endl;
    }
    
    delete[] f;
    return 0;  
}