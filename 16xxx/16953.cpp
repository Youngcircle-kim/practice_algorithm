#include <bits/stdc++.h>
using namespace std;
int a, b, cnt = 1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;

    for (int i = 0;; i++)
    {
        if (a == b)
        {
            break;
        }
        else if (a > b)
        {
            cnt = -1;
            break;
        }

        if (b % 2 == 0)
        {
            b /= 2;
        }
        else if (b % 10 == 1)
        {
            b = (b - 1) / 10;
        }
        else
        {
            cnt = -1;
            break;
        }
        cnt++;
    }

    cout << cnt;
}