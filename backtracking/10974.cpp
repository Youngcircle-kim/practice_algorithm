#include <bits/stdc++.h>
using namespace std;
int n, a[10];
bool visited[10] = {
    0,
};
void dfs(int cnt)
{
    if (cnt == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            a[cnt] = i;
            dfs(cnt + 1);
            visited[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dfs(0);
}