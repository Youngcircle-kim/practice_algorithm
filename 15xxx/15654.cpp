#include <bits/stdc++.h>
using namespace std;
int n, m, e;
vector<int> v;
vector<int> seq(8);
bool visited[10003];

void dfs(int cnt, int idx)
{
    if (cnt == m)
    {
        for (int i = 0; i < cnt; i++)
        {
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[v[i]])
        {
            visited[v[i]] = 1;
            seq[cnt] = v[i];
            dfs(cnt + 1, i);
            visited[v[i]] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        v.push_back(e);
    }
    sort(v.begin(), v.end());

    dfs(0, 1);
}