#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], i, j, psum[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    psum[0] = 0;
    for (int k = 1; k <= n; k++)
    {
        cin >> a[k];
        psum[k] = psum[k - 1] + a[k];
    }
    cin >> m;
    for (int k = 1; k <= m; k++)
    {
        cin >> i >> j;
        cout << psum[j] - psum[i - 1] << "\n";
    }
}