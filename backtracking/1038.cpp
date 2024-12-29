#include <bits/stdc++.h>
using namespace std;
const long long inf = 19876543210;
int n, cnt;
long long ans;
void dfs(long long m, int size)
{
    if (size == 0)
    {
        if (cnt == n)
        {
            ans = m;
        }
        cnt++;
        return;
    }
    int last = m % 10;
    if (m == 0)
    {
        last = 10;
    }
    for (int i = 0; i < last; i++)
    {
        long long next = (m * 10) + i;
        if (m == 0 && i == 0)
        {
            continue;
        }
        dfs(next, size - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cnt = 0;
    ans = -1;
    for (int i = 0; i <= 10; i++)
    {
        dfs(0, i);
    }
    cout << ans;
    return 0;
}