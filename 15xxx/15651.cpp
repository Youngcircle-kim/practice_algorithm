#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10] = {
    0,
};
void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < cnt; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        a[cnt] = i;
        dfs(cnt + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dfs(0);
}