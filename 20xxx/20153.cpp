#include <bits/stdc++.h>
using namespace std;
int n, res;
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
        res ^= i;
    }
    int curMax = 0;
    for (const auto &i : v)
    {
        curMax = max(curMax, (res ^ i));
    }
    curMax = max(curMax, res);
    cout << curMax << curMax;
}