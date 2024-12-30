#include <bits/stdc++.h>
using namespace std;
long long N, P, Q;
unordered_map<long long, long long> m;
long long a(long long n)
{
    if (m.find(n) != m.end())
    {
        return m[n];
    }
    m[n] = a(n / P) + a(n / Q);
    return m[n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> N >> P >> Q;
    m[0] = 1;

    cout << a(N);
}
