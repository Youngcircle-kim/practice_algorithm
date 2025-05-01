#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int board[1002][1002];
int viS[1002][1002];
int viF[1002][1002];
int T, w, h;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T; // test case
    while (T--)
    {
        // constraints
        //  1 <= w, h <= 1_000
        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            fill(viF[i], viF[i] + w, 0);
            fill(viS[i], viS[i] + w, 0);
        }

        queue<pair<int, int>> Qs = {}, Qf = {};
        for (int x = 0; x < h; x++)
        {
            for (int y = 0; y < w; y++)
            {
                board[x][y] = 0;
                char c;
                cin >> c;
                if (c == '#')
                {
                    board[x][y] = -1;
                }
                else
                {
                    if (c == '@')
                    {
                        Qs.push({x, y});
                        viS[x][y] = 1;
                    }
                    if (c == '*')
                    {
                        Qf.push({x, y});
                        viF[x][y] = 1;
                    }
                }
            }
        }

        while (!Qf.empty())
        {
            auto cur = Qf.front();
            Qf.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    continue;
                }
                if (board[nx][ny] == -1)
                {
                    continue;
                }
                if (viF[nx][ny])
                {
                    continue;
                }
                viF[nx][ny] = viF[cur.X][cur.Y] + 1;
                Qf.push({nx, ny});
            }
        }
        bool escape = 0;
        while (!Qs.empty() && !escape)
        {
            auto curS = Qs.front();
            Qs.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = curS.X + dx[dir];
                int ny = curS.Y + dy[dir];
                if (nx < 0 || h <= nx || ny < 0 || w <= ny)
                {
                    cout << viS[curS.X][curS.Y] << '\n';
                    escape = true;
                    break;
                }
                if (board[nx][ny] == -1)
                    continue;
                if (viS[nx][ny])
                    continue;
                if (viF[nx][ny] != 0 && viF[nx][ny] <= viS[curS.X][curS.Y] + 1)
                    continue;
                viS[nx][ny] = viS[curS.X][curS.Y] + 1;
                Qs.push({nx, ny});
            }
        }
        if (!escape)
        {
            cout << "IMPOSSIBLE" << "\n";
        }
    }
}