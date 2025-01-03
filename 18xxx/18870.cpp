#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        v.push_back(e);
    }
    vector<int> res(v);

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    for (auto i : v)
    {
        auto e = lower_bound(res.begin(), res.end(), i);
        cout << distance(res.begin(), e) << " ";
    }
}