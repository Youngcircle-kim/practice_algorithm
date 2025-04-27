#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int T, M, N, K, x, y;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    // constraints
    // 1<=M<=50 row
    // 1<=N<=50 column
    // 1<=K<=2500 cnt
    while (T--)
    {
        int board[52][52] = {
            0,
        };
        bool vis[52][52] = {
            0,
        };
        cin >> M >> N >> K;
        // 배추가 있는 위치 표시
        while (K--)
        {
            cin >> x >> y;
            board[x][y] = 1;
        }
        int cnt = 0;
        for (int row = 0; row < M; row++)
        {
            for (int col = 0; col < N; col++)
            {
                if (vis[row][col] || !board[row][col])
                {
                    continue;
                }
                cnt++;
                queue<pair<int, int>> Q;
                vis[row][col] = 1;
                Q.push({row, col});
                while (!Q.empty())
                {
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
                        if (vis[nx][ny] || board[nx][ny] != 1)
                        {
                            continue;
                        }
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}