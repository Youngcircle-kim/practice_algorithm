#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int gcd(int m, int n)
{
    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    cin >> c >> d;

    int numerator = a * d + c * b;
    int denominator = b * d;
    int cd = gcd(numerator, denominator);
    cout << numerator / cd << " " << denominator / cd;
}