#include <bits/stdc++.h>
using namespace std;
int n, m;
int v[10];
int seq[10];
bool visited[10] = {
    0,
};
void dfs(int depth)
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
        // temp 변수를 사용해 같은 Level에서 사용된 숫자인지 체크
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && temp != v[i])
            {
                seq[depth] = v[i];
                temp = v[i];
                visited[i] = 1;
                dfs(depth + 1);
                visited[i] = 0;
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
    dfs(0);
    return 0;
}