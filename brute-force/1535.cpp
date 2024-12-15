#include <bits/stdc++.h>
using namespace std;
int N;
int a[2][25];
// 입력값의 최대가 20이다. 경우의 수를 아무리 따져도 100만에 못 미칠거 같아 완전탐색으로 풀 수 있을거 같다.
int mx = 0;
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
// 이중 for문은 element control이 2개라 제한적. 백트래킹 사용으로 해결.
void dfs(int idx, int l, int s, int N)
{
    if (idx == N)
    {
        mx = max(mx, s);
        return;
    }

    dfs(idx + 1, l, s, N);
    if (l - a[0][idx] > 0)
    {
        dfs(idx + 1, l - a[0][idx], s + a[1][idx], N);
    }
}
int main()
{
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(0, 100, 0, N);
    cout << mx;
}