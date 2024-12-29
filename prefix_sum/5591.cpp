#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005], psum[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    psum[0] = 0;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    int max = 0;
    for (int i = k + 1; i <= n; i++)
    {
        int curMax = psum[i] - psum[i - k];
        if (max < curMax)
        {
            max = curMax;
        }
    }
    cout << max;
}