#include <bits/stdc++.h>
using namespace std;
int n, x, a[250005];
long long psum[250005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    psum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    long long curMax = psum[x] - psum[0];
    int cnt = 1;
    for (int i = 1 + x; i <= n; i++)
    {
        long long curPsum = psum[i] - psum[i - x];
        if (curMax == curPsum)
        {
            ++cnt;
        }
        if (curMax < curPsum)
        {
            curMax = curPsum;
            cnt = 1;
        }
    }
    if (curMax == 0)
    {
        cout << "SAD";
        return 0;
    }
    cout << curMax << "\n"
         << cnt;
}