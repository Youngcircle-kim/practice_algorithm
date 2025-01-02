#include <bits/stdc++.h>
using namespace std;
int n, m;
string e;
unordered_set<string> s;
vector<string> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        s.insert(e);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> e;
        if (s.find(e) != s.end())
        {
            v.push_back(e);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto s : v)
    {
        cout << s << "\n";
    }
}