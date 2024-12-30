#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[10];

void dfs(int cnt, int prev)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << s[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (prev <= i)
        {
            s[cnt] = i;
            dfs(cnt + 1, i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dfs(0, 0);
}