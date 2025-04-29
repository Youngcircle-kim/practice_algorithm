#include <bits/stdc++.h>
using namespace std;
int board[102][102][102] = {
    -1,
};
int dx[6] = {0, -1, 0, 1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int M, N, H;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // constraints
    // 2 <= M <= 100 column
    // 2 <= N <= 100 row
    // 1 <= H <= 100 height
    cin >> M >> N >> H;
    queue<tuple<int, int, int>> Q; // 3차원이라 tuple 사용
    for (int z = 0; z < H; z++)
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < M; y++)
            {
                cin >> board[x][y][z];
                if (board[x][y][z] == 1)
                {
                    Q.push({x, y, z}); // 시작점이 여러개라 여기서 push
                }
            }
        }
    }
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            // next 좌표들
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
            {
                continue;
            }
            if (board[nx][ny][nz] != 0)
            {
                continue;
            }
            Q.push({nx, ny, nz});
            board[nx][ny][nz] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
    }
    int mx = 1;
    for (int z = 0; z < H; z++)
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < M; y++)
            {
                if (board[x][y][z] == 0)
                {
                    cout << -1;
                    return 0;
                }
                mx = max(board[x][y][z], mx);
            }
        }
    }
    cout << mx - 1;
}