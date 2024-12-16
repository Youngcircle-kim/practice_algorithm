#include <bits/stdc++.h>
using namespace std;
int n, sol = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == 0)
    {
        cout << 1;
        return 0;
    }
    for (int i = 31; i >= 0 && !sol; i--)
    {
        if ((n >> i) & 1)
        {
            sol = i + 1;
        }
    }
    cout << sol;
}