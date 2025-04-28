#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[302][302];

int T, l, ix, iy, gx, gy;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T; // test case
    while (T--)
    {
        // constraints
        // 4 <= l <= 300
        cin >> l;
        for (int i = 0; i < l; i++)
        {
            fill(board[i], board[i] + l, -1);
        }

        cin >> ix >> iy;
        cin >> gx >> gy;
        queue<pair<int, int>> Q;
        board[ix][iy] = 0;
        Q.push({ix, iy});
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 8; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];

                if (nx >= l || nx < 0 || ny < 0 || ny >= l)
                {
                    continue;
                }
                if (board[nx][ny] >= 0)
                {
                    continue;
                }

                board[nx][ny] = board[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << board[gx][gy] << "\n";
    }
}