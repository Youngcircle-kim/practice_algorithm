#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, a, b;
int g[300003];
vector<int> v[300003];
void dijkstra(int s)
{
    g[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (g[next] > g[cur] + 1)
            {
                g[next] = g[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> x;
    for (int i = 1; i <= n; i++)
    {
        g[i] = 1286608618;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
    }
    dijkstra(x);
    bool check = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g[i] == k)
        {
            check = true;
            cout << i << "\n";
        }
    }
    if (!check)
    {
        cout << -1;
    }
}