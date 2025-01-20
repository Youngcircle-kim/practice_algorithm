#include <bits/stdc++.h>
using namespace std;
int n, m;
int v[10];
int seq[10];
bool visited[10] = {
    0,
};
void dfs(int idx, int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    else
    {
        int temp = 0;
        for (int i = idx; i < n; i++)
        {
            if (temp != v[i])
            {
                seq[depth] = v[i];
                temp = v[i];
                dfs(i, depth + 1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v, v + n);
    dfs(0, 0);
    return 0;
}