#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int a[105][75];
bool vis[105][75];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 105; i++){ 
        fill(a[i], a[i]+75, -1);
        fill(vis[i], vis[i] +75, 0);
    }
    
    cin >> n >> m;
    for(int x = 0;x < n; x++){
        for(int y = 0; y < m;y++){
            cin >> a[x][y];
        }
    }
    
    int cnt = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(!vis[x][y] && a[x][y]){
                queue<pair<int, int>> q;
                q.push({x,y});
                vis[x][y] = 1;
                bool is = 1;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int dir = 0; dir < 8; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                        if(a[x][y] < a[nx][ny]) is = 0; 
                        
                        if(!vis[nx][ny] && a[x][y] == a[nx][ny]){
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
                if(is) cnt++;
            }   
        }
    }
    cout << cnt;
}
