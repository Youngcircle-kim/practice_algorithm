#include <bits/stdc++.h>
using namespace std;
int dist[1000002];
int F, S, G, U, D;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist + 1000001, -1);
    // constraints
    // 1 <= S, G <= F <= 1_000_000
    // 0 <= U, D <= 1_000_000
    cin >> F >> S >> G >> U >> D;

    queue<int> Q;
    Q.push(S);
    dist[S] = 0;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int nxt : {cur + U, cur - D})
        {
            if (nxt > F || nxt < 1 || dist[nxt] != -1)
            {
                continue;
            }
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    if (dist[G] == -1)
    {
        cout << "use the stairs";
    }
    else
    {
        cout << dist[G];
    }
}