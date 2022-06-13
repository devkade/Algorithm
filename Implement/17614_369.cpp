#include <iostream>

using namespace std;

int num_length(int n);
int count_369(int n);

int main()
{
    int n;
    cin >> n;

    cout << count_369(n) << endl;

    return 0;
}

int num_length(int n)
{
    int count = 0;
    while (true)
    {
        if (n / 10 == 0)
        {
            count++;
            break;
        }
        else
        {
            count++;
            n = n / 10;
        }
    }
    return count;
}

int count_369(int n)
{
    int count = 0, remain, var;

    for (int i = 1; i <= n; i++)
    {
        var = i;
        while (true)
        {
            // 자리수 1자리
            if (num_length(var) == 1)
            {
                if ((var % 3 == 0) || (var % 6 == 0) || (var % 9 == 0))
                {
                    count++;
                }
                break;
            }
            //자리수 여러자리
            else
            {
                remain = var % 10;
                var = var/10;
                if (remain == 0)
                    continue;
                if ((remain % 3 == 0) || (remain % 6 == 0) || (remain % 9 == 0))
                {
                    count++;
                }
            }
        }
    }
    return count;
}