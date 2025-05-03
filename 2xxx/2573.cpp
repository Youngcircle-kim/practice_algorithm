#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N, M;
int mat[302][302];
bool vis[302][302];
int desc[302][302];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            cin >> mat[x][y];
        }
    }

    bool hasIce = false;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (mat[x][y] != 0)
            {
                hasIce = true;
            }
        }
    }
    if (!hasIce)
    {
        cout << 0;
        return 0;
    }

    queue<pair<int, int>> Q;
    int cntYear = 0;
    while (1)
    {
        int cntG = 0;
        ++cntYear;

        for (int i = 0; i < N; i++)
        {
            fill(desc[i], desc[i] + M, 0);
            fill(vis[i], vis[i] + M, 0);
        }

        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < M; y++)
            {
                if (mat[x][y] == 0 || vis[x][y])
                    continue;

                Q.push({x, y});
                vis[x][y] = 1;

                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;

                        if (vis[nx][ny])
                            continue;

                        if (mat[nx][ny] == 0)
                        {
                            desc[cur.X][cur.Y]++;
                            continue;
                        }

                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }

                cntG++;
                if (cntG >= 2)
                {
                    cout << cntYear - 1;
                    return 0;
                }
            }
        }

        if (cntG == 0)
        {
            cout << 0;
            return 0;
        }

        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < M; y++)
            {
                mat[x][y] -= desc[x][y];
                if (mat[x][y] < 0)
                    mat[x][y] = 0;
            }
        }
    }
}