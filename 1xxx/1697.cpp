#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dist[100002];
int n, k;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist + 100001, -1);
    // constraints
    // 0 <= N <= 100_000
    // 0 <= K <= 100_000
    cin >> n >> k;
    dist[n] = 0;
    queue<int> Q;
    Q.push(n);
    while (dist[k] == -1)
    {
        int cur = Q.front();
        Q.pop();
        for (int nxt : {cur - 1, cur + 1, 2 * cur})
        {
            if (nxt < 0 || nxt > 100000)
            {
                continue;
            }
            if (dist[nxt] != -1)
            {
                continue;
            }
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << dist[k];
}