#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int bitmask = 0;
    string command;
    int x;

    while (n--)
    {
        cin >> command;
        if (command == "add")
        {
            cin >> x;
            bitmask |= (1 << x);
        }
        else if (command == "remove")
        {
            cin >> x;
            bitmask &= ~(1 << x);
        }
        else if (command == "check")
        {
            cin >> x;
            cout << ((bitmask & (1 << x)) ? 1 : 0) << "\n";
        }
        else if (command == "toggle")
        {
            cin >> x;
            bitmask ^= (1 << x);
        }
        else if (command == "all")
        {
            bitmask = (1 << 21) - 1; 
        }
        else if (command == "empty")
        {
            bitmask = 0;
        }
    }

    return 0;
}