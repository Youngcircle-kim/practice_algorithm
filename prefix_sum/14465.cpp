#include <bits/stdc++.h>
using namespace std;
int n, k, b, m;
int a[100005];
long long psum[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> b;
    fill(a, a + 100005, 1);
    psum[0] = 0;
    a[0] = 0;
    for (int i = 1; i <= b; i++)
    {
        cin >> m;
        a[m] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + a[i];
    }
    long long curMin = n;
    for (int i = k; i <= n; i++)
    {
        long long curPsum = psum[i] - psum[i - k];
        if (k - curPsum < curMin)
        {
            curMin = k - curPsum;
        }
    }
    cout << curMin;
}
