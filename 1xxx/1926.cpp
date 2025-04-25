#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[501][501] = {
    0,
};
bool vis[501][501] = {
    0,
};
int n, m;                  // n = 행, m = 열
int dx[4] = {1, 0, -1, 0}; // 행의 이동 좌표 오 위 왼 아
int dy[4] = {0, -1, 0, 1}; // 열의 이동 좌표 오 위 왼 아
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // constraints
    // 1 <= n <= 500
    // 1 <= m <= 500
    cin >> n >> m;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            cin >> board[x][y];
        }
    }

    int cnt = 0, curMax = 0; // cnt = 그림의 개수, curMax = 넓이의 최대값
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (vis[x][y] || !board[x][y])
            {
                continue;
            }
            cnt++;
            queue<pair<int, int>> Q;
            vis[x][y] = 1;
            Q.push({x, y});
            int mx = 0;
            while (!Q.empty())
            {
                mx++;
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            curMax = max(mx, curMax);
        }
    }

    cout << cnt << "\n"
         << curMax;
}