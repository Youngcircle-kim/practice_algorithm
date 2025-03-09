#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    if (n <= 2)
    {
        cout << dp[n];
        return 0;
    }
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    cout << dp[n];
    return 0;
}
// 사용 알고리즘 : Dynamic Programming
// 접급법 : N = 1부터 4까지 관찰한 결과 a_n = a_n-1 + a_n-2라는 점화식을 귀납적으로 추론할 수 있다.
// 추론한 점화식을 N=5에 작접 적용해 테스트를 했고, N=5에도 규칙이 적용되어 그대로 코드로 옮겨적었다.