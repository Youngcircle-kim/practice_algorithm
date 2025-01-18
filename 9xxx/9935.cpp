#include <bits/stdc++.h>
using namespace std;
string s, des_s, res;
stack<char> st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> des_s;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);

        if (s[i] == des_s[des_s.length() - 1] && st.size() >= des_s.length())
        {
            string dum;
            for (int j = 0; j < des_s.length(); j++)
            {
                dum.push_back(st.top());
                st.pop();
            }

            reverse(dum.begin(), dum.end());

            if (dum.compare(des_s) != 0)
            {
                for (int k = 0; k < dum.length(); k++)
                {
                    st.push(dum[k]);
                }
            }
        }
    }

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());
    if (res.empty())
    {
        cout << "FRULA";
        return 0;
    }
    cout << res;
    return 0;
}