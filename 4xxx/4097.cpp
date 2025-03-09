#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> t;
        if (t == 0)
        {
            return 0;
        }
        vector<long long> v(t+1, 0);
        for (int i = 1; i <= t; i++)
        {
            cin >> v[i];
        }
        vector<long long> dp(t+1, 0);
        long long curMax = -987654321;
        for (int i = 1; i <= t; i++)
        {
            dp[i] = max(dp[i - 1] + v[i], v[i]);
            curMax = max(curMax, dp[i]);
        }
        cout << curMax << "\n";
    }
}
// 사용 알고리즘 : Dynamic Programming
// 접급법 : a_n = max(a_n-1 + b_n, b_n) 점화식을 짜고 그대로 코드로 옮겻다.