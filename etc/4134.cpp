#include <bits/stdc++.h>
using namespace std;
int x;
long long n;
bool isPrime(long long n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (long long i = 5; i * i <= n; i++)
    {
        if (n % i == 0)
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

    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> n;

        while (!isPrime(n))
        {
            n++;
        }
        cout << n << '\n';
    }
}