#include <bits/stdc++.h>
using namespace std;
string s;
int cnt = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[i + 1])
        {
            cnt++;
        }
    }
    cout << cnt / 2;
}