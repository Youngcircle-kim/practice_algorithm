// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int n, g;

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
    cin >> g;
    int cnt = 0;
    sort(a, a + n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] == g)
        {
            cnt++;
            i += 1;
        }
        else if (a[i] + a[j] > g)
        {
            j -= 1;
        }
        else if (a[i] + a[j] < g)
        {
            i += 1;
        }
    }
    cout << cnt;
    return 0;
}