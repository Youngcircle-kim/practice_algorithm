#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;

    cout << a + b - c << "\n";
    cout << stoi(to_string(a) + to_string(b)) - c;
}