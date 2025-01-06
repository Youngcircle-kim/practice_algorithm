#include <bits/stdc++.h>
using namespace std;
int n, m, e, l, r;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << a[r] - a[l - 1] << "\n";
    }
}