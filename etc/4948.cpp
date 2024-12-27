#include <bits/stdc++.h>
using namespace std;
int n, cnt;
bool isPrime(int i)
{
    if (i == 1 || i < 0)
    {
        return false;
    }
    if (i == 2 || i == 3)
    {
        return true;
    }
    if (i % 2 == 0 || i % 3 == 0)
    {
        return false;
    }
    for (int j = 5; j * j <= i; j += 6)
    {
        if (i % j == 0 || i % (j + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int k = 0;; k++)
    {
        cin >> n;
        cnt = 0;
        if (n == 0)
        {
            return 0;
        }
        for (int l = n + 1; l <= 2 * n; l++)
        {
            if (isPrime(l))
            {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}