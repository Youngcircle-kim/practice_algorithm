#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    cin >> b;
    cin >> c;
    int dist = abs(a) + abs(b);
    int f = c - dist;

    if (f >= 0 && f % 2 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}