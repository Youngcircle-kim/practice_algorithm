#include <bits/stdc++.h>
using namespace std;
int N, L, t;
int sum(int n)
{
    return n * (n + 1) / 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    for (int i = L; i <= 100; i++)
    {
        int x = sum(i-1);
        if ((N - x) / i >= 0 && (N - x) % i == 0)
        {
            t = (N - x) / i;
            for (int j = t; j < t + i; j++)
            {
                cout << j << " ";
            }
            cout << "\n";
            return 0;
        }
    }

    cout << -1;
}