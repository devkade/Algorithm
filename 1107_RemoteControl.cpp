#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

// 0~100000���� ��ü Ž��
// ���峪�� ���� ��ư���� ���ڸ� ������ �� �ִ��� Ȯ��
// �ּҰ� finding

bool broken[10];

// n�� ������ ��ư���� ���� �� �ִ��� ������ �Ǵ�
bool can_make(int n)
{
    if (n == 0)
        return broken[0] ? false : true;
    while (n != 0)
    {
        if (broken[n % 10] == true)
            return false;
        n /= 10;
    }
    return true;
}

// �ּҰ� ã��
int Min(int a, int b)
{
    if (a < b)
        return a;
    else
    {
        return b;
    }
}

// �ڸ���
int len(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int main()
{
    int target, bNum, temp, initMin, min;
    cin >> target;
    cin >> bNum;
    initMin = abs(target - 100);
    min = 100007;
    // ���峭 ��ư üũ
    for (int i = 0; i < bNum; i++)
    {
        cin >> temp;
        broken[temp] = true;
    }

    // �ּҰ�ã��
    for (int i = 0; i < 1000007; i++)
    {
        if (can_make(i) == true)
        {
            temp = abs(target - i);
            temp += len(i);
            min = Min(min, temp);
        }
    }
    min = Min(initMin, min);
    cout << min << endl;

    return 0;
}