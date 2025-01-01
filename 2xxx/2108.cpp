#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    long long sum = 0;
    int cnt[8001] = {0};

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
        cnt[v[i] + 4000]++;
    }

    double mean_double = (double)sum / n;
    int mean = round(mean_double);

    sort(v.begin(), v.end());
    int median = v[n / 2];

    int curMax = 0;
    for (int i = 0; i <= 8000; ++i)
    {
        if (cnt[i] > curMax)
        {
            curMax = cnt[i];
        }
    }

    vector<int> modes;
    for (int i = 0; i <= 8000; ++i)
    {
        if (cnt[i] == curMax)
        {
            modes.push_back(i - 4000);
        }
    }

    int mode;
    if (modes.size() == 1)
    {
        mode = modes[0];
    }
    else
    {
        sort(modes.begin(), modes.end());
        mode = modes[1];
    }

    int range_val = v[n - 1] - v[0];

    cout << mean << "\n";
    cout << median << "\n";
    cout << mode << "\n";
    cout << range_val << "\n";

    return 0;
}