#include <bits/stdc++.h>
using namespace std;
int n, e, m, a;
unordered_set<int> s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        s.insert(e);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        int res = 0;
        if (s.find(a) != s.end())
        {
            res = 1;
        }
        cout << res << "\n";
    }
}