#include <bits/stdc++.h>
using namespace std;
int x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    bitset<7> bit(x);
    cout << bit.count();
}