#include <bits/stdc++.h>
#define moduler 1000000000
#define MAX 210
int K, N;
long long dp[MAX][MAX];
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;

    for (int i = 0; i <= N; i++)
    {
        dp[1][i] = 1;
    }

    for (int k = 2; k <= K; k++)
    {
        for (int n = 0; n <= N; n++)
        {
            for (int i = 0; i <= n; i++)
            {
                dp[k][n] = dp[k][n] + dp[k - 1][i];
            }
            dp[k][n] = dp[k][n] % moduler;
        }
    }

    cout << dp[K][N] << "\n";
}