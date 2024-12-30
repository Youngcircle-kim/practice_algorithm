#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
int sequence[10];
bool visited[10];
void dfs(int cnt, int k)
{
    if (cnt == m)
    {
        for (int i = 0; i < cnt; i++)
        {
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = k; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            sequence[cnt] = i;
            dfs(cnt + 1, i);
            visited[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dfs(0, 1);
}