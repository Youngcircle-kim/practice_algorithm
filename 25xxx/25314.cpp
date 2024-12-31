// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int n;
string s = "";
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = n; i != 4; i -= 4)
    {
        s += "long ";
    }
    s += "long int";
    cout << s;

    return 0;
}