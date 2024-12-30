#include <bits/stdc++.h>
using namespace std;
int n, t, e, a[10005];
long long psum[10005];
bool isPrime(int l)
{
    if (l < 2)
    {
        return false;
    }
    if (l == 2 || l == 3)
    {
        return true;
    }
    if (l % 2 == 0 || l % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= l; i += 6)
    {
        if (l % i == 0 || l % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    psum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        // 누적합 배열 생성
        for (int j = 1; j <= t; j++)
        {
            cin >> a[j];
            psum[j] = psum[j - 1] + a[j];
        }
        bool found = 0;
        // 완전탐색으로 부분 수열 탐색
        for (int c = 2; c <= t && !found; c++)
        {
            for (int j = 0; j <= t - c && !found; j++)
            {
                int cur = psum[c + j] - psum[j];
                if (isPrime(cur) && !found)
                {
                    cout << "Shortest primed subsequence is length " << c << ": ";
                    for (int x = j + 1; x <= c + j; x++)
                    {
                        cout << a[x] << " ";
                    }
                    cout << "\n";
                    found = 1;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "This sequence is anti-primed." << "\n";
        }
    }
}