// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, j = n - 1;
    int curMin = abs(a[0] + a[1]);
    pair<int, int> p = make_pair(a[0], a[1]);
    while (i < j)
    {
        pair<int, int> p_dump = make_pair(a[i], a[j]);
        int localMin = abs(a[i] + a[j]);

        if (curMin > localMin)
        {
            curMin = localMin;
            p = p_dump;
        }

        if (abs(a[i]) > abs(a[j]))
        {
            i += 1;
        }
        else if (abs(a[i]) < abs(a[j]))
        {
            j -= 1;
        }
        else
        {
            p = p_dump;
            break;
        }
    }
    cout << p.first << " " << p.second;
    return 0;
}