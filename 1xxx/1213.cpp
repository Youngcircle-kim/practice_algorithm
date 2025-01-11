#include <bits/stdc++.h>
using namespace std;
string input, temp, center;
int a[30], cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    for (char c : input)
    {
        a[c - 65]++;
    }

    for (int i = 0; i < 30; i++)
    {
        if (a[i] > 1)
        {
            char c = i + 65;
            for (int j = 0; j < a[i] / 2; j++)
            {
                temp += c;
            }
        }
        if (a[i] % 2 != 0 && cnt < 2)
        {
            center += i + 65;
            cnt++;
        }
        else if (cnt > 1)
        {
            cout << "I'm Sorry Hansoo\n";
            return 0;
        }
    }
    string cp = temp;
    reverse(cp.begin(), cp.end());
    cout << temp << center << cp;
}