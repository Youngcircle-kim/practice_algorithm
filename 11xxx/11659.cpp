#include <bits/stdc++.h>

using namespace std;
int N, M, i, j, k, res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    int a[N + 1];
    a[0] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> k;

        a[i] = k + a[i - 1];
    }

    for (int p = 0; p < M; p++)
    {
        cin >> i >> j;
        res = 0;
        if (i == j)
        {
            cout << a[i] - a[i - 1] << "\n";
            continue;
        }
        res = a[j] - a[i - 1];

        cout << res << "\n";
    }
}
