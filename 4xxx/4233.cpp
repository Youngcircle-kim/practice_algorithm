#include <bits/stdc++.h>
using namespace std;
int a, p;
bool isPrime(int p)
{
    if (p <= 1)
    {
        return 0;
    }
    if (p == 2 || p == 3)
    {
        return 1;
    }
    if (p % 2 == 0 || p % 3 == 0)
    {
        return 0;
    }
    for (int i = 5; i * i <= p; i += 6)
    {
        if (p % i == 0 || p % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // problem
    // p가 소수일 떼, a^p == a (mod p)가 성립
    // 가짜 소수 : a^p = a(mod p) 성립. but, p가 소수는 아님.

    // constraints
    // * 2 < p <= 1,000,000,000
    // * 1 < a < p
    while (true)
    {
        cin >> p >> a;

        if (p == 0 && a == 0)
        {
            break;
        }
        if (isPrime(p))
        {
            cout << "no" << "\n";
            continue;
        }
        long long curRes = 1;
        long long exp = p;
        long long base = a;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                curRes = (curRes * base) % p;
            }
            base = (base * base) % p;
            exp /= 2;
        }
        // cout << curRes % p << " " << p << isPrime(p) << " " << "\n";
        if (curRes == a && !isPrime(p))
        {
            cout << "yes" << "\n";
            continue;
        }
        cout << "no" << "\n";
    }
    return 0;
}