#include <bits/stdc++.h>
using namespace std;
int x, idx = 0, sol;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x;
    for (int i = 1;; i++)
    {
        if (idx + i >= x)
        {
            x -= idx;
            idx = i + 1;
            break;
        }
        idx += i;
    }

    sol = -x + idx;

    if (idx % 2 != 0)
    {
        cout << idx - sol << '/' << sol;
        return 0;
    }
    cout << sol << '/' << idx - sol;
}