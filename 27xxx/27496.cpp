#include <bits/stdc++.h>
using namespace std;
int n, l, cnt = 0;
long long sum;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        if (i >= l)
        {
            sum -= v[i - l];
        }
        if (129 <= sum && sum <= 138)
        {
            cnt++;
        }
    }
    cout << cnt;
}