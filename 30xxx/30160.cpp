#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long _sum = 0;
    long long _term = 0;
    long long _a = 0;
    long long n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;
        _term += 2 * _a + x;
        _sum += _term;
        _a += x;
        cout << _sum << ' ';
    }
}