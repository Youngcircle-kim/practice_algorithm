#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    __int128 ab = (__int128)a * b;
    long long integer_part = ab / c;
    __int128 rem = ab % c;

    long long fractional_part = (rem * 1000000 + c / 2) / c;

    if (fractional_part == 1000000)
    {
        integer_part += 1;
        fractional_part = 0;
    }

    cout << integer_part << '.' << setfill('0') << setw(6) << fractional_part;
}