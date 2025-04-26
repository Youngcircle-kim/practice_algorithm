#include <bits/stdc++.h>
using namespace std;
int n, k;
int dist[200002];
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(dist, dist + 200000, -1);
    // constraints
    // 0 <= n <= 100_000
    // 0 <= k <= 100_000
    cin >> n >> k;

    dist[n] = 0;
    deque<int> Q;
    Q.push_back(n);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop_front();
        // 1초 후는 x-1 , x+1
        // 0초 후는 2*x, x
        if (2 * cur < 200000 && dist[2 * cur] == -1)
        {
            dist[2 * cur] = dist[cur];
            Q.push_front(2 * cur);
        }
        for (int nxt : {cur - 1, cur + 1})
        {
            if (nxt < 0 || nxt >= 200000)
            {
                continue;
            }
            if (dist[nxt] != -1)
            {
                continue;
            }
            dist[nxt] = dist[cur] + 1;
            Q.push_back(nxt);
        }
    }
    cout << dist[k];
}