#include <bits/stdc++.h>
using namespace std;
int n, s;
int a[100005];
long long psum[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    psum[0] = 0;
    // array init
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    // two pointer algorithm
    int cnt = n + 1;
    int end = 1;
    for (int start = 1; start <= n; start++)
    {
        while (psum[end] - psum[start - 1] < s && end <= n)
        {
            end++;
        }
        if (cnt > end - start && psum[end] - psum[start - 1] >= s)
        {
            cnt = end - start + 1;
        }
    }
    if (cnt == n + 1)
    {
        cnt = 0;
    }
    cout << cnt;
}