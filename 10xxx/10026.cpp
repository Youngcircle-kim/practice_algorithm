#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[102][102];
bool vis[102][102] = {
    0,
};
int N;
char color;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
void bfs(int x, int y)
{
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = 1;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            {
                continue;
            }
            if (vis[nx][ny] || board[x][y] != board[nx][ny])
            {
                continue;
            }
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // constraints
    // 1 <= N <= 100
    cin >> N;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> color;
            board[x][y] = color == 'R' ? 1 : color == 'G' ? 2
                                                          : 3;
        }
    }
    int fc = 0, sc = 0; // fc는 일반인 cnt, sc는 적록 색맹 cnt
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (!vis[x][y])
            {
                fc++;
                bfs(x, y);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        fill(vis[i], vis[i] + N, 0);
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (board[x][y] == 2)
            {
                board[x][y] = 1;
            }
        }
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (!vis[x][y])
            {
                sc++;
                bfs(x, y);
            }
        }
    }
    cout << fc << " " << sc;
}