#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

// 0~100000까지 전체 탐색
// 고장나지 않은 버튼으로 숫자를 조합할 수 있는지 확인
// 최소값 finding

bool broken[10];

// n을 리모컨 버튼으로 만들 수 있는지 없는지 판단
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

// 최소값 찾기
int Min(int a, int b)
{
    if (a < b)
        return a;
    else
    {
        return b;
    }
}

// 자리수
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
    // 고장난 버튼 체크
    for (int i = 0; i < bNum; i++)
    {
        cin >> temp;
        broken[temp] = true;
    }

    // 최소값찾기
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