#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int board[102][102] = {
    0,
};
bool vis[102][102] = {
    0,
};
int M, N, K, lx, ly, rx, ry;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // constraints
    // 1<= M <=100
    // 1<= N <=100
    // 1<= K <=100
    cin >> M >> N >> K;
    while (K--)
    {
        cin >> lx >> ly >> rx >> ry;
        for (int i = ly; i < ry; i++)
        {
            for (int j = lx; j < rx; j++)
            {
                board[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    vector<int> sizes = {};
    for (int x = 0; x < M; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (vis[x][y] || board[x][y] != 0)
            {
                continue;
            }
            cnt++;
            int sz = 0;
            queue<pair<int, int>> Q;

            vis[x][y] = 1;
            Q.push({x, y});
            while (!Q.empty())
            {
                sz++;
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                    {
                        continue;
                    }
                    if (vis[nx][ny] || board[nx][ny] > 0)
                    {
                        continue;
                    }
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            sizes.push_back(sz);
        }
    }
    cout << cnt << "\n";
    sort(sizes.begin(), sizes.end());
    for (int i = 0; i < cnt; i++)
    {
        cout << sizes[i] << " ";
    }
}