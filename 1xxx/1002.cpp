#include <bits/stdc++.h>
using namespace std;
int t, x_1, y_1, r_1, x_2, y_2, r_2, res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;

        int dx = pow(x_2 - x_1, 2);
        int dy = pow(y_2 - y_1, 2);
        int dist = dx + dy;
        int dr = pow(r_2 - r_1, 2);
        int _r = pow(r_2 + r_1, 2);

        if (dist == 0)
        {
            if (dr == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (dist == dr || dist == _r)
        {
            cout << 1 << "\n";
        }
        else if (dr < dist && dist < _r)
        {
            cout << 2 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }

    return 0;
}