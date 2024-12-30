#include <bits/stdc++.h>
using namespace std;
int n, s, cnt = 0;
int a[25];
void dfs(int idx, int sum)
{
    if (idx == n)
    {
        if (sum == s)
            cnt++;
        return;
    }
    // 원소 선택하는 경우
    dfs(idx + 1, sum + a[idx]);
    // 원소 선택하지 않은 경우
    dfs(idx + 1, sum);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0);
    if (s == 0)
    {
        cnt--;
    }
    cout << cnt;
}