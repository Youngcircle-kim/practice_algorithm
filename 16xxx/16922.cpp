#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
int a[4] = {1, 5, 10, 50};
bool visited[1005];
void dfs(int depth, int idx, int total)
{
    if (depth == n)
    {
        if (!visited[total])
        {
            visited[total] = true;
            cnt++;
        }
        return;
    }
    for (int i = idx; i < 4; i++)
    {
        dfs(depth + 1, i, total + a[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    dfs(0, 0, 0);

    cout << cnt;
}
// 중복조합을 이용한 풀이(백트래킹) 문제이다.