#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005];
long long psum[10005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    a[0] = 0;
    psum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (psum[j] - psum[i] == m)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}