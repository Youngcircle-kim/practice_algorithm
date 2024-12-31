#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int abc[55][55][55];

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    if (abc[a][b][c])
    {
        return abc[a][b][c];
    }
    if (a < b && b < c)
    {
        abc[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return abc[a][b][c];
    }

    abc[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return abc[a][b][c];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0;; i++)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            return 0;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
}