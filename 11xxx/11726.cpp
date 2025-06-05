#include <bits/stdc++.h>
using namespace std;
int k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    int dp[k + 4];
    fill(&dp[0], &dp[k + 4], 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= k; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] = dp[i] % 10007;
    }

    cout << dp[k];
}
