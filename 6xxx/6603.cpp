#include <bits/stdc++.h>
using namespace std;
int k, e;
vector<int> v(15);
vector<int> seq(8);
int visited[55];
void dfs(int cnt, int idx)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = idx; i < k; i++)
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

    for (int i = 0;; i++)
    {
        cin >> k;
        if (k == 0)
        {
            return 0;
        }
        for (int j = 0; j < k; j++)
        {
            cin >> v[j];
        }
        dfs(0, 0);
        cout << "\n";
    }
}