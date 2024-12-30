#include <bits/stdc++.h>
using namespace std;
int N;
int t;
void dfs(int sum, int sign, int num, int n, string str)
{
    if (n == t)
    {
        sum += (num * sign);
        if (sum == 0)
        {
            cout << str << '\n';
        }
    }
    else
    {
        dfs(sum, sign, num * 10 + (n + 1), n + 1, str + ' ' + char(n + 1 + '0'));
        dfs(sum + (sign * num), 1, n + 1, n + 1, str + '+' + char(n + 1 + '0'));
        dfs(sum + (sign * num), -1, n + 1, n + 1, str + '-' + char(n + 1 + '0'));
    }
}
// 수식의 경우의 수 3개 최대 3^10이다. 완전탐색으로 풀 수 있을거 같다.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        dfs(0, 1, 1, 1, "1");
        cout << "\n";
    }
}